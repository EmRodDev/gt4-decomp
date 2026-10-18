# CD command RPC recovery

Two SDK functions recovered with Codex using the compile-and-diff workflow from
decomp.wtf. Both use `ee-gcc2.9-991111`, whose saved registers are spaced 16 bytes
apart; the engine's default EE-GCC 2.96 profile does not reproduce these frames.

| Address | Source | Behavior inferred from instructions and callers | Bytes |
| --- | --- | --- | --- |
| `005835B0` | `src/libstream/unit_0057A128/func_005835B0.c` | CD streaming request, gate 15, RPC 10 | 360 |
| `00580928` | `src/libstream/unit_0057A128/func_00580928.c` | Gate 2, RPC 14 with no send payload | 152 |

The streaming request contains a sector number, sector count, buffer, command,
and three read-mode bytes. Callers `00583218`, `00583508`, `00583540` and
`00583580` establish those roles. A null mode preserves the previous bytes;
the fourth mode byte is not written. The request pointer's lifetime at entry
matters to the SDK compiler's saved-register allocation.

Both functions send nine arguments to the RPC routine, including the stack
argument for its final callback context. They release the command semaphore
after submission failure and after a successful reply. Replies are read through
the EE uncached alias (`address | 0x20000000`), consistent with DMA delivery.
Address-based names are retained where original symbol names are unproven.

## Reproduction

After the normal project setup with the supported USA v1.01 executable:

```sh
python tools/match.py check 005835b0 src/libstream/unit_0057A128/func_005835B0.c
python tools/match.py check 00580928 src/libstream/unit_0057A128/func_00580928.c
python tools/build.py --jobs 2
```

The complete build must report `.text OK` and `.data OK`. As usual, unresolved
functions elsewhere in the executable remain assembly or raw-byte fallbacks;
an identical complete image does not mean the entire engine is recovered C/C++.

Verified on the changed tree based on `f4da0e09044e` at
`2026-10-18T00:28:58Z`: all 29,436 sources compiled, both recovered functions
were reported `linked` (360 and 152 bytes), and both loaded segments matched.
The `.text` SHA-1 was `28422e7e20a6298224294255355487b9a22cef31` and the `.data`
SHA-1 was `c28c833f9716467545bf362f321e9acc876c3603`.

For an independent check, clone `https://github.com/i12bp8/decomp.wtf` beside
this repository, install its dependencies with `uv sync --python 3.12`, then run:

```sh
../decomp.wtf/.venv/bin/python tools/verify_cd_commands.py
```

This compiles using GT4's configured compiler and calls decomp.wtf's real
`decompnet.rom.match.link` API to resolve relocations and compare against the
original executable. It also changes an instruction in each candidate object
and verifies rejection. Results, source hashes and original CORE SHA-1 are
written to ignored `build/backend-verification.json`. `--backend PATH` selects
a different backend checkout. No game bytes are included in this change.

## Deferred command setup

`005807D0` is not counted as recovered. Its closest draft has six register
operand differences in 86 instructions. Volatile semaphore identifier access
recovers the load/call scheduling; the client and binding-flag high addresses
still occupy exchanged saved registers. The attempts diary records ten tested
hypotheses. No unmatched implementation is added to `src/`.
