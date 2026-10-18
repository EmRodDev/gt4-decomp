# Closed continuation checkpoint, 2026-10-17

This checkpoint ends the current work session. The source branch is
`codex/control-voice-init-2026-10-17`. Both Luna workers stopped after their
last foreground judge and saved their handoffs. No worker, compiler or
continuation is intentionally left running. Resume in a new branch in a
new session; the user wants `/goal` active for sustained work.

## Upstream synchronization

Upstream integrated our preceding six-function lookup/MPEG batch by merging
the pushed branch, then recovered the two later parameter/ring functions
independently. Merge `1bc9dca9` preserved the owner's implementations at
`00554C10` and `005569B8`, including their chosen compiler profiles. All
upstream sources, headers and tools were retained. The attempts diary kept
the upstream contents followed by 14 earlier local-only entries.

Upstream was refreshed again before closing. Revision `80b81d10` includes
six more CPU-tool closings after `fba1cd9c`, including previously difficult
`0055C9A0` and `0055F6A0`. Those implementations are retained too. None of
the four new functions below overlaps that update. Historical local proofs
in `library-lookups-and-headers.md` and
`streaming-parameters-and-ring-accounting.md` describe their named source
commits, not the new contribution count against the latest upstream.

## Reviewed source additions

| Address | Behavior and evidence |
| --- | --- |
| `00563298` | Issues IPU FDEC with an eight-bit shift through a volatile 32-bit MMIO store, then the original single `sync`. The SDK C compiler matches; no extra decoder wait was added. |
| `0055ECC8` | Clears the shared volatile worker flag, then forwards `D_00873EC0` to `00578908`. `0055EC60` sets the same flag and `0055EB50` reads it; the helper's broader control/cleanup semantics remain provisional. |
| `00603848` | Rejects negative or out-of-range indices; otherwise reads the first word of an eight-byte entry. Count is at list `+8`, entries at `+0x10`. |
| `006039C8` | Related checked lookup with count at `+4`; returns the second word of an eight-byte entry, at `+0x14 + index*8`. |

The list accessors retain explicit byte displacement after named partial
headers. A flexible-entry-array cleanup missed one `addu` operand order;
that unmatched rewrite was not substituted. The admitted code documents
the eight-byte stride, selected word and unknown header fields. Valid
allocations and non-null lists for nonnegative indices remain caller
responsibilities, as in the original; no new checks change the behavior.

A native ASan/UBSan harness compiled the actual three non-MMIO sources.
It checks negative indices before any owner dereference, empty lists,
index equal to count, three entries with distinct first/second words,
eight-byte stride and clearing the shared flag before the control call.
The MMIO helper is verified by the original compiler and complete build;
its console-only barrier is not replaced for host testing.

## Excluded destructor

`00614F98` produced an individual opcode MATCH using the full licensed
libio context of a sibling destructor. Object inspection still found
unmapped `IStreamDerived`/`ios`/`istream` virtual-table references and
`__builtin_vec_delete`. An opcode match cannot prove their final addresses.
The candidate was removed from `src/` and is not counted as recovered or
linked by this PR. Its libio notices remain in the ignored scratch draft.
A future attempt must establish the real class/table mappings and correct
the inherited template's misleading function annotation before admission.
No synthetic table mapping or judge exception was introduced.

## Deferred work and local handoff

The stream queue processed eight distinct addresses: two admitted matches
and six deferrals. Its remaining queue had 69 entries. The SDK/runtime queue
processed eight terminal addresses: three opcode matches (one excluded
above) and five deferrals. `005725A8` had one judged candidate when stopped;
101 other addresses remained. These are historical queue counts, not a
promise that the addresses are still unmatched upstream.

| Address | Closest result from this pass | Next useful investigation |
| --- | --- | --- |
| `005599F8` | 6/7 different | Tiny accessor register/address selection; retain older evidence. |
| `0055CF88` | 6/7 different | Typed two-word input and byte destination; no source admitted. |
| `00555290` | 2 instructions different | Helper/synchronization callback return scheduling. |
| `00554A58` | 93/99 different | Recover ring-allocation branches and header layout before tuning. |
| `00564368` | 83/84 different | Recheck decoder mode/output model; older drafts may be better. |
| `00563F98` | 161/162 different | Earlier c3 diary reports 40 differences; use that evidence first. |
| `00571BE0` | 69/98 different | SDK path parser and capacity/period rules; original full diff logs from the first pass were not retained. |
| `00603400` | 2 instructions different | Low-16-bit widening and register-width behavior. |
| `00571D60` | 17/30 different | SDK initializer constant allocation and field-store scheduling. |
| `0056BD48` | 127/191 different | Establish interpolation/buffer layout and callback signature. |
| `00572738` | 113/126 different | Allocator state and adjacent-free-block model. |
| `005725A8` | 99/104 different, one try | Partial typed allocator draft; the session ended before its normal budget. |

All distinct judged hypotheses and the destructor exclusion are recorded
in `knowledge/attempts.jsonl`. The three uncommitted generic `giveup`
summary lines emitted by a worker were replaced by reviewed per-hypothesis
records; no committed diary history was removed. One duplicate record
pointing to the same candidate/log was deduplicated. The first SDK path
parser pass retained only result summaries, explicitly labeled in its
notes; later workers retained full transcripts. No missing transcript was
invented or rejudged merely to manufacture a historical log.

Local scratch (ignored by Git, not guaranteed in a replacement workspace):

- `build/swarm/luna-stream-long/`: original stream candidates and records.
- `build/swarm/luna-sdk-long/`: original SDK/runtime candidates and records.
- `build/swarm/luna-stream-resume/handoff.md`: consolidated stream handoff.
- `build/swarm/luna-sdk-resume/handoff.md`: consolidated SDK/runtime handoff.
- `build/swarm/root-review/closure-reviewed-records.json`: reviewed judge ledger.
- `build/swarm/root-review/00614f98-unlinked-libio.cpp`: excluded licensed draft.

## Resume procedure

1. Start the next session with `/goal` active as requested by the user.
   Fetch upstream and branch from the latest integrated state. If this PR is
   still open, reserve its four addresses and do independent work rather
   than accidentally recovering them again. Prefer the
   owner's version on source overlap; do not revive already integrated drafts.
2. Read AGENTS.md and the project skill. Refresh `upstream_overlap.py --units`
   and the work queue before assigning targets; check addresses, not filenames.
   Keep to our coordinated stream/SDK/audio/MPEG areas.
3. Start fresh Luna workers with separate scratch directories and disjoint
   address queues. Use at most two compiler jobs total. Before each target,
   read the diary, kept drafts, actual assembly and caller/callee evidence.
4. Give Luna sustained batches, with the documented per-function budgets.
   Defer isolated failures and advance; return a substantial shared blocker
   with evidence. The primary reviews and validates instead of automatically
   spending a new implementation round on every deferral.
5. Require immutable candidates, real raw judge logs and immediate ledger
   updates. Count distinct admitted addresses, not repeated MATCH messages.
   Verify execution through fresh progress, not a sidebar/backend status alone.
6. Before publication: semantic/readability review, rejudge any cleanup,
   append reviewed attempts, organize sources, run relevant tests, and prove
   a clean non-partial full link with each new function exactly `linked`.
   Refresh upstream once more and update the report/README from that proof.

## Complete-build proof

Clean source commit `332dd2ac1d78c1fe95d83df6de25760eb76b8c6b` passed the standard
non-partial `tools/build.py --jobs 2` build at `2026-10-17T20:57:23Z`. Each
new source has exact status `linked`:

| Address | Verified linked bytes |
| --- | ---: |
| `0055ECC8` | 44 |
| `00563298` | 32 |
| `00603848` | 44 |
| `006039C8` | 44 |

The four additions supply **164 linked code bytes** relative to
upstream `80b81d10c73f7543bc228bfbef6be634615414ce`. The complete build contains
29,428 sources, 4,294,824 linked code bytes and 56,576 verified source
data bytes. No upstream source was modified or removed; the source delta
is exactly these four additions. There are zero orphan and duplicate
sources. Existing upstream sources that cannot be placed still use the
standard original-byte fallback; this proof does not relabel those as
linked. Both original loaded-segment hashes are preserved:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

All 85 repository tests, individual cleanup checks, native sanitizer
fixtures, assembly policy and source organization checks passed. README
progress was regenerated from this full proof. The proof log and checked
summary remain locally at `build/swarm/root-review/closure-full-build.log`
and `build/swarm/root-review/closure-proof.json`. No assets or binaries
are included in the contribution.
