# Small-family recovery

Six routines recovered after `6619c6df`, using matched members as evidence for
source structure and compiler context. The sources retain provisional layouts;
address-based names do not establish the original class or field names.

| Address | Behavior | Instruction bytes | Reference |
| --- | --- | ---: | --- |
| `00113248` | Propagate enabled and paired options, apply pending adjustments, mark settings dirty | 216 | `00111DC0` |
| `004A19D8` | Store a scratchpad setting and recompute the derived value | 36 | `004A19B0` |
| `005B7B98` | Set channel 0 timer mode through the shared register-write helper | 16 | `005B7B88` |
| `005B7BA8` | Set channel 0 timer comparison through that helper | 16 | `005B7B88` |
| `005FD540` | Insert repeated values into a bounded 32-element integer array | 212 | `00608B20` |
| `00606ED0` | SGI lower_bound on name-bearing records using string comparison | 200 | `006067C0` |
| Total | | 696 | |

The settings update previously differed only in saved-register allocation.
Its identical counterpart showed that the destination view is assigned inside
the pending-update branch. This preserves the natural typed source and gives
an exact match without register annotations.

`004A19D8` is catalogued as `pglFrontFace` from a medium-confidence GT HD
mapping. Its local one-word aggregate is an ABI-compatible provisional view;
the original parameter type has not been recovered. The derived-value helper
reads the same field at `0x2CC` and the neighboring mode at `0x2C8`.

The array routine uses the same copy/shift/fill structure as its 48-element
counterpart. The caller must supply valid capacity and range arguments, as in
the original; no new bounds checks were introduced. The lower_bound routine
retains the SGI algorithm and helper hierarchy covered by `THIRD_PARTY.md`.

The two register wrappers use the SDK 2.9 compiler. Existing callers of the mode
setter read `0x10001010`, alter the enable/status bits, then call it; the wrapper
passes its uncached alias `0xB0001010` to the common helper.

## Verification

All six pass `swarm.py try` and `match.py check-many` after organization, and
pass the source assembly policy. The real decomp.wtf backend also links all
six byte-for-byte and rejects a changed instruction in each candidate:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py \
  00113248:d8 004a19d8:24 005fd540:d4 \
  00606ed0:c8 005b7b98:10 005b7ba8:10
python tools/build.py --jobs 2
```

Lengths are hexadecimal and exclude alignment padding. In particular,
`005FD540` contains 53 instructions (212 bytes), rather than its 216-byte
inventory span. The independent verifier does not replace full-image proof.

The complete build passed at `2026-10-18T04:22:37Z` on the changed tree based
on `6619c6df`: 29,452 sources, 29,153 functions linked from source,
and 4,300,960 linked instruction bytes. All six new addresses are
`linked`, adding 696 bytes. Both original loaded-segment hashes were preserved:

- `.text`: `28422e7e20a6298224294255355487b9a22cef31`
- `.data`: `c28c833f9716467545bf362f321e9acc876c3603`

Unrecovered code still uses the project's normal assembly/raw-byte fallbacks.
A matching complete image does not mean the entire game is decompiled.
No original game data, BIOS or generated binaries are committed.

## Deferred work

`005C30B0` now has a natural member-function-pointer call and automatic holder
lifetimes with only three stack-slot offsets differing. Named-local variants
worsen scheduling. The best expression-form draft and failed hypotheses are
recorded locally and in the attempts diary; no source was admitted for it.
The duplicate scan also contains trap/table fragments without independent
function returns. Those were excluded from C/C++ recovery.
