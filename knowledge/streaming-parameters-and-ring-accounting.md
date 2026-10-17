# Streaming parameters and ring accounting

This continuation adds two library functions to the accumulated
`codex/control-voice-init-2026-10-17` branch. The six preceding additions
are documented in `library-lookups-and-headers.md`. No global header,
compiler profile or judge was changed.

## Packed parameter decoding: 005569B8

The input consists of byte pairs whose contributions are `(low << 2)`
and `(high << 9)`, combined with bitwise OR and truncated to 16 bits.
The inputs are not masked to seven bits; changing OR to addition also
changes behavior when the contributions overlap. The common fields at
`+0x10`, `+0x14` and `+0x18` sign-extend the first three decoded values
to 32 bits. The parser sets the format word at `+4` to 2 in every mode.

The mode at `+0` selects the remaining representation:

| Mode | Additional input | Destination |
| --- | --- | --- |
| 0 | Three pairs | Three signed 32-bit values, in reverse index order at `+0x24`, `+0x20`, `+0x1C` |
| 1 | Nine pairs | A signed 16-bit 3-by-3 matrix at `+0x1C`, filled one column at a time |
| Other | None | Existing variant fields and representation selector remain unchanged |

The provisional union expresses these overlapping layouts without raw
offset casts. Field names describe only observed representations; the
higher-level meaning of the common values and matrix is not established.
The unknown word at `+0x0C` is left untouched. The parser disables
interrupts through `005B72A8` and unconditionally enables them through
`005B72F8`, ignoring the returned prior state. This preserves retail behavior.
The caller supplies at least 12, 24 or 6 readable input bytes respectively;
there is no source-level length parameter or additional validation.

## Returning block bytes: 00554C10

When flag bit 0 at ring offset `+0x18` is set, the function walks a linked
list of byte-aligned block headers. Each header contains a payload length
at `+4` and a next pointer at `+8`. It adds the payload plus the 16-byte
header to the ring's free-byte counter at `+0x34` under disabled interrupts.
The packed structure models the original unaligned loads. The adjacent
`00554D60` source uses the same counter and header accounting.

After accounting, interrupts are enabled and `00554910` drains the pending
queue at `ring + 0x0C`. An empty list still performs this interrupt sequence
and queue drain. If flag bit 0 is clear, the function does nothing. It does
not itself traverse the pending queue or free the block list. Unknown ring
fields retain explicit offsets; pointer fields remain pointer-typed.

## Reviewed but deferred: 00555F68

The slot predicate `00556210` receives the original slot index. The command
allocator/selector `005560C8` instead receives command type 5 for slot zero
or 6 for a nonzero slot. Earlier worker drafts confused these arguments
and the offsets of optional writes; those models were rejected.

The corrected draft uses a `0x114`-byte indexed slot, a 64-byte payload at
slot offset `+0xCC`, and a mutable subrecord at `+0xD8`. It copies the payload
by ordinary aggregate assignment into command offset `+8`, preserving the
original unaligned copy sequence without manual instruction-sized chunks.
The command's first word is written after the copy. A structured subrecord reduced
the residual to four instructions: selector setup scheduling and the order
of two stores of the same value. Chained assignment, the library aliasing
profile and C89 did not close it. The draft remains outside `src/`; no
artificial dependency or forced register was introduced.

## Validation

An AddressSanitizer/UndefinedBehaviorSanitizer host harness compiled the
actual two recovered sources. Packed-parameter fixtures exercise negative
values, truncation, overlapping byte contributions, column order, untouched
unknown/variant bytes and exact-size input allocations for all modes.
Ring fixtures cover nonempty/empty block lists, a disabled accounting flag,
and interrupt/queue-drain call order. Native pointer size differs from the
console's; ring host fixtures check control flow and use the native header
size. The console's offsets and 16-byte header are verified by the exact
compiler and complete executable comparison.

The clean source commit `373a112c90fc3f4d41cf12cd464a9c7c29fda884` passed
`tools/build.py --jobs 2` in a full, non-partial build. Both additions have
exact status `linked`: `005569B8` supplies 508 bytes and `00554C10` supplies
144 bytes, totaling **652 new linked bytes**. The accumulated branch now adds
**eight functions / 1,604 linked bytes** over upstream `0b54ed5c`, in
addition to the previously reviewed typed registration-link wrapper.

The full build covers 29,194 sources and 4,242,880 linked code bytes,
with 56,161 verified source data bytes. All 107 owner additions and
all 22 functions integrated from PRs 24/25 remain individually linked.
There are no orphan or duplicate sources. The original segment hashes
are preserved:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

All 85 repository tests passed, as did the sanitizer fixtures, assembly
policy and source organization checks. README progress was regenerated
from this proof. Upstream was refreshed before selection and consolidation
and remained at `0b54ed5c`.

Caller review also confirms the family context: `005568C0` accumulates
seven-bit bytes at `self + 0x128`, invokes `005569B8` on the accumulated
record and resets the write pointer. `00554F60` passes a block list to
`00554C10` after copying payload bytes; it records the copied length at
header `+0x0C`. Those callers remain outside this contribution's recovered
function count. No unsupported public library names are assigned.
