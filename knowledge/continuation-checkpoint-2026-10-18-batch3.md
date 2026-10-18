# GT4 decompilation continuation checkpoint — 2026-10-18 batch 3

## Result and stopping point

This batch closes with **9 new functions and 11,628 linked code bytes** relative to the selected upstream baseline. Each counted address has an individually rejudged source and exact `linked` status in the final complete-build report. The user requested the complete build and internal draft PR; this is the stopping point. The 100-function goal was a maximum, not a reason to include unverified or duplicate code.

The work was performed by Luna. The internal PR is **AWAITING SOL REVIEW**; Sol has not reviewed it.

## Baseline and proof revision

- Upstream baseline: `f7bb71e04d383c6c6483bde77dec30fd198041a0` (`upstream/master`, 2026-10-18).
- Working branch: `codex/luna-recovery-2026-10-18-batch3`.
- Clean source commit used by the proof: `57093e6709315aedc1d45182199442e6f8a94546`.
- Upstream PRs #28 and #29 were merged. No open upstream PR claimed any of the 13 candidate addresses when checked.
- `tools/upstream_overlap.py --days 30 --units` refreshed the claims manifest; all 13 candidate addresses were reported free by `--check`. Complete-build evidence and the repository's contribution notes still identified three candidates as already supplied by source groups in the selected upstream tree; those standalone copies were removed in favor of upstream.

## Newly verified sources

All rows below are direct `linked` entries in `build/full/report.json`; the sizes come from that report and sum to 11,628 bytes.

| Address | Source | Linked bytes | Isolated judge after organization |
|---|---|---:|---|
| `00596640` | `src/libstream/unit_005942D0/_IO_getline_info.c` | 428 | MATCH, 107 instructions |
| `005DFF68` | `src/runtime/unit_005DEC28/func_005DFF68.cpp` | 2,184 | MATCH, 546 instructions |
| `005E07F0` | `src/runtime/unit_005DEC28/func_005E07F0.cpp` | 1,376 | MATCH, 344 instructions |
| `005E0E70` | `src/runtime/unit_005DEC28/func_005E0E70.cpp` | 568 | MATCH, 142 instructions |
| `005E10A8` | `src/runtime/unit_005DEC28/func_005E10A8.cpp` | 2,112 | MATCH, 528 instructions |
| `005E18E8` | `src/runtime/unit_005DEC28/func_005E18E8.cpp` | 1,480 | MATCH, 370 instructions |
| `005E2100` | `src/runtime/unit_005DEC28/func_005E2100.cpp` | 1,904 | MATCH, 476 instructions |
| `005E2B48` | `src/runtime/unit_005DEC28/func_005E2B48.cpp` | 1,000 | MATCH, 250 instructions |
| `005E30E8` | `src/runtime/unit_005DEC28/func_005E30E8.cpp` | 576 | MATCH, 144 instructions |

The eight sorting functions share the observed 44-byte record and 0x54-byte comparator layouts. Scalar fields whose meanings are not established remain offset-named `unknown` fields. The comparator's vector and guarded `Vec4` assignment follow matched neighboring helpers and the retained SGI headers. The 107-instruction stream helper uses only the observed `IOFilePrefix` fields; it does not claim a complete `IO_FILE` layout. The library sources retain their public-source notices and `licence: libio` markers.

## Complete-build proof

The final build was non-partial and used the clean source commit above (`dirty: false`). The tool binaries came from the repository's ignored local tool cache, added to `PATH` and `LD_LIBRARY_PATH`; no system packages were installed.

```text
PATH=build/tool-cache/mips-binutils/root/usr/bin:$PATH \
LD_LIBRARY_PATH=build/tool-cache/mips-binutils/root/usr/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH \
python3 tools/build.py --jobs 2
.text OK  sha1 28422e7e20a6298224294255355487b9a22cef31
.data OK  sha1 c28c833f9716467545bf362f321e9acc876c3603
29,524 sources; 29,223 functions linked overall
orphan sources: 0; duplicate sources: 0
```

The complete report records 56,576 bytes placed from source in `.data`. It also reports unrelated pre-existing non-linked source candidates elsewhere in the repository; none of the nine counted addresses is among them. Final build generation time was `2026-10-18T23:32:38Z`.

Checks run successfully on the final source set:

- `python3 -m unittest discover -s tests -v` — 94 tests passed.
- `python3 tools/organize.py --check` — passed.
- `find src -type f \( -name '*.c' -o -name '*.cpp' \) -print0 | xargs -0 python3 tools/asm_policy.py` — passed.
- `git diff --check` — passed.
- `python3 tools/report.py` and `python3 tools/update_readme.py` — generated the local progress report and the README progress block from the final build proof.

## Candidates excluded after review

Three individual matches were removed because current upstream source groups already cover their addresses. The final report marks them `linked as part of` those upstream groups, and `knowledge/contribution-coordination.md` / `knowledge/c-runtime-units.md` describe the ownership and verified group context:

- `00597DD0` and `00598228` are covered by upstream `func_005978E8`'s float-conversion group. The group is already present at the baseline; the standalone candidates were duplicates in contribution, so upstream was retained.
- `0059AF50` (`_IO_file_attach`) is covered by the upstream file-operations group beginning at `0059AC68`; the standalone candidate was omitted in favor of that source.

`005D8510` individually matched (181 instructions), but the complete-build report from the diagnostic pass gave it `references unnamed-address symbols` for its generated `__uninitialized_copy_aux`, `__uninitialized_fill_n_aux`, and `fill` helpers. It therefore was not verified at the original address and was removed from `src/`. Its candidate and transcript remain in ignored local scratch. It is not counted.

## Deferred work

These six independent targets did not meet the quality/match threshold in this pass. Best retained results and hypotheses are taken from the attempts diary; do not repeat them without new evidence.

| Address | Best retained result | What remains / next evidence needed |
|---|---|---|
| `00545FC0` | 16/16 different after 3 tries | A 32-word in-place bignum subtraction model and two loop/borrow rewrites still miss every instruction. Re-establish the exact borrow expression and compiler lowering before retrying. |
| `0058F780` | 154/163 different after 3 tries | Readable semaphore/RPC polling models still have large control-flow/register differences; try 1 also had wrong-address references to `0058F728` and `005B0750`. Recover those ABI/callee facts first. |
| `005B3ED8` | 98/106 different in retained try 2 | Bounded command-request copy and semaphore/result layout remain uncertain; the three retained attempts were recovered from local transcripts and were not rejudged in this batch. |
| `005830B0` | 38/92 different after 3 tries | A typed 20-byte request and real strings improved the result, but the retained extra null argument emits a stack store absent from the original. Revisit the call ABI before changing source shape. |
| `005B5698` | 116/170 different after 3 tries | Request/path model remains plausible; changing request-pointer order and byte signedness did not close the large code-generation difference. |
| `005E8E40` | 266/313 different after 3 tries | The SGI vector fill-insert operation and 36-byte four-string item model fit the target, but the frame/control-flow/helper output remains far off. Try 1 also had a prototype-order compile failure. |

`00597A70` had a one-instruction `bnez`/`bnel` residual after four total attempts, but is already covered by upstream's `005978E8` float-conversion group. It is not new batch work.

## Attempts, drafts, and local-only artifacts

The versioned diary contains 55 new rows covering 20 distinct attempted addresses, including failed hypotheses, compile failures, cleanup rejudges, and the outcomes used to exclude candidates. Candidate files were not overwritten. The current source organization was rejudged; raw outputs are in the ignored local directory below.

- `knowledge/attempts.jsonl` — versioned attempt ledger.
- `build/swarm/luna-primary/` — ignored candidate sources and retained judge logs for this batch; not guaranteed to survive a workspace replacement.
- `build/swarm/root-review/organize-rejudge/` — immutable snapshots and raw rejudge outputs for all 13 organized candidates; ignored and local-only.
- `build/swarm/root-review/first-full-report-before-exclusions.json` — diagnostic full-build report used to identify the three upstream-covered functions and the `005D8510` integration failure; ignored and local-only.
- `build/swarm/root-review/final-complete-build.log` — final complete-build transcript; ignored and local-only.
- `build/full/report.json`, `progress/report.json`, and `progress/report.meta.json` — generated local proof/report artifacts; ignored and local-only.

The README numbers were regenerated with the official report tools. Upstream advanced from b27d84c to f7bb71e0 after the source search; its only change was the region_compiler verdict handling, and the branch was rebased and fully rebuilt on f7bb71e0. The progress artifact branch was not updated: `tools/publish_progress.py` performs a force push, which this task explicitly forbids. The checked-in progress branch therefore still has its previous artifact until a maintainer publishes a new one through an allowed workflow.

## Publication handoff

The intended destination is `moesuito/gt4-decomp`, base branch `master`, with this working branch as the head. The fork's `master` was 23 commits behind upstream and had no divergent commits at the last check, so it can be fast-forwarded to the selected baseline before opening the draft PR. Do not push to `gustavocanepa/gt4-decomp` and do not merge the internal PR.

The PR description and this checkpoint must state **AWAITING SOL REVIEW**. No workers or compiler processes should remain running at closeout.
