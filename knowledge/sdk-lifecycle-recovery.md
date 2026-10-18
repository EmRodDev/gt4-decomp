# SDK lifecycle recovery

Six more small SDK routines recovered after `370d95a0`. All use the existing
`ee-gcc2.9-991111` compiler profile and natural C resource lifetimes. Names and
partial structure views remain provisional except where existing code supplies
the SDK parameter layout.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `00585DE0` | Validate resource children, unlink the parent, reattach or recycle children, notify after restoring interrupts | 320 |
| `00586DA0` | Create done/idle semaphores and a worker, clean up each allocation failure, start the worker | 332 |
| `00586EF0` | Wait for worker completion, terminate/delete the thread, delete semaphores and invalidate IDs | 124 |
| `005B1508` | Submit a pooled SIF transaction, optionally wait on a completion semaphore, release failed requests | 356 |
| `005B4650` | Reserve a descriptor slot and publish a backend handle or release the slot on failure | 200 |
| `005B6FC8` | Build a SIF reboot command, flush the packet, start DMA and update control registers on success | 340 |
| Total | | 1,672 |

The worker views agree with `00587BB0`: field `0x10` is its request; it signals
the semaphore at `0x08` when processing succeeds and the semaphore at `0x0C`
otherwise. Initialization and teardown now use the same done/idle names.
Semaphore field names follow existing SDK users: maximum count at `0x04`,
initial count at `0x08`, option/tag at `0x14`. Unspecified SDK fields retain the
original uninitialized state.

The resource removal uses the layouts and count check in `00585F20`. Its child
handler `00586B80` can attach a child to another active resource. Remaining
children are processed by `005869A8`, marked with flag `4` and linked into the
free list at global-header offset `0x14`. The callback runs after interrupt
state has been restored.

The transaction allocator `005B11F0` supplies the request's token and address;
its existing release helper clears the allocation flag and token. Submission
retains all five arguments, including the asynchronous-mode bit in argument 5.
The synchronous path creates a zero-initial-count semaphore, waits after a
successful submission, then deletes it. Failure paths preserve the original
`-1`, `-2` and `-3` results and cleanup order.

The descriptor wrapper agrees with `005B21D0` and `005B2348`: 32 slots of
16 bytes at `008897C0`, protected by semaphore `00658348`. It calls backend
selector `9`, stores the returned handle and returns the slot index.

The reboot packet is 104 bytes: a 16-byte command header, two control words and
80 argument bytes. It copies the argument bytes without their terminator and
stores their count. The 8/24/32-bit header fields naturally reproduce the SDK's
64-bit read/modify/write operations. A signed register-selector prototype is
needed for the original call delay slot; the unsigned draft did not match.

## Reproduction

All six passed `swarm.py try`, source assembly policy, and `match.py check-many`
after organization. The actual decomp.wtf backend links each one byte-for-byte
and rejects an instruction mutation in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  00585de0:140 00586da0:14c 00586ef0:7c \
  005b1508:164 005b4650:c8 005b6fc8:154
python tools/build.py --jobs 2
```

Lengths are hexadecimal and describe reviewed function boundaries. Alignment
padding is excluded. The inventory for `005B6FC8` also includes the next
routine at `005B7120`; the recovered reboot body ends at `005B711C`.
These explicit boundaries do not change the GT4 judge or the full-image check.

The complete build passed at `2026-10-18T04:32:27Z` on the changed tree
based on `370d95a0`: 29,458 sources, 29,159 source-linked functions,
and 4,302,632 instruction bytes from source. All six new functions are
`linked`, adding 1,672 bytes. The original segment hashes are preserved:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

The remaining unrecovered code still uses assembly/raw-byte fallbacks. This
build proves the new sources integrate exactly; the entire game is not yet
decompiled. No original game data, BIOS or generated binaries are committed.

## Deferred work

- `005FC170`: the public SGI heap tail matches. Endpoint construction still
  differs in reference aliasing and temporary loads. Five source hypotheses
  are recorded; none was admitted to `src/`.
- `005B8588`: the nonvolatile handle/free-list model differs only in two
  branch-delay rows. A volatile-object view worsens the surrounding schedule.
- `005B11F0` and identical sibling `00590AB8`: the compiler removes a token
  reload that the original retains. Both natural increment forms show the
  same residual; no allocator source was admitted.
