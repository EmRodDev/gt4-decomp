# SDK RPC binding, descriptor guards and table management

Seven routines recovered after `1b6c4641`, using the existing SDK 2.9 profile.
Names and partial record layouts are provisional; numeric command identities
and machine behavior match the original.

| Address | Behavior | Compiled bytes |
| --- | --- | ---: |
| `005B9310` | Replace and clear caller-owned callback table under IRQ exclusion | 124 |
| `005B17D0` | Bind RPC client with pooled request and optional completion semaphore | 332 |
| `005B1700` | Send bind reply with matching server and schedule retry after failed send | 204 |
| `005B9068` | Allocate alarm using timer primitives without IRQ wrappers | 240 |
| `005B1DF0` | Unlink a registered group under IRQ exclusion | 144 |
| `005B2150` | Count occupied descriptors under table semaphore | 124 |
| `005B2D00` | Submit operation 253 after compatibility and descriptor-count checks | 240 |
| Total | | 1,408 |

## RPC bind and retry

`005B17D0` resets the client's command/server fields, allocates a 64-byte request,
copies its generation into the client and submits command `0x80000009`. Blocking
mode owns a temporary completion semaphore. Semaphore creation failure returns
-3 after releasing the packet; send failure returns -2 after releasing both;
success waits and deletes the semaphore. Asynchronous mode stores semaphore -1
and leaves successful completion to the response handler. The existing
`005B1508` transaction model, allocator `005B11F0`, release `005B1298`, send
wrapper `005B0DB0` and completion handler `005B1328` were reviewed. The allocator
and completion handler remain unrecovered and are not counted here.

`005B1700` obtains a reply slot from the existing round-robin allocator,
preserves the original header references, finds a registered server and copies
its address and DMA buffer into the reply. A missing server yields two zero
fields. The reply uses outer command `0x80000008`, inner command `0x80000009`.
A failed send schedules `005B16C0` after 0x800 timer units; that callback resends
the same reply and returns either zero or another 0x800 interval.

Recovered sibling `005B1438` supplied the useful header model: capture both
opaque 32-bit wire references before publishing the reply. Pointer views left
initial load/store scheduling wrong. Integer wire views recovered the sequence;
capturing request id before client address closed the remaining register homes.
The server address stays a pointer, with aliasing consistent with its DMA buffer.
No pinned registers, dead stores or assembly were introduced.

The retry uses `005B9068`, the counterpart of recovered `005B8F38` that calls
unwrapped timer allocation, callback installation and start primitives. It
preserves the shared free-list volatility and rollback ordering, installs the
existing dispatcher `005B8ED8` and returns the same encoded alarm handle. A null
callback and exhausted pool retain their original errors. Timer allocation
failure recycles the record and clears its timer. Callback timer-register views
remain provisional. Review included its existing caller `005B1438`, the new bind
reply caller and the underlying timer routines.

## Tables, groups and descriptor guards

`005B9310` returns the old caller-owned callback table, publishes a replacement
and its count, then clears `count * 16` bytes while interrupts remain excluded.
The default table is separate. Existing `005B9448`, table reset `005B92E8`,
registration `005B9390`, dispatch `005B94A0` and the memset callee establish the
layout and ownership. Registration/dispatch still require global-pointer state
handling and are not recovered here. The typed entry view records callback,
argument, saved global pointer and an unknown word.

`005B1DF0` removes the requested group from the pool's singly linked list. It
returns the old head when removing that head, otherwise the predecessor or null
when absent. Keeping the unlink/break inside the search loop reproduces the
original peeled first iteration and avoids a redundant post-loop null test.
The original unconditionally reenables interrupts after this operation; that
behavior is preserved. Callers must supply a valid group.

`005B2150` initializes the descriptor semaphores, waits for table ownership,
counts nonzero occupancy fields across 32 sixteen-byte records and releases the
semaphore. `005B2D00` takes the library lock, initializes the backend when needed,
runs the existing four-byte identifier compatibility check and rejects a nonempty
descriptor table with -16. Compatibility rejection returns `0xFFFEFFFC`.
It then sends the caller's argument with operation 253 through the established
ten-argument RPC retry interface and returns an uncached response word. Submission
failure returns -11. Every path releases the library lock. The unused second
request word retains its original contents.

The int return declaration of library-lock helper `005B27C8` agrees with its
existing source and restores the original initial address/result register choice.
The uncached response is ordinary RAM, as in prior recovered requests, allowing
the load in the unlock call's delay slot.

## Verification

All seven pass `swarm.py try`, assembly policy and organized `match.py check-many`.
Cleanup of the callback entry view and opaque pool declaration was rejudged.
The actual decomp.wtf backend matches all seven entire compiled bodies and
rejects an instruction mutation in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  005b9310:7c 005b17d0:14c 005b9068:f0 005b2d00:f0 \
  005b2150:7c 005b1df0:90 005b1700:cc
python tools/build.py --jobs 2
```

Explicit lengths are hexadecimal and use compiler-emitted body sizes, not the
inventory span to the next start. The alarm allocator ends with its return delay slot at `005B9154`, giving
a complete 240-byte body; padded spans elsewhere are counted only to the
compiled end.
Hashes and local proof are saved in `build/sdk-bind-sources.json` and
`build/sdk-bind-proof.json`.

The complete build at `2026-10-18T09:19:53Z` links all seven new routines from
C. Totals are 29,194 linked sources and 4,310,560 source instruction bytes
(80.73% of `.text`). Original segment hashes remain exact: `.text`
`28422e7e20a6298224294255355487b9a22cef31`, `.data`
`c28c833f9716467545bf362f321e9acc876c3603`. Original assembly fallback still supplies
unrecovered code; this remains a partial decompilation.

## Deferred work

`005B11F0` retains its previously recorded serial/token residual. `005B1920`
retains its earlier header alias/scheduling residual; no new hypothesis was tried.
`005B9390`, `005B94A0`, `005B2808`, `005B28A8`, `005B1328` require live global-pointer
state handling, while `005B5D18` includes an explicit delay loop. These were
inspected to select targets; no new recovery is claimed for them. `005B9668` and
`005B9AB0` retain their existing near-miss notes.
