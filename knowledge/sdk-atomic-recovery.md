# SDK descriptor completion and atomic allocation

Three functions recovered after `56464d59`, using the existing SDK 2.9 profile.
They close a previously deferred RPC caller, an alarm allocation path, and the
shared heap-break update. Structure names and partial layouts are provisional.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `005B4880` | Submit descriptor operation 11, inspect uncached acceptance, wait for completion | 340 |
| `005B8F38` | Allocate an alarm record and timer, install callback, start timer, return encoded handle | 300 |
| `005AE3A0` | Adjust heap break atomically, enforce kernel upper limit and set ENOMEM on failure | 172 |
| Total | | 812 |

## Descriptor operation

The existing descriptor lookup `005B2348`, lock helpers and retry wrapper
`005B2258` establish the call interface. The retry call has ten arguments;
its ninth and tenth arguments occupy eight-byte stack slots at `sp+0` and
`sp+8`. The intervening word is padding, resolving the earlier suspected
missing-argument issue without adding an uninitialized parameter.

The request carries a completion semaphore, a pointer to a local result word,
the result size, the backend descriptor and the caller's output address.
Acceptance is read from the uncached alias of the shared RPC response after
submission. Keeping that RAM read ordinary allows the original load in the
unlock call's delay slot. The function preserves the original signed test of
the retry wrapper's return and its cleanup paths, including the unusual path
that waits/unlocks without deleting the semaphore.

## Alarm record

The free list supplies a 16-byte record holding a next pointer, timer handle,
callback and callback argument. The function disables interrupts, pops a record,
allocates a timer, installs the dispatcher and starts it. Allocation failure
returns the record to the list and clears its timer handle before restoring
interrupt state. Pool exhaustion and a null callback preserve their original
error values.

An inline `take_record` helper reproduces the separate pop/result checks.
The shared head and asynchronously cleared timer-handle field are volatile.
On rollback, the previous head is saved, then the new head is published and
the record's link/handle are filled while interrupts remain disabled. This
source lifetime and ordering reproduce the original without register pins.

Dispatcher `005B8ED8` forwards four argument registers to the user callback:
the encoded public handle, two timer values and the saved callback argument.
The source uses a provisional typed register view; exact original callback
typedef and timer-value meanings are unproven. Existing `005AED18` already
calls this allocator for alarm-backed semaphore delays. The dispatcher itself
remains unrecovered and is not counted.

## Heap break

The heap routine reads CPU status and, when needed, disables interrupts until
the status bit confirms that they are disabled. It computes the candidate
break, queries the kernel upper bound and either updates the break or writes
errno 12 and returns `(void *)-1`. Success returns the previous break. Both
paths restore interrupts only when initially enabled.

CPU status, interrupt enable/disable and pipeline synchronization use separate
single-instruction intrinsics: `mfc0`, `di`, `ei`, `sync.p`. These operations
cannot be expressed in C. The conditions, retry loop, arithmetic, limit check,
errno write and return behavior are ordinary C. The source assembly policy
accepts these intrinsics; no assembly block replaces the routine.

## Verification

All three pass `swarm.py try`, organized `match.py check-many`, and assembly
policy. The actual decomp.wtf backend links all three byte-for-byte and rejects
an instruction mutation in every candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  005b4880:154 005b8f38:12c 005ae3a0:ac
python tools/build.py --jobs 2
```

Explicit lengths are hexadecimal and exclude alignment padding. They do not
change the GT4 judge or replace full-image proof.

The complete build at `2026-10-18T05:10:02Z` links all three new functions
from C, with 29,182 linked sources and 4,308,296 source instruction bytes.
Both original segment hashes remain exact: `.text`
`28422e7e20a6298224294255355487b9a22cef31`, `.data`
`c28c833f9716467545bf362f321e9acc876c3603`. Original assembly fallback
still supplies unrecovered code; this is a partial decompilation.

## Deferred work

- `005B4718`: the related close request retains the prior nonnegative-result
  comparison residual. A wider comparison cast also folds to the same shorter
  instruction sequence; source was not admitted.
- `005B1028`: void return types recover its initial tail call, but pool-address
  and store scheduling remain at the previously recorded residual. Initializing
  the packet view early hoists its address into the prologue and worsens it.
- `005AEDE0`, `005898C0`, `0057FD08`, `005AF1C0`, `0058DDA0`, `005B7198` were
  inspected for target selection. Existing assembly/ABI or diary evidence did
  not supply a new easy source model, and no recovery is claimed for them.
