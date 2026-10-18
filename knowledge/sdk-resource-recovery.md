# SDK resource and small-wrapper recovery

Six small functions recovered with Codex after refreshing upstream to
`ec4261f8`. All use the existing `ee-gcc2.9-991111` profile. Parameter layouts,
call signatures and return types were reconstructed from the instructions and
existing callers/callees; original names remain unproven unless stated below.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `00583BA0` | Allocate ELOADP driver resources, create a semaphore and worker, install its interrupt handler | 228 |
| `00583C88` | Release those resources, unregister the handler and restore interrupt state | 180 |
| `0058AE10` | Inflate gzip data, check the trailer's output length and optionally return its stored CRC | 184 |
| `005AEA78` | Initialize the kernel top worker and semaphore, clean up thread-creation failure, dispatch a zeroed start message | 236 |
| `005AED18` | DelayThread: check interrupt enable, create an alarm-backed semaphore, wait and clean up | 200 |
| `005B2258` | Retry an RPC call at most 101 times, delaying with a scale capped at 128; return a failure flag | 236 |
| Total | | 1,264 |

The semaphore and thread parameter structures reproduce the SDK field offsets
without copying instructions into the source. Fields that the original leaves
untouched remain uninitialized. No shared header was changed.

The gzip trailer is an unaligned packed pair of 32-bit words. Its aggregate
copy reproduces the unaligned doubleword instructions naturally. The wrapper
compares the decompressed size with ISIZE; it returns the stored CRC rather
than calculating or validating it.

DelayThread uses one `mfc0` intrinsic to read the CPU status register. The rest
is C, including error handling and resource lifetime. The repository's assembly
policy accepts the intrinsic. Declaring its return type as `int` in the RPC
retry caller also recovers the compiler's comparison-register choice.

## Reproduction

Run `tools/match.py check ADDR FILE` for each source, or use `check-many` with
the six address/source pairs. The functions are organized under
`src/libstream/unit_0057A128/` and `src/runtime/unit_0059BE80/`.

Independent decomp.wtf linking and changed-instruction rejection checks:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  00583ba0:e4 00583c88:b4 0058ae10:b8 \
  005aea78:ec 005aed18:c8 005b2258:ec
python tools/build.py --jobs 2
```

Lengths are hexadecimal and describe reviewed function boundaries. The
call-based inventory folds alignment padding into several entries and a second
routine into `0058AE10`; the gzip wrapper ends at `0058AEC8`. Explicit lengths
allow the independent linker to compare exactly the recovered function body.
They do not change the GT4 judge or replace the complete-image proof.

All six passed both function matchers and the backend's instruction corruption
checks. The original CD-command checks also passed after extending the verifier
to accept additional functions. A full build must still report `.text OK` and
`.data OK`, with all six addresses marked `linked`.

The complete build passed at `2026-10-18T00:41:27Z` on the changed tree based on
`6a15b9b82a26`: 29,446 sources, all six new addresses `linked`, and 1,264 new
linked bytes. Both original loaded-segment hashes were preserved:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

The full image contains 4,300,264 bytes linked from source. The remaining
unrecovered functions retain the project's normal assembly/raw-byte fallbacks.
No original data, BIOS or generated binaries are part of this contribution.

## Deferred work

The settings update at `00113248` has matching logic but exchanged saved-register
assignments for its configuration and destination views. Three natural source
forms did not improve the 19/54 operand differences. Its drafts remain outside
`src/`; the attempts diary records the findings for a later pass.
