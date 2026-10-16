# Round 2: bounded two-worker batch

## Starting point

PR #20 is merged; assign this batch from the resulting master checkpoint. Baseline: 29,032 matched functions,
4,195,700 matched code bytes, 4,148,972 linked code bytes. Keep this round
separate from the first checkpoint. Preparation is not a claim of new matches.

## Worker A: public runtime extraction (2,072 inventory bytes)

1. **005BA770 (1,680 bytes)**: compare public GCC runtime source with solved
   __umoddi3 at 005BB380, supplied by PR #19. The target diary has no attempts.
   Establish the routine name/return semantics from assembly first; do not assume
   that all near-family members are interchangeable. Use the existing public GCC
   staging/libmatch pipeline, original notices and gcc-runtime licence marker.
2. **005A8288 (184)**: __sbprintf-like sibling of the verified public extraction
   at 005A7518. Compare call destinations and use the exact newlib 1.9.0 source.
3. **005A8340 (120)**: vfprintf-like sibling of 005A75D0. Preserve the selected
   public source's macros, compiler context and notices.
4. **005A3858 (88)**: fscanf-like sibling of 005A36F8. A previous cross-game
   adaptation differed; the new hypothesis is the locally verified public-source
   extraction rather than retrying that adaptation.

Public sources and per-file notices must be retained. Do not copy a sibling and
leave its original address/provenance description unchanged. Do not import the
unpublished MPEG block or any SDK material as part of this batch.

## Worker B: solved game-code siblings (616 inventory bytes)

1. **00565DA0 (176)** and **00566DF8 (176)**: compare with solved 005527D8 at
   src/libstream/unit_0054DF90/func_005527D8.cpp. Earlier twin adaptations left
   about 25 rows; use the actual local C++ sibling and inspect ctor/dtor context.
2. **0060FD48 (168)**: compare with solved 00548178 at
   src/network/unit_00494578/func_00548178.cpp. Only an old model-drafter failure
   is recorded. Verify actual global block types/calls, and retain a genuine
   single hardware instruction only if required by the original.
3. **002F3730 (96)**: compare with 00306848 at
   src/adhoc/unit_00305CF8/func_00306848.cpp. Inspect linkage and default-string
   globals. It belongs to an exact-copy group, but prove the target independently
   before considering any duplicate-source integration.

## Budgets and gate

Two workers only, one compiler per worker. Lead runs no competing build/search.
Four source hypotheses per small target; at most six for the large GCC target.
Stop earlier when the only residual is a previously exhausted compiler decision
and there is no new source hypothesis. Preserve the closest valid draft.
A single bounded finisher pass can follow after both workers stop.

Reject dead stores and unused temporaries that exist only to force stack layout,
including the rejected 005D80D8 form from round 1. Exclude the user's primary
checkout targets 0041BAC0,004A7D38,00580928,0058D0A8,005F7538,005FA350,0060B548.
The large static-init family, 004DEDC8 and the previous network allocation
residuals are deferred unless a new, documented hypothesis is available.

Lead reviews saved sources and notices, organizes, rejudges all changed sources,
runs the existing tests, and requires exact full .text/.data and actual linkage
before reporting a gain. Inventory byte totals above include padding and are
opportunity estimates, not promised recovered bytes. Release only this round's
leases at its end. No public comments without the owner's exact-text approval.
