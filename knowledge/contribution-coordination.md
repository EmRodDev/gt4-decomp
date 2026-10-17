# Library contribution coordination, 2026-10-16

PR #18: runtime/C/XML/STL blocks. PR #19 by Ganitzsh: 125 stream/runtime
sources, head `cdca5f5bdd484af2565f925bff80e02380b378ce` at review time.

Comparison is by resolved function address, including whole functions inside
verified source groups, rather than by pathname. Generic-to-real-name renames
hide several overlaps in a filename-only diff.

## Already covered by the published #18 checkpoint

| Address | Source supplied by #18 |
|---|---|
| `005BCF00` | `old_find_exception_handler.c`, first body of a consecutive group |
| `005BCFD0` | subsequent body in the same `005BCF00` group |
| `005BDCD8` | `fpmul.c` |
| `005BE5D8` | `fde_merge.c`, first body of a consecutive group |
| `005BEF80` | `frame_init.c` |
| `005BF3A0` | `decode_stack_op.c` |
| `0059AF50` | `_IO_file_attach`, inside the complete `0059AC68` fileops group |
| `0059B158` | `_IO_file_underflow`, inside the same fileops group |
| `00597A70` | inside the `005978E8` floatconv group |
| `00598228` | inside the same floatconv group |

All ten addresses are covered by the checkpoint's verified complete link.
Dropping the duplicate standalone entries from #19 preserves #18's actual
preceding-body context and source-group integration. The other 115 addresses
of #19 remain separate from that published checkpoint. Its green CI does not
replace the combined-tree binary proof after integration.

## Later unpublished work deferred to #19

The local sorting search subsequently recovered `005F3F28`, `005F41E8`,
`005F42E0`, `005F4460` and `005F4538`, which #19 also supplies. These five
local, unpublished source files were moved to ignored scratch storage and
removed from the next #18 source checkpoint. #19 owns those contributions;
there is no request for its author to repeat them.

## Additional unpublished library matches

The contributor also offered 16 GCC-runtime and 17 newlib/possible-DJ
functions. If further material is volunteered, use it to identify uncovered
functions and preserve the applicable public notices. The main extraction
pipeline can handle integration; do not assign follow-up work to the contributor.
Any public reply must first be reviewed and approved by the repository owner.

For the 53 MPEG candidates, use the separate extraction and per-file notice
review described in THIRD_PARTY.md. No decoder match is claimed here.

The resolved 125-address reservation is retained in [contribution-claims.json](contribution-claims.json). Check and refresh that pinned manifest before assigning further library targets; a file-name comparison is insufficient. The local sorting scan excludes those addresses for subsequent batches.

## Integrated checkpoint

PRs #17 and #19 are included by merge commits in the integration branch, preserving contributor history. The ten standalone overlap entries listed above are removed here because the verified #18 groups already provide those addresses. The five previously deferred sorting sources are supplied by #19.

Four additional PR #17 XML overlaps (`004DDA88`, `004DE118`, `004E1A10`, `004E20A0`) retain the already validated #18 C extraction sources; the corresponding standalone C++ files are omitted from the combined tree.


# Work division, 2026-10-17

Why: on 2026-10-17 the owner's matching workers and a contributor's branch
(`moesuito:codex/control-voice-init-2026-10-17`) closed the same six functions in `unit_005547E8`
(`00556390`, `0055F3E8`, `005637A8`, `005638B0`, `005639B8`, `00563A88`) on the same day. The
contributor's versions were kept: they read better (named constants and comments) and arrive with a
complete-build proof. The owner's flat copies were set aside, not committed.

Who works where (from `tools/upstream_overlap.py --units`, branches pushed in the last 7 days):

| Contributor | Area | Units |
|---|---|---|
| moesuito | stream / SDK / audio runtime / MPEG | `unit_005547E8`, `unit_005676B0`, `unit_005FF878` |
| Ganitzsh | game code: race, engine, adhoc, gamedata, UI, network graphics | `unit_00378778`, `unit_003E20A8`, `unit_00321330`, `unit_00364818`, `unit_003CCAE0`, `unit_00408DB8`, `unit_00101400`, `unit_00494578` (VU0 / GIF helpers) |
| owner's workers | newlib / libm, libgcc, SDK glue below `0x57A128`, leftover game code | `unit_0059BE80`, `unit_0057A128`, `unit_003F7150`, `unit_001C4BE0`, `unit_005C9AE0` |

Rules:

1. Before leasing an area to a worker, run `python tools/upstream_overlap.py --units` and keep the
   worker off the units and addresses it lists for a contributor. `--check ADDR,ADDR` says which of
   some addresses someone else already holds.
2. When both sides close the same function, keep the contributor's source if it passes `match.py
   check` in the merged tree and reads at least as well; remove the other copy before the build
   (a duplicated source fails the build).
3. Merge a contributor's pushed commits by full branch, not by the PR head seen at review time: the
   second commit of PR #26 (16 functions) was pushed after the first merge and was missed until
   the branches were compared on 2026-10-17.
