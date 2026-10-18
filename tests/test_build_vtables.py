"""A C++ object's vtable and companions are placed only where they equal the original."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build

TEXT, DATA = 0x100000, 0x200000
HI, LO, W32, J26 = 5, 6, 2, 4
words = lambda *ws: struct.pack(f"<{len(ws)}I", *ws)
resolve = {"func_00100800": 0x100800}.get


def section(name, data, flags):
    return {"name": name, "flags": flags, "size": len(data), "data": data}


def image(text_writes, data_writes):
    text, data = bytearray(0x1000), bytearray(0x1000)
    for a, b in text_writes:
        text[a - TEXT:a - TEXT + len(b)] = b
    for a, b in data_writes:
        data[a - DATA:a - DATA + len(b)] = b
    return bytes(text), bytes(data)


class CompanionTests(unittest.TestCase):
    """A constructor at 0x100000 loads its vtable (0x200100); the vtable points at the type-info
    function (0x100400) and an outside method; the type-info function loads its type name (0x200200)."""

    def obj(self, rodata=b"3Foo\0", extra=()):
        sections = [section("", b"", 0),
                    section(".text", words(0x3C040000, 0x24840000), 6),
                    section(".gnu.linkonce.d._vt$3Foo", words(0, 0, 0, 0), 3),
                    section(".gnu.linkonce.t.__tf3Foo", words(0x3C020000, 0x24420000), 6),
                    section(".rodata", rodata, 2)] + list(extra)
        symbols = [("", 0, 0, True), ("_vt$3Foo", 0, 2, True), ("__tf3Foo", 0, 3, True),
                   (".rodata", 0, 4, True), ("func_00100800", 0, 0, False)]
        relocs = {1: [(0, HI, 1), (4, LO, 1)], 2: [(4, W32, 2), (8, W32, 4)], 3: [(0, HI, 3), (4, LO, 3)]}
        return {"sections": sections, "symbols": symbols, "relocs": relocs}

    def original(self, vtable=None, name=b"3Foo\0"):
        return image([(0x100000, words(0x3C040020, 0x24840100)), (0x100400, words(0x3C020020, 0x24420200))],
                     [(0x200100, vtable or words(0, 0x100400, 0x100800, 0)), (0x200200, name)])

    def place(self, obj, original):
        text, data = original
        return build.companion_places(obj, 0x100000, TEXT, text, DATA, data, resolve)

    def test_identical_vtable_and_companions_are_placed(self):
        self.assertEqual(self.place(self.obj(), self.original()), {
            "size": 8,
            "data": {".gnu.linkonce.d._vt$3Foo": 0x200100, ".rodata": 0x200200},
            "noload": {".gnu.linkonce.t.__tf3Foo": 0x100400}})

    def test_vtable_slot_the_source_lacks_refuses_the_object(self):
        self.assertIsNone(self.place(self.obj(), self.original(vtable=words(0, 0x100400, 0x100800, 0x100900))))

    def test_vtable_pointing_elsewhere_refuses_the_object(self):
        self.assertIsNone(self.place(self.obj(), self.original(vtable=words(0, 0x100400, 0x100804, 0))))

    def test_different_type_name_refuses_the_object(self):
        self.assertIsNone(self.place(self.obj(), self.original(name=b"3Fop\0")))

    def test_unresolved_symbol_refuses_the_object(self):
        obj = self.obj()
        obj["symbols"][4] = ("v1__10ResultBase", 0, 0, False)
        self.assertIsNone(self.place(obj, self.original()))

    def test_unknown_relocation_refuses_the_object(self):
        obj = self.obj()
        obj["relocs"][2][1] = (8, 7, 4)  # R_MIPS_GPREL16
        self.assertIsNone(self.place(obj, self.original()))

    def test_other_data_refuses_the_object(self):
        self.assertIsNone(self.place(self.obj(extra=[section(".data", words(1), 3)]), self.original()))

    def test_type_names_kept_apart_by_the_original_are_checked_piece_by_piece(self):
        # A second type-info function (0x100500) names a second class at .rodata+8; the original
        # keeps that name at 0x200300, so .rodata is linked NOLOAD once every piece is proven.
        obj = self.obj(rodata=b"3Foo\0\0\0\0" + b"3Bar\0")
        obj["sections"].append(section(".gnu.linkonce.t.__tf3Bar", words(0x3C020000, 0x24420008), 6))
        obj["symbols"].append(("__tf3Bar", 0, 5, True))
        obj["relocs"][5] = [(0, HI, 3), (4, LO, 3)]
        obj["relocs"][2].append((12, W32, 5))
        text, data = self.original(vtable=words(0, 0x100400, 0x100800, 0x100500))
        text, data = image([(0x100000, text[:0x1000 - 0x0]), (0x100500, words(0x3C020020, 0x24420300))],
                           [(0x200000, data), (0x200300, b"3Bar\0")])
        placed = self.place(obj, (text, data))
        self.assertEqual(placed["data"], {".gnu.linkonce.d._vt$3Foo": 0x200100})
        self.assertEqual(placed["noload"], {".gnu.linkonce.t.__tf3Foo": 0x100400,
                                            ".gnu.linkonce.t.__tf3Bar": 0x100500, ".rodata": 0x200200})
        data = data[:0x301] + b"X" + data[0x302:]
        self.assertIsNone(self.place(obj, (text, data)))

    def test_hi16_carries_into_the_upper_half(self):
        obj = {"sections": [section("", b"", 0), section(".text", words(0x3C040000, 0x24840000, 0x0C000000), 6)],
               "symbols": [("", 0, 0, True), ("func_00100800", 0, 0, False)],
               "relocs": {1: [(0, HI, 1), (4, LO, 1), (8, J26, 1)]}}
        built = build.relocate(obj, 1, {1: TEXT}, {"func_00100800": 0x2080F0}.get)
        self.assertEqual(built, words(0x3C040021, 0x248480F0, 0x0C000000 | 0x2080F0 >> 2))


if __name__ == "__main__":
    unittest.main()
