# SDK timer lifecycle and time conversion

Six timer routines recovered after `cb522fbb`, using the existing SDK 2.9
profile. All are ordinary C with no inline assembly. Record/state names and
partial layouts remain provisional.

| Address | Behavior | Compiled bytes |
| --- | --- | ---: |
| `005B8CE0` | Convert ticks to optional seconds and microseconds | 168 |
| `005B7D10` | Shut down initialized timer service when no records are allocated | 184 |
| `005B84D0` | Allocate a timer record and generation handle | 112 |
| `005B8588` | Validate and release a timer record | 160 |
| `005B8940` | Replace accumulated ticks, returning the previous total | 204 |
| `005B8828` | Stop a timer and update callback scheduling when applicable | 196 |
| Total | | 1,024 |

## Time conversion and shutdown

`005B8CE0` divides unsigned ticks by 147456000, truncates the seconds quotient
to 32 bits and optionally stores it. The fractional calculation uses that
truncated value in a full-width frequency product, then multiplies the remainder
by 1000000 and divides by the same frequency. This preserves the original
arithmetic even for large inputs. Both output pointers are optional. Existing
inverse conversion `005B8D88` confirms the frequency and units. The division
helper at `005BAE00` is already named `__udivdi3` in the project symbol map.

`005B7D10` rejects an uninitialized service and an outstanding allocation count.
It excludes interrupts, removes handler 11 and, on successful removal, disables
the channel and writes the original timer mode/count reset values. It then clears
the shared ticks, resets the handler to -1 and conditionally restores interrupts.
The shared allocation count is volatile, matching the existing timer query
`005B8678` and asynchronous pool updates. Hardware wrappers `005B7B98` and
`005B7B88`, interrupt removal and `005AE780` were reviewed; their implementations
remain separate from this source.

## Allocation and release

Timer records are 64 bytes. Handle bits 10..31 encode the record address and
bits 0..9 encode generation. Allocation pops the shared free list, increments the
allocation count, clears callback/flags/elapsed ticks and assigns the next odd
10-bit generation. The original reloads of generation and record identity use
volatile views. Snapshotting the incremented count before reading the next link
closes the allocator's previous two-instruction scheduling residual.

Release validates the handle and rejects the currently executing timer. It
removes a scheduled record from the callback list when flag 2 is set, clears
identity/flags, links the record back to the free list and decrements allocation
count. Validation reads occur with caller-supplied interrupt exclusion. A small
`clear_record(volatile ...)` helper publishes the reset before free-list return;
explicit head/count snapshots preserve the original update ordering. This closes
the prior optional-removal branch and pool-publication residuals. Existing wrapper
`005B8628` provides interrupt exclusion; list removal `005B8120` takes one argument
and returns the following node.

The shared-state views in the new sources are local partial models, rather than
a claim about the original C typedef. Their volatility follows the observed pool
and interrupt interactions. No register constraints or extra stores were added.

## Accumulated ticks and stopping

`005B8940` excludes interrupts and validates generation/current-timer state.
For a running timer, it adds `now - started` to the old accumulated total, replaces
the start snapshot and installs the caller's new accumulated value. A stopped
timer needs only the replacement store. It returns the previous total, or -1
on validation failure, and restores the prior interrupt state.

`005B8828` performs corresponding checks in the caller's interrupt-excluded
context. A stopped timer returns 0. A running timer accumulates elapsed ticks,
clears running flag 1 and returns 1. When callback flag 2 is set, it removes the
record and updates hardware scheduling using the captured clock. Both operations
belong inside that conditional path. Using the actual one-argument removal
prototype also restores the original mask/arithmetic instruction scheduling.
The existing `005B88F0` wrapper and the removal/scheduler routines were reviewed.

The volatile shared-state view preserves the explicit global-base address setup
in both routines, resolving the folded-address residual recorded by earlier
attempts. Clock reads continue to call existing `005B8400`; that low-level
routine is not recovered by this batch.

## Verification

All six pass `swarm.py try`, organized `match.py check-many`, and assembly policy.
The actual decomp.wtf linker matches their complete compiled bodies and rejects
an instruction mutation in each:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  005b8ce0:a8 005b7d10:b8 005b84d0:70 005b8588:a0 \
  005b8940:cc 005b8828:c4
python tools/build.py --jobs 2
```

Lengths are hexadecimal compiled-body sizes, excluding subsequent alignment
padding. Local evidence is saved in `build/sdk-timer-sources.json`,
`build/sdk-timer-backend.json`, and `build/sdk-timer-proof.json`.

The verifier now resolves named undefined symbols from existing project mappings,
so compiler-generated `__udivdi3` references work through the backend's ordinary
symbol table. It does not invent addresses or relax byte comparison. A deliberately
wrong mapped symbol address is also rejected. The GT4 judge, original image,
compiler profiles and decomp.wtf linker were not changed.

The complete build at `2026-10-18T09:56:26Z` links all six new routines from
C. Totals are 29,200 linked sources and 4,311,584 source instruction bytes
(80.75% of `.text`). Original segment hashes remain exact: `.text`
`28422e7e20a6298224294255355487b9a22cef31`, `.data`
`c28c833f9716467545bf362f321e9acc876c3603`. Original assembly fallback still supplies
unrecovered code; this remains a partial decompilation.

## Deferred work

`005B8400` and `005B8450` retain prior low-level timer-read assembly/code-generation
residuals; `005B7B18` is kernel-mode register-write assembly. `005B7A40` and
`005B7688` retain prior table-load scheduling notes. They were inspected for target
selection, with no new recovery claimed. Memory RPC routines `005B6DF8` and
`005B6EE8`, and argument packing `005B7788`, were inspected before this timer
batch was selected; no source hypothesis was judged for them.
