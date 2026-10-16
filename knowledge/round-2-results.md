# Matching round 2, 2026-10-16

Baseline: PR #20, master 5665a7395. Two workers, one compiler per worker,
with lead source review and complete binary proof before counting a gain.

## Reviewed matches

| Address | Reconstruction |
|---|---|
| 005BA770 | GCC signed remainder __moddi3, with original inline __negdi2 |
| 005A8288 | newlib __sbprintf using the floating vfprintf path |
| 005A8340 | newlib vfprintf wrapper calling 005A83B8 |
| 005A3858 | newlib fprintf calling 005A8340 |
| 00565DA0 | stream constructor, correctly sized 0x48-byte data member |
| 00566DF8 | sibling stream constructor, 0x10-byte data member |
| 0060FD48 | block transfer and conditional hardware interrupt enable |
| 002F3730 | hClass wrapper with distinct fallback strings and C++ linkage |

All eight pass the unchanged judge after cleanup and organization. This is
668 instructions / 2,672 bytes before the complete-link check. Inventory sizes
include padding; the full-build report remains authoritative for actual gains.
The initial plan's fscanf hypothesis for 005A3858 was disproved by its callee.

## Runtime provenance and reproduction

`python knowledge/recipes/runtime_round2.py` recreates the four runtime drafts
in ignored build/swarm/round2-runtime/reproduced. The recipe uses exact public
source trees outside the repository and already verified sibling preprocessing
contexts. All four reproduced files were byte-identical to the reviewed drafts
before organization. Original per-file notices are retained, including the
complete original fprintf.c notice. No third-party licence is relabelled.

- GCC: public 2000-10-03 snapshot, gcc/libgcc2.c and existing __umoddi3 context.
  Select L_moddi3; keep the target's duplicate clz-table alias 006D2B28 separate
  from sibling aliases pointing at 006D2D28. Retain gcc-runtime notices/marker.
- newlib: public 1.9.0 source, verified stdio contexts and exact fprintf.c body.
  Keep floating wrapper mappings separate from integer-only vfiprintf mappings.
  The first fprintf extraction duplicated the stdarg context and did not compile;
  selecting the final builtin shim fixed it. Retain newlib notices/marker.

Public input SHA-256:

- gcc/libgcc2.c: `72e2a766cab25c96f394b8c2f19ca135758155a8ac9752954559b7db8a9b90fe`
- newlib/libc/stdio/fprintf.c: `663413fd2d578b1541733a2351969ff753b2019c7feedbc1119d5d43b0b1a521`

The 00565DA0 cleanup removes inherited unused shape members and describes the
actual cleared buffer size. Unlike the rejected first-round 005D80D8 draft,
none of the accepted sources requires a dead store to force stack layout.
