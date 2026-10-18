# SDK polling, RPC and timer recovery

Six functions recovered after `da9469c4`, using the existing SDK 2.9 compiler
profile and neighboring callers/callees as layout evidence. Address-based names
and local partial structures remain provisional.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `0058BCE8` | Bind an RPC client until its server pointer is present, delaying between retries | 144 |
| `0058C088` | Shut down both channels and clear the initialized flag | 136 |
| `0058C690` | Submit operation 6 to close a channel, translate distinguished errors, set state 2 on success | 172 |
| `0058D818` | Submit synchronous operation 21 and return the server's result after releasing the semaphore | 192 |
| `0058DA38` | Submit asynchronous operation 3, release the submission lock on failure, mark operation pending on success | 188 |
| `005B8728` | Resume a generation-checked timer, record its start time and update scheduling when linked | 172 |
| Total | | 1,004 |

## Source review

The binding routine reads the server pointer at client offset `0x24`, as do the
other RPC wrappers. It ignores the bind call's return and retries until that
pointer becomes nonzero. A volatile countdown preserves the original polling
delay. Placing the bind call in the while condition gives the original initial
branch around the delay and the shared polling tail without explicit jumps.

Channel records are 40 bytes. Existing `0058C740` supplies status and initializes
the local state at offset `0x04`; the recovered shutdown and close routines use
the same stride and field. Close returns the same unavailable error for status
zero and server result `-1`. Result `-2` and a transport failure have distinct
errors. Shutdown preserves the original behavior of ignoring individual stop
and close errors before clearing the global initialized flag.

Both operation wrappers use the same 48-byte command buffer. Operation 21
writes its second word and uses synchronous RPC mode; operation 3 writes its
first word and installs callback `0058D748`. Reviewing that callback establishes
that it signals the **separate completion semaphore** at `00657AF8`. The
submission lock is at `00657AF4`: successful asynchronous submission retains
it for later completion handling. The callback itself does not release it.

The timer handle encodes a 64-byte-aligned object address above its ten-bit
generation field. The routine rejects negative/stale handles and the current
timer, returns 1 for an already-running timer and 0 after resumption. It reads
the 64-bit clock at `005B8400`, stores it at object offset `0x10`, and sets flag
1. Flag 2 triggers sorted-list insertion through `005B8098` and hardware timer
rescheduling through `005B7F08`.

Shared timer-pool state is volatile, consistent with existing `005B8678`.
Keeping timer objects ordinary while making the shared state volatile also
reproduces the original explicit pool-base address calculation. No register
annotations, assembly blocks or synthetic stores were introduced.

## Verification

All six pass `swarm.py try`, `match.py check-many` after organization, and the
source assembly policy. The real decomp.wtf linker independently accepts every
function byte-for-byte and rejects a changed instruction in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  0058bce8:90 0058c088:88 0058c690:ac \
  0058d818:c0 0058da38:bc 005b8728:ac
python tools/build.py --jobs 2
```

The explicit lengths are hexadecimal and exclude alignment padding. They do
not alter the GT4 judge or replace full-image verification.

The complete build passed at `2026-10-18T04:40:15Z` on the changed tree
based on `da9469c4`: 29,464 sources, 29,165 source-linked functions,
and 4,303,636 instruction bytes linked from source. All six new
functions are `linked`, adding 1,004 bytes. Both original segment hashes match:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

Unrecovered code retains the normal assembly/raw-byte fallbacks. The entire
game is not yet decompiled. Original game data, BIOS and generated binaries
are excluded from this contribution.

## Deferred work

The shared channel transport `0058BD78` has the correct packet layout, call
signature and reply copy, but the final packet store and RPC-mode conversion
remain exchanged after four source hypotheses. It was not admitted.

Applying volatile shared-state evidence to `005B8588` fixes its optional
unlink branch but changes the later free-list publication schedule. Qualifying
only its current-handle field retains the earlier two-row residual. Those
findings and local drafts are recorded for further work; no release source was
admitted.
