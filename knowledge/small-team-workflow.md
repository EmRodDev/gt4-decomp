# Small-team matching workflow

## Baseline and roles

Starting integration: `b85e4649f` (PRs #17, #18 and #19 merged).
Generated baseline: 29,023 / 30,962 matched functions; 4,193,680 matched code
bytes; 4,146,952 linked code bytes. Count only subsequent, independently verified
gains, and report bytes alongside functions.

Use two matcher workers and one lead. Each worker compiles one candidate at a
time. The lead does not run compiler searches or full builds while either worker
is compiling. Keep at least 4 GB available RAM. Do not launch detached processes.

## Choose and lease work

1. Refresh `tools/families.py --min-size 64 --level skeleton --top 12`, then
   `tools/work_queue.py --top 20`. Also generate a near-family map with
   `tools/families.py --min-size 64 --level near --json build/near-families.json`.
   Prioritize unmatched members with a solved sibling in that map. Similarity
   alone does not establish a solution; read the family diary before assigning
   a representative.
2. Prefer reusable game-code units, close retained drafts, and families with a
   clear source hypothesis. The initial large static-init family is already
   documented as a scheduling residual; do not repeat its failed flags search.
3. Lease separate units using `tools/swarm.py assign WORKER`. Check the manifest
   before dispatch: exclude existing sources, contributor work, original-assembly
   fragments, and work reserved in the user's primary checkout. In particular,
   do not target 0041BAC0, 004A7D38, 00580928, 0058D0A8, 005F7538, 005FA350 or
   0060B548 without reconciling that checkout first.
4. Unpublished MSSG MPEG and other third-party candidates need their provenance
   resolved before source inclusion; a high queue rank is not permission to
   bypass that review.

## Worker loop

Read `AGENTS.md`, the project skill and `swarm.py rules`. For each leased target,
use `swarm.py prompt ADDR`, including its attempt history and best retained draft.
Try a specific, new source hypothesis through `swarm.py try`; only MATCH may be
saved into src/. Use six candidate attempts per target in this first round.
After three attempts stuck purely on allocation/scheduling, retain the closest
natural draft and use `swarm.py giveup` with the precise residual. Never restart
from scratch when a closer, valid draft is available. Do not use nosched1,
register pinning, dead stores or multiple instructions disguised as one asm.

## Lead and mechanical finishing

Review reusable discoveries across siblings, then lease a further bounded batch
rather than leaving a worker indefinitely on one target. At a batch boundary,
stop worker compilation before running a mechanical finisher. Restrict context
and rewrite passes to named near misses and a small variant budget. Check the
attempt store before repeating a pass. Oracle certification is diagnostic only;
it cannot replace the unchanged judge. No unbounded permuter run in this loop.

The initial local certified-draft queue was empty. Contributor draft caches are
not implied by the presence of the tools; build our own retained-draft queue.

## Integration gate

Review every saved source and provenance, rejudge changed sources, organize with
the project tool and run policy checks. Run one full build with two compiler jobs
and require exact .text/.data plus actual source/group linkage. Run the existing
regression suite and CI checks when validating implementation, as authorized by
the owner. Generate progress with report.py/update_readme.py; never hand-edit
counts. Preserve useful failed drafts and recorded hypotheses for the next round.

No public comments or replies without the owner's review and approval of the
exact text. Do not assign follow-up work to volunteer contributors.

## Initial batches

- `duo-race`: network unit 00494578, targets 00494780, 004969B0, 00497020,
  00497838, 00498B28, 00498F88.
- `duo-network`: DynamicsConductorLicense unit 003F7150, targets 003F7CA8,
  003F7EA8, 003F8D70, 003F9340, 003FA508, 003FAD78.

Worker names are allocation identifiers; the unit and target addresses above
are authoritative.

## First-round selection adjustment

The default unit assignment selected many historical register/scheduling
residuals whose best drafts were not present locally. Stop that reconstruction
path after bounded probes. The lead identified the four singleton callbacks
005D4C60/005D9FA8/005DBF48/005DC4F8 and an existing solved caller as a source
reference. All four matched on their first candidate. Subsequent batches now
prefer explicit solved-sibling pairs over an address-ordered exhausted unit.
The other worker moved to eight smaller network targets; no third matcher was
started.

## Reviewed first checkpoint

Nine new sources pass the unchanged judge after organization and formatting.
The tenth apparent match (005D80D8) was rejected during lead review: an inherited
unused local array/store forced the frame layout. Removing it changes 20/57
instructions; retain the rejected draft only in scratch until a genuine
iterator/RAII temporary explains the original stack store.

The network worker retained unresolved drafts rather than repeatedly reconstruct
missing historical work. The closest new C draft, 00498AE0, has one aligned
residual/four positional rows. A measured default-profile probe and five bounded
rewrite variants produced no improvement; no long permutation search followed.

Accepted addresses: 005605B0, 00560690, 005CCF08, 005D4C60, 005D9FA8,
005CB230, 005DBF48, 005DC4F8 and 00602060. Exact linkage and aggregate
progress are established by the full-build report, not the worker byte estimates
(which include inventory padding).
