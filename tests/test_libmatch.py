"""Regression cases from the GCC 2.96 RTTI sources."""
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import libmatch


class RttiExtractionTests(unittest.TestCase):
    def test_methods_after_namespace_headers_and_const_qualifiers(self):
        text = """namespace std {
class type_info { virtual bool equal() const; };
}
namespace
{
inline void *convert(void *p) { return p; }
}
bool __si_type_info::
do_upcast(int mode) const
{
    if (mode) { return true; }
    return false;
}
extern "C" int __throw_type_match_rtti(void *p)
{ return p != 0; }
"""
        lines = [(line, "tinfo.cc") for line in text.splitlines()]
        defs = libmatch.find_definitions(lines)
        keys = [libmatch.cxx_key(d.signature(lines)) for d in defs if d.kind == "func"]
        self.assertEqual(keys, [(None, "convert"), ("__si_type_info", "do_upcast"),
                                (None, "__throw_type_match_rtti")])
        self.assertIn("if (mode)", "\n".join(defs[1].body(lines)))

    def test_multiple_builtin_macro_definitions_and_stringification(self):
        text = (
            '#define BUILTIN(t) int value_##t; const char *name_##t() { return #t; }\n'
            'BUILTIN (v); BUILTIN (Ui);\n'
        )
        lines = [(line, "tinfo2.cc") for line in text.splitlines()]
        expanded = libmatch.expand_function_macros(lines)
        defs = libmatch.find_definitions(expanded)
        names = [d.name for d in defs if d.kind == "func"]
        self.assertEqual(names, ["name_v", "name_Ui"])
        self.assertIn('return "v";', "\n".join(line for line, _ in expanded))
        self.assertIn('return "Ui";', "\n".join(line for line, _ in expanded))

    def test_shared_aligned_arrays_and_initialized_objects_become_extern(self):
        text = (
            "unsigned char __tiv [sizeof (Type)]\n"
            "  __attribute__ ((aligned (__alignof__ (void *))));\n"
            "static int use_table = 1;\n"
            "extern int existing;\n"
        )
        result = libmatch.declare_external_objects(text, ["__tiv", "use_table", "existing"])
        self.assertIn("extern unsigned char __tiv [sizeof (Type)]", result)
        self.assertIn("__attribute__ ((aligned", result)
        self.assertIn("extern int use_table;", result)
        self.assertEqual(result.count("extern int existing;"), 1)

    def test_nothrow_context_is_limited_to_its_original_unit(self):
        with tempfile.TemporaryDirectory() as directory:
            for filename, name in [("tinfo.cc", "first"), ("tinfo2.cc", "second")]:
                Path(directory, filename).write_text(
                    "class Type { bool equal(int) const; };\n"
                    f'extern "C" int {name}() {{ return 1; }}\n'
                )
            cfg = {"name": "fixture", "source": directory,
                   "nothrow_declarations": {"tinfo.cc": ["bool equal(int) const;"]}}
            report = {"symbols": {}, "functions": {
                name: {"status": "found", "address": f"{0x100000+i*8:08x}",
                       "file": filename, "offset": 0}
                for i, (filename, name) in enumerate([("tinfo.cc", "first"),
                                                     ("tinfo2.cc", "second")])
            }}
            first = libmatch.emit_source(cfg, report, "first")
            second = libmatch.emit_source(cfg, report, "second")
            self.assertIn("equal(int) const throw();", first)
            self.assertNotIn("equal(int) const throw();", second)

    def test_full_leading_line_comment_notice_is_preserved(self):
        text = "// Copyright FSF\n\n// Redistribution terms\n// Linking exception\nint value; // internal note\n"
        result = libmatch.strip_comments(text)
        self.assertIn("// Copyright FSF", result)
        self.assertIn("// Redistribution terms", result)
        self.assertIn("// Linking exception", result)
        self.assertNotIn("internal note", result)

    def test_line_comment_notice_can_be_kept_after_code(self):
        result = libmatch.strip_comments("int value; // Copyright second author\n", keep=("Copyright",))
        self.assertIn("// Copyright second author", result)


if __name__ == "__main__":
    unittest.main()
