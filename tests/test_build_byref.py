"""Constants placed by reference: every %hi/%lo pair must name a constant that holds the
original's bytes, and anything the image check cannot see is refused with a reason."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build


class ByReferenceTests(unittest.TestCase):
    address = 0x00500000        # the function
    data_address = 0x00600000   # start of the original's data
    constant_address = 0x00600120

    def place(self, *, hi_opcode=0x0F, constant=b"abc\0", original_constant=b"abc\0", second_target=None):
        # .text: lui v0,%hi(.rodata); addiu v0,v0,%lo(.rodata) [; again for a second read]
        text = struct.pack("<II", (hi_opcode << 26) | (2 << 16), (9 << 26) | (2 << 21) | (2 << 16))
        relocs = [(0, 5, 1), (4, 6, 1)]
        original = struct.pack("<II", (0x0F << 26) | (2 << 16) | 0x0060, (9 << 26) | (2 << 21) | (2 << 16) | 0x0120)
        if second_target is not None:
            text += text[:8]
            relocs += [(8, 5, 1), (12, 6, 1)]
            original += struct.pack("<II", (0x0F << 26) | (2 << 16) | (second_target >> 16),
                                    (9 << 26) | (2 << 21) | (2 << 16) | (second_target & 0xFFFF))
        sections = {".text": text, ".rodata": constant}
        symbols = [("", 0, "", True), (".rodata", 0, ".rodata", True)]
        data = bytearray(0x1000)
        offset = self.constant_address - self.data_address
        data[offset:offset + len(original_constant)] = original_constant
        build.BYREF_WHY.clear()
        with tempfile.TemporaryDirectory() as directory, \
             patch.object(build, "OUT", directory), \
             patch.object(build, "wsl", return_value=""), \
             patch.object(build, "elf_info", return_value=(sections, {".text": relocs}, symbols)), \
             patch("builtins.open", side_effect=FileNotFoundError):
            try:
                out = build.place_rodata_by_reference([self.address], self.data_address, bytes(data),
                                                      original, self.address)
            except FileNotFoundError:
                out = "patched"  # every check passed: the object copy would be written now
        return out, build.BYREF_WHY.get(self.address)

    def test_matching_constant_is_placed(self):
        self.assertEqual(self.place()[0], "patched")

    def test_hi_word_that_is_not_lui_is_refused(self):
        out, why = self.place(hi_opcode=0x23)  # lw: ee-as 2.96's indexed-load macro
        self.assertEqual(out, {})
        self.assertIn("not a lui", why)

    def test_changed_constant_is_refused(self):
        out, why = self.place(original_constant=b"abd\0")
        self.assertEqual(out, {})
        self.assertIn("differs from the original", why)

    def test_one_constant_read_at_two_addresses_is_refused(self):
        out, why = self.place(second_target=0x00600200)
        self.assertEqual(out, {})
        self.assertEqual(why, "one constant read at two different addresses")


if __name__ == "__main__":
    unittest.main()
