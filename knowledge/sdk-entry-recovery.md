# SDK pointer entry points and alarm lifecycle

Five routines recovered after `d9ead6d9`, using the existing SDK 2.9 compiler
profile. All are complete functions with ordinary C control flow and no assembly.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `0058E738` | Submit scalar asynchronous operation 10 | 188 |
| `0058E408` | Submit bounded string operation 12 with callback output | 320 |
| `0058D6F0` | Drain pending library operation and delete semaphores | 88 |
| `005B8ED8` | Dispatch alarm callback and recycle its record on zero result | 92 |
| `005B9158` | Validate alarm handle, release timer and recycle record | 168 |
| Total | | 856 |

## Inventory and entry points

The previous `build/functions.csv` was a call-target-only inventory. The existing
`tools/inventory.py` rebuilds it from the existing splat split, including pointer
entry points: 31,164 starts, with 30,962 targets after the configured assembly
exclusions. Its backup is `build/functions_jal.csv`. No new discovery algorithm,
judge change or function-boundary override was needed. Inventory sizes include
padding; the byte counts above use the actual compiled bodies.

`0058E738` is the recovered operation-3 wrapper's scalar sibling, with operation
10 in both RPC submission and pending-state publication. Its callback
`0058D748` signals the completion semaphore. Successful submission retains the
library semaphore until the completion consumer releases it. Failures preserve
the existing -100, -200 and -91 return paths.

`0058E408` rejects null/empty input after acquiring the library semaphore, with
unlock and -210 on that path. It copies at most 1023 input bytes into a 1024-byte
packet text field and terminates it. The packet also carries a separate DMA
response buffer, flushed before submission. Reviewed callback `0058E378` copies
the uncached response to the caller's optional output and signals completion.
The caller must retain that output until completion. Operation meanings and
partial packet layouts remain provisional; numeric command identities are exact.

`0058D6F0` calls the completion consumer `0058DF18` in blocking mode before deleting
the library semaphore, setting its handle to -1, and deleting the completion
semaphore. It returns 1 even when the library semaphore was already negative.
The consumer was reviewed but remains unrecovered.

## Alarm record lifecycle

Both alarm routines reuse the provisional 16-byte layout established by
`005B8F38`: next link, volatile timer handle, callback and callback argument.
The free-list head is shared and volatile. The dispatcher forwards the encoded
handle, two native timer register values and the saved user argument. A nonzero
callback result is returned unchanged; zero recycles the record, clears its timer
and returns -1. The exact original callback typedef remains unproven; the
64-bit register view agrees with the allocator and timer setter. This type
model closes the previously recorded four-row dispatcher epilogue residual.

Cancellation decodes the record address from the handle, excludes interrupts,
and rejects a negative handle or mismatching low-byte generation. Success calls
timer release `005B8628`, publishes the record back to the free list, fills its
link, clears the timer and conditionally restores interrupts. The timer release
wrapper and underlying `005B8588` were reviewed to confirm handle validation and
pool return. Original ordering and error 0x80008002 are preserved.

## Verification

All five pass `swarm.py try`, organized `match.py check-many` and `asm_policy.py`.
The actual decomp.wtf linker matches each entire body and rejects an instruction
mutation in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  0058e738:bc 0058e408:140 005b8ed8:5c 005b9158:a8 0058d6f0:58
python tools/build.py --jobs 2
```

Lengths are hexadecimal. Source hashes and batch proof are saved locally in
`build/sdk-entry-sources.json` and `build/sdk-entry-proof.json`.

The complete build at `2026-10-18T09:09:46Z` links all five new functions
from C: 29,187 linked sources, 4,309,152 source instruction bytes (80.70% of
`.text`). Both segment hashes remain exact: `.text`
`28422e7e20a6298224294255355487b9a22cef31`, `.data`
`c28c833f9716467545bf362f321e9acc876c3603`. Original assembly fallback still supplies
unrecovered code; this remains a partial decompilation.

## Deferred work

`0058DF18` now has a readable model only one instruction away: the compiler emits
`srl` sign-bit extraction where the original uses `slti`. Native-width syscall
return/local variants worsen it, and a wider zero literal is unchanged. Four
hypotheses are recorded; the closest draft is `build/swarm/codex/0058df18_best.c`.
It is not admitted or included in the recovered-byte count. `0058DBD8` and
`005B8DF8` were inspected; their earlier register-allocation and assembler-hazard
notes supplied no new easy hypothesis.
