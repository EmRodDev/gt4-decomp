"""A source group confers coverage only after its parent object was verified."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build


class SourceCoverageTests(unittest.TestCase):
    def test_whole_functions_without_standalone_sources_are_covered(self):
        result = build.record_source_coverage({0x1000: "linked"}, {0x1000: 0x30},
                                               {0x1000: 0x10, 0x1010: 0x10, 0x1020: 0x10})
        self.assertEqual(result[0x1000], "linked")
        self.assertEqual(result[0x1010], "linked as part of func_00001000")
        self.assertEqual(result[0x1020], "linked as part of func_00001000")

    def test_a_partial_next_function_does_not_count_as_complete(self):
        result = build.record_source_coverage({0x1000: "linked"}, {0x1000: 0x18},
                                               {0x1000: 0x10, 0x1010: 0x10})
        self.assertNotIn(0x1010, result)

    def test_rejected_parent_clears_earlier_coverage(self):
        for failure in ("differs after linking", "brings its own data: .rodata"):
            with self.subTest(failure=failure):
                result = build.record_source_coverage(
                    {0x1000: failure, 0x1010: "linked as part of func_00001000"},
                    {0x1000: 0x20}, {0x1000: 0x10, 0x1010: 0x10})
                self.assertEqual(result[0x1010], "covering source did not link")

    def test_separate_objects_and_gaps_keep_their_own_status(self):
        status = {0x1000: "linked", 0x1040: "linked", 0x1020: "does not compile"}
        result = build.record_source_coverage(status, {0x1000: 0x20, 0x1040: 0x20},
                                               {0x1000: 0x10, 0x1010: 0x10, 0x1020: 0x10,
                                                0x1040: 0x10, 0x1050: 0x10})
        self.assertEqual(result[0x1020], "does not compile")
        self.assertEqual(result[0x1040], "linked")
        self.assertEqual(result[0x1050], "linked as part of func_00001040")
        self.assertNotIn(0x1010, status)


class SourceSelectionTests(unittest.TestCase):
    @staticmethod
    def obj(size, **sections):
        return {"sections": {".text": size, **sections}, "undefined": []}

    def test_rejected_group_leaves_standalone_children_eligible(self):
        parsed = {0x1000: self.obj(0x30, **{".rodata": 4}),
                  0x1010: self.obj(0x10), 0x1020: self.obj(0x10)}
        status, objects, _ = build.select_source_objects(parsed, parsed, 0x1040, {".rodata": {}})
        self.assertIn("could not be confirmed", status[0x1000])
        self.assertEqual(objects, {0x1010: 0x10, 0x1020: 0x10})

    def test_group_requires_every_data_section_to_be_verified(self):
        parsed = {0x1000: self.obj(0x20, **{".rodata": 4, ".gcc_except_table": 8}),
                  0x1010: self.obj(0x10)}
        for places in ({".rodata": {0x1000: 0x2000}, ".gcc_except_table": {}},
                       {".rodata": {}, ".gcc_except_table": {0x1000: 0x2010}}):
            with self.subTest(places=places):
                _, objects, _ = build.select_source_objects(parsed, parsed, 0x1040, places)
                self.assertEqual(objects, {0x1010: 0x10})
        _, objects, _ = build.select_source_objects(parsed, parsed, 0x1040,
              {".rodata": {0x1000: 0x2000}, ".gcc_except_table": {0x1000: 0x2010}})
        self.assertEqual(objects, {0x1000: 0x20})

    def test_excluded_cached_group_does_not_hide_children(self):
        parsed = {0x1000: self.obj(0x30), 0x1010: self.obj(0x10)}
        status, objects, _ = build.select_source_objects(parsed, [0x1010], 0x1040, {})
        self.assertNotIn(0x1000, status)
        self.assertEqual(objects, {0x1010: 0x10})

    def test_partial_group_does_not_suppress_next_source(self):
        parsed = {0x1000: self.obj(0x18), 0x1020: self.obj(0x10)}
        _, objects, _ = build.select_source_objects(parsed, parsed, 0x1040, {})
        self.assertEqual(objects, {0x1000: 0x18, 0x1020: 0x10})

    def test_out_of_image_group_is_rejected_without_hiding_children(self):
        parsed = {0x1000: self.obj(0x100), 0x1010: self.obj(0x10)}
        status, objects, _ = build.select_source_objects(parsed, parsed, 0x1040, {})
        self.assertIn("too long", status[0x1000])
        self.assertEqual(objects, {0x1010: 0x10})

    def test_rejected_symbols_do_not_leak_into_selected_undefined_set(self):
        parsed = {0x1000: self.obj(0x20), 0x1010: self.obj(0x10)}
        parsed[0x1000]["undefined"] = ["unknown"]
        parsed[0x1010]["undefined"] = ["known"]
        _, objects, undefined = build.select_source_objects(
            parsed, parsed, 0x1040, {}, resolve=lambda s: 0x2000 if s == "known" else None)
        self.assertEqual(objects, {0x1010: 0x10})
        self.assertEqual(undefined, {"known"})


if __name__ == "__main__":
    unittest.main()
