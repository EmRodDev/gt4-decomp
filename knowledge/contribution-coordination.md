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
