# Synchronized FIFO and request-pool operations

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

The first Luna worker recovered these four functions, and the coordinating
session reviewed their semantics and requested pointer-prototype and layout
corrections. Each final candidate passed the unchanged `match.py check` judge
with 28 instructions. Every judged hypothesis, including rejected drafts, is
recorded in `knowledge/attempts.jsonl`. Individual matches must still survive
the full link before being counted as new source coverage.

## Protected request containers

`00559378` and `00559548` visit two `0x18`-byte request slots. Each non-null
request is passed to `0055D688(request, 0)` and its slot is cleared. The former
also clears the enclosing `0x58`-byte pool entry's state at `+0x54`; the latter
returns the entry pointer without that state write. `0055D688` updates request
flags. It does not directly free the request, so these methods do not invent a
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
