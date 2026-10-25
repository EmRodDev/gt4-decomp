"""A data section may differ from the original only by the assembler's zero padding at its end."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build


class PaddedSectionTests(unittest.TestCase):
    # 00451238: three float constants, rounded up to 16 bytes by the assembler; the original
    # places the next unit's constant right after them.
    constants = bytes.fromhex("0000803f0000003f0000c03f")
    original = bytes(8) + constants + bytes.fromhex("813d7041") + bytes(16)

    def test_exact_bytes_are_full(self):
        self.assertEqual(build.rodata_matches(self.constants, self.original, 8), "full")

    def test_zero_tail_under_the_alignment_is_padded(self):
        self.assertEqual(build.rodata_matches(self.constants + bytes(4), self.original, 8), "padded")

    def test_nonzero_tail_is_refused(self):
        self.assertIsNone(build.rodata_matches(self.constants + b"\x01\0\0\0", self.original, 8))

    def test_changed_constant_is_refused(self):
        changed = b"\x01" + self.constants[1:] + bytes(4)
        self.assertIsNone(build.rodata_matches(changed, self.original, 8))

    def test_tail_of_sixteen_bytes_or_more_is_refused(self):
        self.assertIsNone(build.rodata_matches(self.constants[:8] + bytes(24), self.original, 8))

    def test_section_not_a_multiple_of_eight_is_refused(self):
        self.assertIsNone(build.rodata_matches(self.constants + bytes(2), self.original, 8))

    def test_negative_offset_is_refused(self):
        self.assertIsNone(build.rodata_matches(self.constants, self.original, -4))


if __name__ == "__main__":
    unittest.main()
