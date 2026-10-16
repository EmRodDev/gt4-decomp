# Synchronization, voice selection, and playback operations

## FIFO types and behavior

RTTI helpers `00613070`, `006134C8`, and `00613C38` identify
`PDISTD::CSFifoBase`, `PDISTD::MTFifoBase`, and `PDISTD::FifoBase`.
The recovered single-element copy operations share this partial base layout:

| Offset | Field | Evidence |
| --- | --- | --- |
| `00` | write index | Used to address the destination in enqueue; advanced by `0057B410`. |
| `04` | read index | Used to address the source in dequeue; advanced by `0057B3B0`. |
| `08` | element count | Increased/decreased by those two core operations. |
| `0C` | storage pointer | Base address passed to the copy routine. |
| `10` | element size in bytes | Multiplies the slot index and supplies the copy length. |
| `14` | capacity | Used to wrap the indices in the core operations. |
| `18` | unknown | Preserved explicitly; these methods do not establish its role. |
| `1C` | synchronization state | Interrupt section for CS; recursive mutex for MT. |

The source views describe the accessed prefix. They do not establish a complete
class layout or a public API for constructing these objects.

| Function | Type | Operation |
| --- | --- | --- |
| `006132C0` | CS | Copy one read slot into the caller's output, then consume one element. |
| `00613388` | CS | Copy the caller's input into one write slot, then produce one element. |
| `00613710` | MT | Same dequeue operation under the recursive mutex. |
| `006137D8` | MT | Same enqueue operation under the recursive mutex. |

These methods do not check capacity or emptiness. Their callers must satisfy the
original preconditions; adding checks would change the recovered behavior.
`005A4724` is the byte-copy routine: its return value is the destination pointer,
and its parameters are destination, source, and unsigned byte count. The new
sources use pointer parameters rather than casts through integers.

## Two different synchronization mechanisms

`00576100` calls `005B72A8`, which reads the EE status register and disables
interrupts if enabled. The section stores a nesting depth and the previous
interrupt-enable state. `00576140` restores interrupts only when the outermost
section exits and interrupts were enabled on entry. Calling this a semaphore or
an ordinary thread mutex would obscure its behavior. FIFO methods use a scoped
interrupt guard so that both entry and exit are visible in one operation.

`00576788` and `005767C0` instead call `00576418` and `00576640`. Those routines
track the owning thread, recursive depth, and waiting threads, and invoke the
thread sleep/wake helpers. The MT FIFO therefore uses a scoped recursive mutex.
Its opaque `0x28`-byte state covers the offsets accessed by those routines;
the complete class layout remains unproved.

The core consume/produce helpers take an integer **element count** as their
second argument. Some older neighboring declarations use `void *` for that
argument; the recovered copy operations use the evidenced integer prototype.

## Matching and review

All four FIFO operations use `ee-gcc2.96-no-strict-aliasing`. Loading the storage
pointer, element size, and slot index into named locals in that order reproduces
the original scheduling without artificial stack writes or register constraints.
Consistent base and derived layout declarations keep the two synchronization
variants distinct across translation units.

Pointer-prototype and layout corrections preserve the match. Each final FIFO
candidate passed the unchanged `match.py check` judge with 28 instructions.
Every judged hypothesis, including rejected drafts, is
recorded in `knowledge/attempts.jsonl`. Individual matches must still survive
the full link before being counted as new source coverage.

## Protected voice containers

`00559378` and `00559548` visit two `0x18`-byte voice slots. Each non-null
voice is passed to `0055D688(voice, 0)` and its slot is cleared. The former
also clears the enclosing `0x58`-byte pool entry's state at `+0x54`; the latter
returns the entry pointer without that state write. `0055D688` updates voice
flags. It does not directly free the voice, so these methods do not invent a
delete/free operation or assign ownership to the unknown fields.

`0055C6E0` counts nodes whose **64-bit** flags intersect the supplied mask.
`0055C758` finds and unlinks the first such node, clears its next pointer,
writes `6` at `+0x30`, and obtains a fresh ID from `0055C520(node->owner)`.
No meaning beyond the observed numeric value is assigned to field `+0x30`.
Both the head-removal and interior-removal cases preserve the original list
behavior, including a null result when no node matches.

These methods all bracket their work with the global interrupt section at
`00655340`. Explicit entry/exit calls are sufficient for their single-exit
control flow. The new sources preserve unknown layout regions rather than
giving them speculative application-level names.

The canonical global at `006518C8` is `SDDRV::VoiceSystem::master_`, recovered
with high confidence in `config/gthd_globals.txt`. `0055C808` links nodes through
the same head at `+0x2AA8` and next pointer at `+0x0C`; `0055C520` generates IDs
from the counter at system offset `+0xA0`. This supports the provisional names
`VoiceListEntry` and `VoiceSystemListView`, replacing the initial request-list
names. The accessed fields do not establish whether the list owns its voices
or is specifically a free/pending list, so neither role is claimed.

## Channel selection and playback control

`0055CFE8` initializes a voice-selection filter, including the system pointer,
64-bit selection mask, comparison criteria, and enabled-constraint bits. The
callee `0055C9A0` synchronously scans 48 voice records of stride `0xE0` starting
at system offset `+0xA8` and applies callbacks to matching records. It does not
enqueue the filter for later use. A zero selection mask skips the traversal
and optional completion callback. The complete selector remains unmatched;
this behavior is established from its original instructions.

| Function | Recovered behavior |
| --- | --- |
| `0055B898` | Read one stream byte, update the current channel's value, then apply `0055CFD8` to voices selected by mask and channel. |
| `0055BBB0` | Set a channel's signed-byte toggle to zero or one; when it and the channel's active word are nonzero, apply `0055CF28` to matching voices. |
| `0055BDF0` | Stop an active embedded playback record, initialize playback with the supplied context/input/index, and store the new record state. |
| `0055CD18` | Apply a control-value pair to one bank, or to banks zero and one when the selector is two. |

The channel methods share identical partial layouts: 16 channel records begin
at owner offset `+0x68` with stride `0x1C`; their value, signed toggle, and active
word lie at record offsets `+7`, `+9`, and `+0x14`. Typed array indexing replaces
raw address arithmetic. Constraint bit `0x40` enables the channel criterion.
`0055B898` prepares that filter before interrupt entry; `0055BBB0` prepares its
criterion/constraint fields after entry. The sources preserve that timing.

The playback record is **embedded** at owner offset `+0x234`, rather than
referenced by a pointer stored there. Its context remains an opaque pointer
through the parameter, record, and initializer declaration. The unsigned index
comparison resets an index only when it is strictly greater than the input
word at `+4`; equality is preserved. The saved float's application-level
meaning remains unknown. These views do not claim a complete player layout.

`0055DDD8`, called by `0055CD18`, addresses two control banks with stride
`0x1D0`, sets a dirty bit, and writes a 16-bit pair. Argument words remain
32-bit in the wrapper; narrowing them in its prototype would add behavior
before the callee's own stores.

## Initial eight-function proof

The non-partial build of clean source commit
`8c7d081e998632edaf210264fda8dca07b516fbd` passed with `tools/build.py --jobs 2`.
All eight new functions have the exact status `linked`, with no orphan or
duplicate sources. They contribute **988 additional linked code bytes** over
upstream `ab5ca09f43e1380ead55cccb825d2a759aff3e08`.

| Segment | Rebuilt SHA-1, identical to the original |
| --- | --- |
| `.text` | `28422e7e20a6298224294255355487b9a22cef31` |
| `.data` | `c28c833f9716467545bf362f321e9acc876c3603` |

The build compiled 29,035 function sources and linked 4,153,104 code bytes;
55,106 data bytes came from verified source sections. The repository's 85 tests
passed. `tools/report.py` and `tools/update_readme.py` generated the progress
figures from that build; no percentages were edited by hand.

The nearby pool scans `005596F8` and `00559808` remain unmatched. Their bounded
attempts stopped at 9/37 and 11/39 differing instructions respectively. Their
remaining differences concern loop induction and scheduling; no candidate from
those attempts was admitted into `src/`.

## Combined twelve-function proof after upstream PR 23

Upstream merged PR 23 as `6e18ca3768811c5338401f42b6e13e619e502428`.
That code was merged into this branch before validating the expanded batch.
The upstream README was preserved during conflict resolution and subsequently
regenerated from the combined build; upstream diary revisions were preserved
and local records appended without replacing the author's entries.

The non-partial build of clean source commit
`95c50021f592507adc98ba0d4ba7a5d7cd6017ee` passed with
`tools/build.py --jobs 2`. All twelve new functions have status `linked`.
They supply **1,736 linked code bytes** beyond upstream PR 23: the original
eight contribute 988 bytes and the four channel/playback controls add 748.
The voice-layout naming changes preserve the earlier functions' instructions.

The rebuilt segment hashes remain exactly:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

The build covers 29,069 source files, 4,168,056 linked code bytes, and 55,106
verified source data bytes, with no orphan or duplicate sources. The 85 tests
and source-organization check passed. README figures were regenerated with
`tools/report.py` and `tools/update_readme.py` from this clean full build.

The core selector `0055C9A0` remains unmatched despite a readable reconstruction
reaching 2/106 differing instructions: a required-flags load and loop-counter
initialization are scheduled in the opposite order. Additional natural helper
and mask-type hypotheses did not close it. That candidate is excluded from
`src/`; its diary records distinguish algorithm recovery from a proven match.
