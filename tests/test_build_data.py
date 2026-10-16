"""Data placement must prove all references and relocated bytes against the image."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build
import match


class DataPlacementTests(unittest.TestCase):
    address = 0x005c1498
    data_address = 0x006d5000
    section_address = 0x006d5ce0

    def place(self, *, corrupt=False, relocation="R_MIPS_32", references=True,
              inconsistent=False, outside=False):
        section = ".gcc_except_table"
        mine = struct.pack("<II", 0x3c040000, 0x24840010)
        original = struct.pack("<II", 0x3c04006d, 0x24845cf0)
        relocations = {0: (match.R_MIPS_HI16, section, 0, False),
                       4: (match.R_MIPS_LO16, section, 0, False)} if references else {}
        if inconsistent:
            mine += struct.pack("<II", 0x3c040000, 0x24840010)
            original += struct.pack("<II", 0x3c04006d, 0x24845d00)
            relocations.update({8: (match.R_MIPS_HI16, section, 0, False),
                                12: (match.R_MIPS_LO16, section, 0, False)})
        table = struct.pack("<III", 0xfffffffe, 0x00010004, 0x10)
        relocated = struct.pack("<III", 0xfffffffe, 0x00010004, self.address + 0x10)
        data = bytearray(0x1000)
        offset = self.section_address - self.data_address
        data[offset:offset + len(relocated)] = relocated
        if corrupt:
            data[offset + 4] ^= 1
        if outside:
            data = data[:offset + len(relocated) - 1]
        dump = f"@ func_{self.address:08X}.o\n00000008 {relocation} .text\n"
        with tempfile.TemporaryDirectory() as directory, \
             patch.object(build, "OUT", directory), \
             patch.object(build, "wsl", side_effect=["", dump]), \
             patch.object(build, "elf_section", return_value=table), \
             patch.object(match, "read_object", return_value=(mine, relocations, [])):
            return build.place_rodata([self.address], self.data_address, bytes(data),
                                     original, self.address, section=section)

    def test_exception_table_with_exact_relocated_bytes_is_placed(self):
        self.assertEqual(self.place(), {self.address: self.section_address})

    def test_one_changed_byte_rejects_the_section(self):
        self.assertEqual(self.place(corrupt=True), {})

    def test_unknown_relocation_rejects_the_section(self):
        self.assertEqual(self.place(relocation="R_MIPS_26"), {})

    def test_missing_reference_rejects_the_section(self):
        self.assertEqual(self.place(references=False), {})

    def test_disagreeing_reference_bases_reject_the_section(self):
        self.assertEqual(self.place(inconsistent=True), {})

    def test_section_extending_outside_the_loaded_data_is_rejected(self):
        self.assertEqual(self.place(outside=True), {})


if __name__ == "__main__":
    unittest.main()
