"""Public STL algorithm generators retain value layout and real template bodies."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import stl_algo


class AlgorithmSourceTests(unittest.TestCase):
    def test_inline_key_layout_and_comparison(self):
        src = stl_algo.source(stl_algo.Spec(44, 40), "adjust_heap", "005D45B8")
        self.assertIn("char prefix[40]; int key;", src)
        self.assertIn("return key < o.key;", src)
        self.assertIn("template void __adjust_heap(SortValue_005D45B8 *, int, int, SortValue_005D45B8);", src)
        self.assertNotIn("005int45B8", src)

    def test_key_at_start_has_no_zero_length_array(self):
        src = stl_algo.source(stl_algo.Spec(12, 0, "unsigned int"), "push_heap", "A")
        self.assertIn("unsigned int key; char suffix[8];", src)
        self.assertNotIn("[0]", src)

    def test_descending_keeps_a_real_comparison(self):
        src = stl_algo.source(stl_algo.Spec(8, 4, "float", descending=True), "sort_heap", "A")
        self.assertIn("return key > o.key;", src)

    def test_external_comparator_has_one_byte_state_and_real_forwarder(self):
        src = stl_algo.source(stl_algo.Spec(12, comparator="external"), "adjust_heap", "B")
        self.assertIn("int words[3]", src)
        self.assertIn("char state;", src)
        self.assertIn("return sort_compare_B(&a, &b);", src)
        self.assertIn("SortValue_B, SortCompare_B);", src)

    def test_function_pointer_comparator_is_not_a_stateful_object(self):
        src = stl_algo.source(stl_algo.Spec(8, comparator="pointer"), "push_heap", "C")
        self.assertIn("typedef bool (*SortCompare_C)", src)
        self.assertNotIn("char state", src)

    def test_make_heap_comparator_precedes_deduction_pointers(self):
        src = stl_algo.source(stl_algo.Spec(12, comparator="external"), "make_heap", "D")
        self.assertIn("SortValue_D *, SortValue_D *, SortCompare_D, SortValue_D *, int *", src)

    def test_invalid_layouts_are_rejected(self):
        for spec in (stl_algo.Spec(0), stl_algo.Spec(6), stl_algo.Spec(8, 6),
                     stl_algo.Spec(8, 8), stl_algo.Spec(8, -4)):
            with self.subTest(spec=spec), self.assertRaises(ValueError):
                spec.validate()

    def test_every_member_uses_the_public_header(self):
        for member in stl_algo.MEMBERS:
            src = stl_algo.source(stl_algo.Spec(16), member, "E")
            self.assertIn("#include <stl_algo.h>", src)
            self.assertEqual(src.count("template "), 1)
            self.assertNotIn("asm", src)


if __name__ == "__main__":
    unittest.main()
