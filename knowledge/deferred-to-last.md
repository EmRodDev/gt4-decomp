# Deferred to the end

Decision of the owner, 2026-10-18: the functions that look hand-written, and the fragments that
borrow their caller's registers, are worked **last**. By then the code around them is decompiled,
and what still calls them or is called by them shows what is left unconnected. No assembly (`.s`)
is accepted for them (see `config/asm_functions.txt` for the 205 that were assembly in the
original and are not targets): they stay open until a C/C++ source reproduces the bytes, or are
reported as open.

Do not lease these to workers or tools meanwhile (`swarm.py` workers return `fragment` and make no
tries anyway). When their turn comes:

1. For the fragments, first check the function inventory: a routine that jumps into its
   neighbours and uses registers it never set (`s5`-`s7`, `ra`) is usually one function cut in
   pieces. Merge the boundaries and decompile it whole, from the public source if it has one
   (the inflate code is gzip/zlib).
2. For the hand-written ones, a strong model with `tools/oracle.py`, many tries; record what the
   compiler cannot emit (trapping `daddi`, hand-scheduled `movz` chains, `t5`-`t9` allocation).

## Seen so far (2026-10-17 workers)

| Address | What | Note |
|---|---|---|
| 0058a280, 0058a4a8, 0058a5f8, 0058a668, 0058ab08 | inflate: bit reader and main loop | borrow `s5`-`s7`, jump into each other; one function cut in pieces? gzip/zlib source |
| 0058ac20 | fragment | uses caller's `s3`-`s7` and `ra` |
| 0058b2b0, 0058b370 | syscall stub tables | `break` / `addiu $zero,n` pairs: check against `config/asm_functions.txt` |
| 0057f768 | soft-double divide | trapping `daddi`/`dsub`, `movz` chains, `t5`-`t9`; ~100 instructions off whatever the profile |
| 0057f3c0 | saturating double bits to u64 | fully if-converted `daddi`/`movz`/`movn` |
| 0057fa98 | `fixdfsi` | trapping `daddi`/`dsub`, branchless `movz` chains |
| 0057d1f0, 0057d2b8, 0057d380 | sin/cos kernels | EE accumulator ops (`adda.s`, `madda.s`, `madd.s`, `msub.s`) |
| 0057f188 | unrolled byte compare | looks hand-written |
