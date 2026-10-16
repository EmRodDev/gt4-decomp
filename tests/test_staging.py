"""Public-source staging and the alternate-assembler command boundary."""
import shutil
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import stage_gcc_runtime
import stage_libmatch


class PublicStagingTests(unittest.TestCase):
    def test_preprocessor_preserves_flags_and_quoted_paths(self):
        command = stage_libmatch.preprocess_command(
            '"/path with spaces/ee-gcc" -c -O2 -G0 -fno-exceptions -Iinclude')
        self.assertEqual(command, ["/path with spaces/ee-gcc", "-E", "-C",
                                   "-O2", "-G0", "-fno-exceptions", "-Iinclude"])

    def test_wrapped_or_non_compile_commands_are_rejected(self):
        for command in ('bash tools/cc_as.sh as "gcc"', 'ee-gcc -E unit.c'):
            with self.subTest(command=command), self.assertRaises(ValueError):
                stage_libmatch.preprocess_command(command)

    def test_softfloat_adjustment_removes_only_the_two_target_guards(self):
        source = ('before();\nif ((high & GARDMASK) == GARDMSB)\n'
                  '{ if (nested) { round_high(); } }\n'
                  'between();\nif ((quotient & GARDMASK) == GARDMSB)\n'
                  '{ round_quotient(); }\nafter();\n')
        result = stage_gcc_runtime.ps2_softfloat(source)
        for statement in ("before();", "between();", "after();"):
            self.assertIn(statement, result)
        self.assertNotIn("round_high", result)
        self.assertNotIn("round_quotient", result)
        with self.assertRaises(ValueError):
            stage_gcc_runtime.ps2_softfloat(result)

    def test_pack_adjustments_keep_the_surrounding_public_code(self):
        source = ("prefix();\n      if (src->normal_exp < NORMAL_EXPMIN)\n"
                  "{ original_rounding(); }\n    }\n\n  /* We previously used bitfields */\n"
                  "suffix();\n")
        single = stage_gcc_runtime.ps2_pack(source, single=True)
        double = stage_gcc_runtime.ps2_pack(source, single=False)
        for result in (single, double):
            self.assertIn("prefix();", result)
            self.assertIn("suffix();", result)
            self.assertIn("fraction >>= NGARDS", result)
            self.assertNotIn("original_rounding", result)
        self.assertIn("EXPBIAS + 1", single)
        self.assertNotIn("EXPBIAS + 1", double)

    def test_unpack_single_keeps_maximum_exponent_as_normal(self):
        source = ("unpack_d (FLO_union_type * src, fp_number_type * dst)\n{\n"
                  "if (exp == 0) { zero(); }\n  else if (exp == EXPMAX)\n    {\n"
                  "\t  dst->class = CLASS_INFINITY;\n    }\n"
                  "else { normal(); }\n}\n#endif /* L_unpack_df || L_unpack_sf */\n")
        result = stage_gcc_runtime.ps2_unpack(source, single=True)
        self.assertIn("zero();", result)
        self.assertIn("normal();", result)
        self.assertNotIn("exp == EXPMAX", result)
        self.assertNotIn("CLASS_INFINITY", result)

    def test_unpack_double_retains_infinity_parts(self):
        source = ("unpack_d (FLO_union_type * src, fp_number_type * dst)\n{\n"
                  "if (exp == 0) { zero(); }\n  else if (exp == EXPMAX)\n    {\n"
                  "\t  dst->class = CLASS_INFINITY;\n    }\n"
                  "else { normal(); }\n}\n#endif /* L_unpack_df || L_unpack_sf */\n")
        result = stage_gcc_runtime.ps2_unpack(source, single=False)
        self.assertIn("dst->normal_exp = EXPBIAS;", result)
        self.assertIn("dst->fraction.ll = IMPLICIT_1;", result)
        self.assertIn("CLASS_INFINITY", result)

    def test_unrecognized_public_source_is_rejected(self):
        for transform in (stage_gcc_runtime.ps2_pack, stage_gcc_runtime.ps2_unpack):
            with self.subTest(transform=transform.__name__), self.assertRaises(ValueError):
                transform("unexpected snapshot", single=True)


@unittest.skipUnless(sys.platform != "win32" and shutil.which("bash"), "requires POSIX shell")
class AssemblerWrapperTests(unittest.TestCase):
    def test_extra_compiler_arguments_and_paths_with_spaces(self):
        with tempfile.TemporaryDirectory() as directory:
            work = Path(directory)
            gcc = work / "gcc"
            assembler = work / "assembler"
            gcc.write_text('#!/bin/bash\nset -e\nprintf "%s\\n" "$@" > args.txt\n'
                           'while [ "$1" != "-o" ]; do shift; done\n'
                           'printf "assembly" > "$2"\n')
            assembler.write_text('#!/bin/bash\nset -e\n'
                                 'while [ "$1" != "-o" ]; do shift; done\n'
                                 'printf "object" > "$2"\n')
            gcc.chmod(0o755)
            assembler.chmod(0o755)
            output = work / "output file.o"
            subprocess.run(["bash", str(ROOT / "tools/cc_as.sh"), str(assembler),
                            str(gcc) + " -O2", "-DVALUE=1", "-Iinclude with spaces",
                            "source file.c", "-o", str(output)], cwd=work, check=True)
            self.assertEqual(output.read_text(), "object")
            arguments = (work / "args.txt").read_text().splitlines()
            self.assertIn("-DVALUE=1", arguments)
            self.assertIn("-Iinclude with spaces", arguments)
            self.assertIn("source file.c", arguments)

    def test_missing_output_argument_has_a_clear_failure(self):
        for arguments in ([], ["as", "gcc", "input.c"], ["as", "gcc", "input.c", "-o"]):
            with self.subTest(arguments=arguments):
                result = subprocess.run(["bash", str(ROOT / "tools/cc_as.sh"), *arguments],
                                        capture_output=True, text=True)
                self.assertEqual(result.returncode, 2)
                self.assertIn("cc_as.sh:", result.stderr)


if __name__ == "__main__":
    unittest.main()
