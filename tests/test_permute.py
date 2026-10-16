"""The mechanical search must preserve identifiers that are legal in C."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import permute


class ParserSourceTests(unittest.TestCase):
    def test_c_member_named_class_survives(self):
        source = "struct Number { int class; };\nint get(struct Number *p) { return p->class; }\n"
        result = permute.parser_source(source, "c")
        self.assertIn("int class;", result)
        self.assertIn("p->class", result)
        self.assertEqual(result, source)

    def test_cpp_class_and_linkage_are_adapted(self):
        result = permute.parser_source('class Number { int value; };\n'
                                       'extern "C" int get(Number *p);\n', "cpp")
        self.assertIn("struct Number", result)
        self.assertNotIn('extern "C"', result)
        self.assertIn("extern int get(Number *p);", result)

    def test_c_conditional_linkage_and_brace_literals_are_untouched(self):
        source = ('#ifdef __cplusplus\nextern "C" {\n#endif\n'
                  'enum Kind { A, B };\nchar opening = \'{\';\n'
                  '#ifdef __cplusplus\n}\n#endif\n')
        self.assertEqual(permute.parser_source(source, "c"), source)

    def test_cpp_linkage_removes_its_matching_brace(self):
        source = ('extern "C" { int first() { return 1; } }\n'
                  'int second() { return 2; }\n')
        result = permute.parser_source(source, "cpp")
        self.assertIn("int first() { return 1; }", result)
        self.assertIn("int second() { return 2; }", result)
        self.assertEqual(result.count("{"), result.count("}"))

    def test_cpp_literals_and_comments_keep_the_word_class(self):
        result = permute.parser_source('class Number { int x; };\n'
                                       'const char *s = "class {"; // class {\n', "cpp")
        self.assertIn('"class {"', result)
        self.assertIn('// class {', result)
        self.assertIn('struct Number', result)


class ContextPreservationTests(unittest.TestCase):
    def test_real_neighbor_bodies_are_restored(self):
        import permute_context
        original = ("struct S { int value; };\n"
                    "int before(int x) { return x + 1; }\n"
                    "int target(int x) { return before(x); }\n"
                    "int after(int x) { return x - 1; }\n")
        candidate = ("int before(int x);\n"
                     "int target(int changed) { return before(changed + 2); }\n"
                     "int after(int x);\n")
        result = permute_context.restore(original, candidate, "target")
        self.assertIn("int before(int x) { return x + 1; }", result)
        self.assertIn("int after(int x) { return x - 1; }", result)
        self.assertIn("int target(int changed) { return before(changed + 2); }", result)
        self.assertIn("struct S { int value; };", result)
        self.assertNotIn("return before(x);", result)

    def test_braces_inside_comments_and_strings_do_not_end_a_body(self):
        import permute_context
        original = ('int target(int x) { /* } */ return x; }\n'
                    'int tail(void) { return 3; }\n')
        candidate = 'int target(int x) { char *s = "}"; return x + s[0]; }\n'
        result = permute_context.restore(original, candidate, "target")
        self.assertIn('char *s = "}";', result)
        self.assertIn('int tail(void) { return 3; }', result)

    def test_missing_or_duplicate_target_is_rejected(self):
        import permute_context
        for source in ("int other(void) { return 1; }\n",
                       "int target(void) { return 1; }\nint target(void) { return 2; }\n"):
            with self.subTest(source=source), self.assertRaises(ValueError):
                permute_context.function_span(source, "target")

    def test_notices_and_licence_markers_survive_once(self):
        notice = "/* Copyright Example. Permission to copy is granted. */"
        source = "/* compiler: X */\n/* licence: MIT */\n" + notice + "\n" + notice
        result = permute.source_notices(source)
        self.assertEqual(result.count(notice), 1)
        self.assertIn("/* licence: MIT */", result)
        self.assertNotIn("compiler:", result)


class ContextScoringTests(unittest.TestCase):
    def test_function_is_selected_and_rebased_without_changing_instructions(self):
        from unittest.mock import patch
        import permute_objdump
        with patch.object(permute_objdump.match, "read_object", return_value=(b"", {},
                          [("before", 0, 16), ("target", 16, 32)])):
            command = permute_objdump.command("unit.o", "target", "r5900")
        self.assertIn("--disassemble=target", command)
        self.assertIn(f"--adjust-vma={permute_objdump.BASE - 16}", command)
        self.assertEqual(command[-1], "unit.o")

    def test_missing_function_cannot_score_as_an_empty_object(self):
        from unittest.mock import patch
        import permute_objdump
        with patch.object(permute_objdump.match, "read_object", return_value=(b"", {}, [])):
            with self.assertRaises(ValueError):
                permute_objdump.command("unit.o", "missing", "r5900")


class LinuxLauncherTests(unittest.TestCase):
    def test_linux_interpreter_does_not_depend_on_host_executable(self):
        import shlex
        command = permute.linux_python_command("/path with spaces/helper.py", "--name", "target")
        parts = shlex.split(command)
        self.assertEqual(parts[:2], ["bash", "-c"])
        self.assertIn('exec "$p" "$@"', parts[2])
        self.assertEqual(parts[4:], ["/path with spaces/helper.py", "--name", "target"])

    @unittest.skipIf(sys.platform == "win32", "helper executes inside Linux/WSL")
    def test_launcher_executes_spaced_paths_and_arguments(self):
        import json
        import shlex
        import subprocess
        import tempfile
        with tempfile.TemporaryDirectory(prefix="permuter helper ") as directory:
            script = Path(directory) / "helper script.py"
            script.write_text("import json,sys; print(json.dumps(sys.argv[1:]))\n")
            args = ["two words", "$literal", "semi;colon"]
            result = subprocess.run(shlex.split(permute.linux_python_command(str(script), *args)),
                                    capture_output=True, text=True, check=True)
        self.assertEqual(json.loads(result.stdout), args)

    def test_scoring_command_survives_toml_quoting(self):
        import json
        import tomllib
        command = permute.linux_python_command("/path with spaces/helper.py", "--function", "target")
        settings = "objdump_command = " + json.dumps(command) + "\n"
        self.assertEqual(tomllib.loads(settings)["objdump_command"], command)


if __name__ == "__main__":
    unittest.main()
