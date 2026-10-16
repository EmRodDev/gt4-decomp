"""Layouts and comparators inferred from the GT4 tree instantiations."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import stl


class TreeSourceTests(unittest.TestCase):
    def test_symbol_ids_compare_as_unsigned_words(self):
        text = stl.key_source("HSymID")
        self.assertIn("unsigned int w[1]", text)
        self.assertIn("return w[0] < o.w[0]", text)

    def test_set_uses_identity_and_the_original_node_type_getter(self):
        text = stl.source(stl.KNOWN_TREES[0x5de030], "_M_insert")
        self.assertIn("typedef HSymID Value;", text)
        self.assertIn("_Identity<Value>", text)
        self.assertIn("func_005DEAC8", text)
        self.assertNotIn("_Select1st<Value>", text)

    def test_ordinary_map_retains_pair_and_select_first(self):
        text = stl.source(stl.KNOWN_TREES[0x5eeb70], "insert_unique")
        self.assertIn("typedef pair<const HSymID, Val_00323B48> Value;", text)
        self.assertIn("_Select1st<Value>", text)
        self.assertIn("func_005EFEA0", text)

    def test_plain_maps_keep_distinct_value_types_and_plain_allocator(self):
        first = stl.source(stl.KNOWN_TREES[0x60cb20], "_M_insert")
        second = stl.source(stl.KNOWN_TREES[0x60d000], "_M_insert")
        self.assertIn("Pod4_0060CB20", first)
        self.assertIn("Pod4_0060D000", second)
        for text in (first, second):
            self.assertIn("typedef unsigned int Key;", text)
            self.assertIn("func_00575E60(0x10, n * sizeof(T))", text)
            self.assertIn("func_00575DA0(p)", text)


if __name__ == "__main__":
    unittest.main()
