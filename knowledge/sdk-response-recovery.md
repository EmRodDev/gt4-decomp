# SDK response and asynchronous request recovery

Eight functions recovered after `4fa447f1`, using the existing SDK 2.9 profile.
The response extractor and metadata decoder form one reviewed pair; the four
asynchronous wrappers extend the packet family recovered in earlier batches.
Names and partial object layouts remain provisional.

| Address | Behavior | Instruction bytes |
| --- | --- | ---: |
| `0058EF08` | Copy a channel response payload, decode trailing descriptors, return length or failure | 212 |
| `0058F4D0` | Expand forty presence bits into packed-field descriptors | 176 |
| `0058FC68` | Serialize synchronous RPC `80001302`, log transport failure, return the server result | 188 |
| `0058E548` | Submit asynchronous operation 16 with two packet arguments | 204 |
| `0058EB20` | Submit asynchronous operation 17 with the same argument layout | 204 |
| `0058EBF0` | Submit asynchronous operation 18 with two arguments and a bounded string | 268 |
| `0058D8D8` | Submit asynchronous operation 2 with three arguments and a bounded string | 296 |
| `0058DC88` | Submit asynchronous operation 5 with a caller buffer and callback scratch area | 276 |
| Total | | 1,824 |

## Response layout and decoder

Existing `0058F348` establishes readiness, and `0058F3A0` selects one of two
128-byte response buffers using their timestamp at `0x7C`. The recovered
extractor retains the active/readiness checks, copies the byte count at response
offset `0x02`, then passes the following bytes to the metadata decoder.
It returns `-1` if the response status at `0x04` is zero. These checks do not
add payload bounds validation that the original did not perform.

Channel records have stride `0x334`. Their descriptors begin at `0x14`:
forty records of four 32-bit fields (`present`, `width`, `byte_offset`,
`bit_offset`). The final `0xA0` bytes remain unexplained in the local view.
The existing field consumer at `0058F1F0` checks presence before interpreting
width and extracts either one bit or a byte at the described bit offset.

The decoder consumes five bitmap bytes. Present fields 16..31 and 35..38 have
width 8; other present fields have width 1. Absent fields clear presence and
both offsets but preserve the old width. The source retains this behavior.
Declaring the field index before the packed-bit index, while initializing them
in the original order, resolved an earlier saved draft's register swap using
ordinary locals.

## Request family

Operations 16 and 17 place their arguments at offsets `0x04` and `0x08` in the
48-byte command packet. Operations 18 and 2 use a `0x414`-byte packet with a
1024-byte string at `0x14`; both reject null/empty strings after locking and
release the lock on that failure. They copy at most 1023 characters using the
existing strncpy routine and explicitly terminate byte 1023. Operation 2
fills its argument words after copying, which also reproduces the compiler's
retained string-subobject address.

All four asynchronous request functions preserve the library's server-present
check, nonblocking semaphore acquisition, submission failure result `-91` and
pending-operation marker. On successful submission the lock remains held for
later completion handling. Callback `0058D748` signals the separate completion
semaphore, as documented in `sdk-polling-recovery.md`.

Operation 5 writes back the caller buffer and a `0xC0`-byte scratch area before
submission. Its callback `0058DBD8` uses the uncached scratch view, copies up to two
fragments to their destinations through both cached and
uncached aliases, then signals the completion semaphore. The wrapper passes
the scratch address as the callback argument. The callback itself remains
unrecovered and is not counted in this batch.

## Verification

All eight pass `swarm.py try`, `match.py check-many` after organization, and the
source assembly policy. The actual decomp.wtf backend links each byte-for-byte
and rejects an instruction mutation in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  0058ef08:d4 0058f4d0:b0 0058fc68:bc \
  0058e548:cc 0058eb20:cc 0058ebf0:10c \
  0058d8d8:128 0058dc88:114
python tools/build.py --jobs 2
```

Lengths are hexadecimal and exclude alignment padding and neighboring
functions. The inventory span for `0058F4D0` also includes unrelated code
beginning at `0058F580`; the decoder ends at `0058F580` after 44 instructions.
These reviewed boundaries do not change the GT4 judge or full-image proof.

The complete build passed at `2026-10-18T04:49:19Z` on the changed tree
based on `4fa447f1`: 29,472 sources, 29,173 source-linked functions,
and 4,305,460 instruction bytes linked from source. All eight new
functions are `linked`, adding 1,824 bytes. The original segment hashes match:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

Unrecovered code retains the normal assembly/raw-byte fallbacks. The entire
game is not yet decompiled. No original game data, BIOS or generated binaries
are included in this contribution.

## Deferred work

The companion second-payload extractor `0058EFE0` now differs only in the
commutative operand order of one `addu`. Reassociation, reversed spelling and
an explicit intermediate pointer leave that residual. Its readable draft
remains outside `src/`; the diary records all attempts.

Clock read `005B8400` has prior evidence of original SDK assembly and was
excluded from C recovery. No pinned registers, raw words or instruction blocks
were introduced to close residuals.
