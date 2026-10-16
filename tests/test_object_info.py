"""Direct metadata decoding keeps the ELF data used by source selection intact."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import object_info


def fixture():
    names = ["", ".text", ".gnu.linkonce.t.test", ".bss", ".strtab", ".symtab", ".shstrtab"]
    name_table = b"\0"
    offsets = {"": 0}
    for name in names[1:]:
        offsets[name] = len(name_table)
        name_table += name.encode() + b"\0"
    strings = b"\0undefined\0defined\0weak\0"
    symtab = (bytes(16) + struct.pack("<IIIBBH", 1, 0, 0, 16, 0, 0)
              + struct.pack("<IIIBBH", 11, 0, 4, 18, 0, 1)
              + struct.pack("<IIIBBH", 19, 0, 0, 32, 0, 0))
    data = bytearray(52)
    data[:7] = b"\x7fELF\x01\x01\x01"
    sections = [bytes(40)]
    for i, (name, kind, body, size) in enumerate([
            (".text", 1, bytes(8), 8), (".gnu.linkonce.t.test", 1, bytes(12), 12),
            (".bss", 8, b"", 1024), (".strtab", 3, strings, len(strings)),
            (".symtab", 2, symtab, len(symtab)), (".shstrtab", 3, name_table, len(name_table))], 1):
        offset = len(data)
        data += body
        sections.append(struct.pack("<10I", offsets[name], kind, 0, 0, offset, size,
                                     4 if kind == 2 else 0, 0, 1, 16 if kind == 2 else 0))
    shoff = len(data)
    for section in sections:
        data += section
    struct.pack_into("<I", data, 32, shoff)
    struct.pack_into("<HHH", data, 46, 40, len(sections), 6)
    return data


class ObjectInfoTests(unittest.TestCase):
    def read(self, data):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "a.o"
            path.write_bytes(data)
            return object_info.read_info(path)

    def test_template_code_is_summed_with_text(self):
        result = self.read(fixture())
        self.assertEqual(result["sections"][".text"], 20)
        self.assertFalse(any(k.startswith(".gnu.linkonce.t.") for k in result["sections"]))

    def test_uninitialized_storage_does_not_require_file_bytes(self):
        self.assertEqual(self.read(fixture())["sections"][".bss"], 1024)

    def test_undefined_global_and_weak_names_survive(self):
        self.assertEqual(self.read(fixture())["undefined"], ["undefined", "weak"])

    def test_wrong_endianness_is_rejected(self):
        data = fixture(); data[5] = 2
        with self.assertRaises(ValueError): self.read(data)

    def test_truncated_section_headers_are_rejected(self):
        with self.assertRaises(ValueError): self.read(fixture()[:-1])

    def test_invalid_string_offset_is_rejected(self):
        data = fixture(); shoff = struct.unpack_from("<I", data, 32)[0]
        struct.pack_into("<I", data, shoff + 40, 0x100000)
        with self.assertRaises(ValueError): self.read(data)

    def test_only_expected_existing_objects_are_collected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "func_00001000.o").write_bytes(fixture())
            (root / "func_00002000.o").write_bytes(fixture())
            listing = root / "expected.txt"
            listing.write_text("func_00001000.o\nfunc_00003000.o\n")
            self.assertEqual(set(object_info.collect(root, listing)), {0x1000})

    def test_listing_cannot_escape_object_directory(self):
        with tempfile.TemporaryDirectory() as directory:
            listing = Path(directory) / "expected.txt"
            listing.write_text("../other.o\n")
            with self.assertRaises(ValueError): object_info.collect(directory, listing)


if __name__ == "__main__":
    unittest.main()
