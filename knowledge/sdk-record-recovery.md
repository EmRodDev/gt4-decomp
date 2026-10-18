# SDK optional-output and record requests

Six asynchronous request functions recovered after `86fcd08b`, using the
existing SDK 2.9 profile. They extend the reviewed server/semaphore/packet
family without changing its lifecycle. Semantic argument names and partial
record layouts remain provisional.

| Address | Request | Instruction bytes |
| --- | --- | ---: |
| `0058E038` | Operation 1: two arguments, three optional output pointers and callback scratch | 380 |
| `0058DAF8` | Operation 4: three argument words at packet offsets `0`, `0x10`, `0x14` | 224 |
| `0058E228` | Operation 13: string, arguments and a buffer of 64-byte records | 332 |
| `0058E618` | Operation 15: two arguments, bounded string and zero third packet word | 284 |
| `0058E7F8` | Operation 14: bounded string, three flag bits and a copied 64-byte record | 460 |
| `0058E9C8` | Operation 14 with flag 16 and a second string; pending marker 19 | 344 |
| Total | | 2,024 |

## Source review

All six preserve the server-present check, nonblocking submission-lock
acquisition and failure results. They return `-100` for an unbound client,
`-200` when the lock cannot be acquired and `-91` for submission failure.
String operations also return `-210` for their original invalid-input cases,
releasing the acquired lock. Successful submission retains it for later
completion handling. The existing callers retry these request functions until
submission succeeds; their argument counts agree with the recovered views.

Operation 1 sends three presence flags and saves the corresponding result
pointers. Existing callback `0058DFE0` reads the scratch area through its
uncached alias, conditionally writes results from scratch words 0, 1 and 36,
then signals completion semaphore `00657AF8`. The recovered wrapper preserves
all three pointer tests and the `0xC0`-byte scratch writeback.

Operation 13 uses a `0x414`-byte string packet. The record count and buffer
address are passed in their original fields. Only nonnegative counts trigger
cache writeback, with byte length `count * 64`; a negative count is still sent
to the server. No additional buffer validation was introduced.

Operation 14's main form copies a complete 64-byte metadata record with one
ordinary C aggregate assignment. Its four-byte alignment naturally emits the
original unaligned doubleword loads/stores. It masks the incoming flags to
three bits, attaches the copied record, copies the main string, and flushes
cache before submission.

The second form writes flag 16 and copies a second string into the metadata
record's final 32 bytes, leaving its first 32 bytes intact. This typed string
subobject preserves the original retained subobject address and later base
calculation, closing an earlier cache-flush delay-slot residual. It sends RPC
command 14 but stores **pending marker 19**; the source preserves that distinction.
The second string keeps the original 32-byte strncpy limit without an extra
terminator store. Main packet strings keep their 1023-character limit and
explicit terminator in byte 1023.

## Verification

All six pass `swarm.py try`, `match.py check-many` after organization and the
source assembly policy. The actual decomp.wtf backend links each byte-for-byte
and rejects an instruction mutation in every candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  0058e038:17c 0058daf8:e0 0058e228:14c \
  0058e618:11c 0058e7f8:1cc 0058e9c8:158
python tools/build.py --jobs 2
```

Lengths are hexadecimal and describe reviewed function bodies, excluding
alignment padding and neighboring routines. In particular, inventory spans
fold additional code into `0058E038`, `0058DAF8`, `0058E228` and `0058E618`.
Their recovered bodies end at `0058E1B4`, `0058DBD8`, `0058E374` and `0058E734`
respectively. Other functions within those inventory spans are not counted.
These boundaries do not weaken the GT4 judge or replace full-image proof.

The complete build passed at `2026-10-18T04:58:05Z` on the changed tree
based on `86fcd08b`: 29,478 sources, 29,179 source-linked functions,
and 4,307,484 instruction bytes linked from source. All six new
functions are `linked`, adding 2,024 bytes. Both original segment hashes match:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

Unrecovered code retains the normal assembly/raw-byte fallbacks. The entire
game is not yet decompiled. Original game data, BIOS and generated binaries
are excluded from this contribution.

## Stack-argument follow-up

The recovered ten-argument retry routine `005B2258` reads its ninth argument at
entry `sp+0` and its tenth at entry `sp+8` (`sp+0xC0`/`sp+0xC8` after its
`0xC0` frame allocation). This confirms eight-byte stack argument slots for
this SDK ABI. A caller writing words at `sp+0` and `sp+8` does not thereby
leave an uninitialized argument; the intervening word is padding. This removes
the earlier suspected ABI blocker for `005B4880`, which has not yet been tried.

## Deferred work

- `0058BF60`: initialization and capability extraction have the right call/loop
  shape, but 27 rows differ in comparison/result registers and unpacked values.
- `0058C3F0`: channel transition and three-buffer invalidation have twelve
  scheduling/branch/result differences after three structural hypotheses.
- `0058EDA8`: inspected only; its earlier ten-attempt diary describes a
  register/scheduling residual and supplies no new source-model lead.

Those routines remain outside `src/`. The attempts diary records the tested
hypotheses, and local drafts are retained for future work.
