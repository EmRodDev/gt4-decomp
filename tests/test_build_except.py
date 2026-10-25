"""A function compiled alone brings an exception table of its own (header, its entries, -1);
the original keeps those entries inside its file's shared table, which is all the code reaches."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build
import match


class SharedExceptionTableTests(unittest.TestCase):
    address = 0x00596fc0
    data_address = 0x006d5000
    table_address = 0x006d5ce0

    def place(self, *, entries_differ=False, no_terminator=False):
        section = ".gcc_except_table"
        # lui a0,%hi(table); addiu a0,a0,%lo(table): ours at 0, the original's at table_address
        mine = struct.pack("<II", 0x3c040000, 0x24840000)
        original = struct.pack("<II", 0x3c04006d, 0x24845ce0)
        relocations = {0: (match.R_MIPS_HI16, section, 0, False), 4: (match.R_MIPS_LO16, section, 0, False)}
        entries = struct.pack("<III", 0x10, 0x30, 0x58)
        table = struct.pack("<II", 0xfffffffe, 0x00010004) + entries + (b"" if no_terminator else b"\xff" * 4)
        data = bytearray(0x1000)
        offset = self.table_address - self.data_address
        # The shared table: another header, then this function's entries, then the next function's.
        shared = struct.pack("<II", 0xfffffffe, 0x00020008) + (b"\x00" * 12 if entries_differ else entries) \
            + struct.pack("<III", 0x70, 0x90, 0xb8)
        data[offset:offset + len(shared)] = shared
        dump = f"@ func_{self.address:08X}.o\n"
        build.PADDED_DATA.discard((self.address, section))
        with tempfile.TemporaryDirectory() as directory, \
             patch.object(build, "OUT", directory), \
             patch.object(build, "wsl", side_effect=["", dump]), \
             patch.object(build, "elf_section", return_value=table), \
             patch.object(match, "read_object", return_value=(mine, relocations, [])):
            out = build.place_rodata([self.address], self.data_address, bytes(data), original,
                                     self.address, section=section)
        return out, (self.address, section) in build.PADDED_DATA

    def test_entries_inside_a_shared_table_are_located(self):
        self.assertEqual(self.place(), ({self.address: self.table_address}, True))

    def test_different_entries_are_refused(self):
        self.assertEqual(self.place(entries_differ=True), ({}, False))

    def test_table_without_terminator_is_refused(self):
        self.assertEqual(self.place(no_terminator=True), ({}, False))


if __name__ == "__main__":
    unittest.main()
