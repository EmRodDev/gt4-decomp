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

    def test_weak_operator_wrapper_preserves_nested_argument_commas(self):
        text = (
            '#define WEAK(x) x __attribute__((weak)); x\n'
            'WEAK(void *operator new(size_t size, const Tag& tag) throw())\n'
            '{ return allocate(size); }\n'
        )
        lines = [(line, "new1.cc") for line in text.splitlines()]
        expanded = libmatch.expand_function_macros(lines)
        defs = libmatch.find_definitions(expanded)
        self.assertEqual(len(defs), 1)
        self.assertEqual(libmatch.cxx_key(defs[0].signature(expanded)), (None, "operatornew"))
        self.assertIn("const Tag& tag", defs[0].signature(expanded))
        self.assertIn("return allocate(size)", "\n".join(defs[0].body(expanded)))

    def test_old_abi_builtin_operators_and_std_namespace(self):
        for symbol, signature in [
            ("__builtin_new", "void *operator new(size_t) throw(std::bad_alloc)"),
            ("__builtin_vec_new", "void *operator new[](size_t) throw(std::bad_alloc)"),
            ("__builtin_delete", "void operator delete(void *) throw()"),
            ("__builtin_vec_delete", "void operator delete[](void *) throw()"),
            ("uncaught_exception__Fv", "bool std::uncaught_exception()"),
            ("what__C9exception", "const char *std::exception::what() const"),
        ]:
            with self.subTest(symbol=symbol):
                self.assertEqual(libmatch.mangled_key(symbol), libmatch.cxx_key(signature))

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

    def test_shared_function_pointers_become_extern(self):
        text = (
            "static Context *(*get_context)(void) = &initialize;\n"
            "void (*terminate_handler)(void) __attribute__((__noreturn__)) =\n"
            "  default_terminate;\n"
        )
        result = libmatch.declare_external_objects(text, ["get_context", "terminate_handler"])
        self.assertIn("extern Context * (*get_context)(void);", result)
        self.assertIn("extern void (*terminate_handler)(void) __attribute__((__noreturn__));", result)
        self.assertNotIn("=", result)

    def test_nonstatic_initialized_arrays_do_not_become_common_definitions(self):
        self.assertEqual(libmatch.extern_declaration("const double tens[] =", "{1, 10, 100}"),
                         "extern const double tens[3];")
        self.assertEqual(libmatch.extern_declaration("static int p05[6] =", "{5, 25}"),
                         "extern int p05[6];")
        self.assertEqual(libmatch.extern_declaration("extern int table[] =", "{1}"),
                         "extern int table[1];")

    def test_const_classifier_context_survives_function_extraction(self):
        with tempfile.TemporaryDirectory() as directory:
            Path(directory, "unit.c").write_text(
                "static int classify(int x) { return x & 1; }\n"
                "int consume(int x) { return classify(x); }\n")
            cfg = {"name": "fixture", "source": directory,
                   "const_contexts": {"consume": ["classify"]}}
            report = {"symbols": {}, "functions": {
                "consume": {"status": "found", "address": "00100000", "file": "unit.c"}}}
            text = libmatch.emit_source(cfg, report, "consume")
            self.assertIn("__attribute__((const)) static int classify(int x)", text)
            self.assertNotIn("return x & 1", text)
            self.assertIn("return classify(x)", text)

    def test_notype_bss_symbol_is_learned_from_section_relocations(self):
        relocations = {0: (libmatch.match.R_MIPS_HI16, ".bss", 0, False),
                       4: (libmatch.match.R_MIPS_LO16, ".bss", 0, False)}
        learned = libmatch.learn_symbols(
            [0x3c020089, 0x2442d944], [0x3c020000, 0x24420000],
            relocations, 0x005be6d0, [("marker.0", 0, 0, ".bss", 0)])
        self.assertEqual(learned, {"marker.0": 0x0088d944})

    def test_inline_uninitialized_static_is_externalized(self):
        body = ["{", "  static Frame *marker;", "  return &marker;", "}"]
        known = {}
        result = "\n".join(libmatch.localize_statics(body, {"marker": 0x88d944}, known))
        self.assertIn("#define marker D_0088D944", result)
        self.assertIn("extern Frame *marker;", result)
        self.assertEqual(known, {"marker": 0x88d944})

    def test_explicit_local_constant_preservation_keeps_the_pool_layout(self):
        body = ["{", "static const char token[] = {1, 2, 3};",
                "static Frame *marker;", "return token[0];", "}"]
        known = {}
        text = "\n".join(libmatch.localize_statics(
            body, {"token": 0x600000, "marker": 0x880000}, known, preserve=["token"]))
        self.assertIn("static const char token[] = {1, 2, 3};", text)
        self.assertNotIn("#define token", text)
        self.assertIn("extern Frame *marker;", text)
        self.assertEqual(known, {"marker": 0x880000})

    def test_negative_array_addend_still_identifies_section_zero_symbol(self):
        relocations = {0: (libmatch.match.R_MIPS_HI16, ".data", 0, False),
                       4: (libmatch.match.R_MIPS_LO16, ".data", 0, False)}
        learned = libmatch.learn_symbols(
            [0x3c050065, 0x8ca57edc], [0x3c050000, 0x8ca5fffc],
            relocations, 0x00597fe0, [("p05.0", 0, 24, ".data", 1)])
        self.assertEqual(learned, {"p05.0": 0x00657ee0})
        self.assertEqual(libmatch.learn_symbols(
            [0x3c050065, 0x8ca57edc], [0x3c050000, 0x8ca5fffc],
            relocations, 0x00597fe0, [("p05.0", 16, 24, ".data", 1)]), {})

    def test_preserve_libc_builtin_names_and_drop_implementation_pragma(self):
        with tempfile.TemporaryDirectory() as directory:
            Path(directory, "unit.c").write_text(
                '#pragma implementation "exception"\n'
                'extern void *memcpy(void *, const void *, unsigned);\n'
                'void copy(void *a, const void *b) { memcpy(a, b, 32); }\n')
            cfg = {"name": "fixture", "source": directory,
                   "preserve_symbols": ["memcpy"], "omit_implementation_pragmas": True}
            report = {"symbols": {"memcpy": "005a4724"}, "functions": {
                "copy": {"status": "found", "address": "00100000",
                         "file": "unit.c", "offset": 0}}}
            result = libmatch.emit_source(cfg, report, "copy")
            self.assertIn("memcpy(a, b, 32)", result)
            self.assertNotIn("#define memcpy", result)
            self.assertNotIn("#pragma implementation", result)

    def test_explicit_groups_keep_shared_exception_tables_together(self):
        from unittest.mock import patch
        report = {"functions": {
            "first": {"status": "found", "address": "00100000", "size": 16, "file": "unit.c"},
            "second": {"status": "found", "address": "00100010", "size": 16, "file": "unit.c"},
            "third": {"status": "found", "address": "00100020", "size": 16, "file": "unit.c"}}}
        with patch.object(libmatch, "has_source", return_value=False), \
             patch.object(libmatch, "is_function_start", return_value=True):
            self.assertEqual(libmatch.emit_groups(report, source_groups=[["first", "second"]]),
                             [(["first", "second"], 0x100000), (["third"], 0x100020)])
            with self.assertRaisesRegex(ValueError, "intervening"):
                libmatch.emit_groups(report, source_groups=[["first", "third"]])
            report["functions"]["second"]["file"] = "other.c"
            with self.assertRaisesRegex(ValueError, "translation units"):
                libmatch.emit_groups(report, source_groups=[["first", "second"]])

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


class PreprocessedExtractionTests(unittest.TestCase):
    def definitions(self, text):
        lines = [(line, "unit.c") for line in text.splitlines()]
        return lines, libmatch.find_definitions(lines)

    def test_macro_scope_ignores_braces_in_multiline_comments(self):
        text = ('/* Copyright example {\n * terms\n */\n'
                '#define DEFINE(x) int x() { return 1; }\nDEFINE(real)\n')
        lines = [(line, "unit.c") for line in text.splitlines()]
        expanded = libmatch.expand_function_macros(lines)
        self.assertEqual([d.name for d in libmatch.find_definitions(expanded)], ["real"])

    def test_line_markers_and_blank_lines_inside_ansi_parameters(self):
        with tempfile.TemporaryDirectory() as directory:
            Path(directory, "unit.c").write_text(
                '# 1 "unit.c"\nint convert(\n# 12 "header.h" 2\n'
                '\n  int value,\n\n  int radix)\n{ return value + radix; }\n')
            lines = libmatch.flatten({"source": directory}, "unit.c")
            definitions = libmatch.find_definitions(lines)
            self.assertEqual([d.name for d in definitions], ["convert"])
            self.assertIn("int value", definitions[0].signature(lines))
            self.assertIn("int radix", definitions[0].signature(lines))
            self.assertNotIn('# 12', "\n".join(line for line, _ in lines))

    def test_knr_parameters_keep_blank_lines_and_comments(self):
        lines, definitions = self.definitions(
            "int convert(value, radix)\n\nint value;\n"
            "/* separate parameter */\n\nint radix;\n"
            "{ return value + radix; }\n")
        self.assertEqual([d.name for d in definitions], ["convert"])
        signature = definitions[0].signature(lines)
        self.assertIn("int value;", signature)
        self.assertIn("int radix;", signature)

    def test_license_parentheses_and_braces_do_not_define_functions(self):
        lines, definitions = self.definitions(
            "/* Copyright (c) Example { terms; } */\n\n"
            "int real(int x)\n{ /* } */ return x; }\n")
        self.assertEqual([(d.kind, d.name) for d in definitions], [("func", "real")])
        self.assertNotIn("Copyright", definitions[0].signature(lines))

    def test_comment_mask_preserves_columns_and_quoted_literals(self):
        text = '"/* literal */"; /* multi\nline { } */ int x; // trailing\n'
        masked = libmatch.mask_comments(text)
        self.assertEqual(len(masked), len(text))
        self.assertEqual([i for i, ch in enumerate(masked) if ch == "\n"],
                         [i for i, ch in enumerate(text) if ch == "\n"])
        self.assertIn('"/* literal */"', masked)
        self.assertEqual(masked.index("int x"), text.index("int x"))
        self.assertNotIn("trailing", masked)

    def test_long_ansi_varargs_head_is_not_a_knr_declaration(self):
        signature = "int output(" + "const char *format, " * 80 + "...)"
        self.assertIsNone(libmatch.KNR_HEAD.search(signature))
        _, definitions = self.definitions(signature + "\n{ return 0; }\n")
        self.assertEqual([d.name for d in definitions], ["output"])

    def test_unused_guessed_alias_does_not_redefine_header_prototype(self):
        with tempfile.TemporaryDirectory() as directory:
            Path(directory, "unit.c").write_text(
                "extern int get(void *);\nextern int overflow(void *, int);\n"
                "int target(void *p) { return get(p); }\n")
            cfg = {"name": "fixture", "source": directory}
            report = {"symbols": {"get": "00101000", "overflow": "00101000"},
                      "functions": {"target": {"status": "found", "address": "00100000",
                                                "file": "unit.c", "refs": {"get": "00101000"}}}}
            text = libmatch.emit_source(cfg, report, "target")
            self.assertIn("#define get ", text)
            self.assertNotIn("#define overflow ", text)


if __name__ == "__main__":
    unittest.main()
