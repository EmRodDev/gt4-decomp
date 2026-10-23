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
| 0057f490, 0057f4f8 | long to double / long to float helpers | trapping `addi`/`daddi`, `$at`, t-registers, unscheduled: part of the soft-float library cluster |
| 00545a54 | MMI register-saving loop | `sq` saves of t0-t2/v1 and a t-register loop; C gives no `sq` |
| 005a4644 | hand-written MMI memchr | t-registers, unscheduled |
| 004ac034 | unaligned 64-byte copy | retail has an `sdl $t1,0xA7($a0)` whose offset no C source gives (looks like a typo in the original) |
| 004a7438 | fragment of the VU0 graphics code | keeps `ra` in `$t2` and returns with `jr $t2` |
| 004a74a0, 004a747c, 004a7454, 004a7890, 004a7844, 004a7a54, 004a7a00, 004a7988, 004a79b0, 004a79d8, 004ac400, 004a5f00 | libvu0 (`sceVu0*`): unit matrix, transpose matrix, sincos, ... | Opus (V2, oracle) 2026-10-18: hand-scheduled; `lui`/`addiu`/`sb` and `ld ra` sit between VU instructions that are scheduling barriers for ee-gcc 2.96; local-alloc gives `$v0` to the constant (priority 10000) over the base (3333). Probably Sony's libvu0, multi-instruction inline asm in the SDK source. |
| 004a7350 | hand-written assembly called by 004a7988 | `ori $t0,$t0,0x0`, fixed registers, same file as the 004a7438 fragment |
| 0012c250, 00232470, 00235ed0 (+ the other large static-init ctor/dtor functions, about 8 in all) | static initialisation of 70+ global objects, 5 words off | Opus (O3) 2026-10-19: one delay-slot decision. The guard of the object at +0x40 carries REG_BR_PROB 6001 (the NE heuristic); the original compiler saw a not-taken note there. In gcc-20001003 (predict.c, jump.c, ifcvt.c, reorg.c) a not-taken note can only come from a successor without successors, EQ of pointers, EQ (3999) or LT/LE against 0, and an inverted jump flips its note, so no arm swap, negation, pointer cast, real C++ globals, empty guard, throw() or profile moves it. Do not spend tries on source shape; what is left is a decision for the maintainer. Also: the dtor callee of another unit must not carry throw() (the original has bnel). |
| 005b2808 | SDK (ee-gcc2.9) handler install: `old = h.func; h.arg = arg; h.func = func; D_00889A80 = $gp` | opus-solo 2026-10-23: 2 of 40 off, build/drafts/func_005B2808.v2.c. The original's `sw $gp` sits in a branch delay slot; reorg never puts an asm insn in a delay slot, so the original read `$gp` through a global register variable (`register void *gp asm("$28")`), which tools/asm_policy.py refuses as register pinning. A one-instruction `asm("sw $gp, %0" : "=m"(...))` gives everything else; whether a global `$gp` variable is acceptable for SDK code is the owner's call. |

## Assembly-looking functions found 2026-10-23 (opus-solo), left open

Listed here instead of config/asm_functions.txt (they were added there briefly, then taken out under the
decision above). Evidence per group:

- **network crypto module 0x545a54-0x546ae0 (bignum add/sub/mul, an RC4 variant)** (18): `move` encoded as `or`, `sq` saves of `$a0`-`$a2`, `$t0`-`$t6` in first-use order with `$v0/$v1` unused, empty `jr` slots. 00545a54, 00545ac8, 00545b28, 00545b88, 00545bf0, 00545c58, 00545d7c, 00545eb8, 00545f30, 00545fc0, 00546038, 005460c8, 005464b0, 00546668, 00546830, 005468d0, 005469d0, 00546a60
- **SDK float/string helpers 0x57f238-0x57fbe0** (19): trapping `daddi`/`dsub`/`dadd`, `$at` as an arithmetic scratch, a MIPS I load-delay `nop` (the strcmp). 0057f238, 0057f2f8, 0057f360, 0057f3c0, 0057f418, 0057f470, 0057f480, 0057f768, 0057fa38, 0057fa48, 0057fa98, 0057faf8, 0057fb50, 0057fb88, 0057fb98, 0057f490, 0057f4f8, 0057f578, 0057f8b8
- **vector/MMI bodies** (55): each needs at least 3 distinct VU0/COP2/MMI instructions without a C operator (`por`/`pcpyld`/`pcpyud`/`plzcw`/`mtsab`/`qfsrv` not counted), i.e. more inline asm statements than asm_policy.py allows (counted with operands, so one inline helper used several times is not overcounted). 003e8438, 004a70e8, 004a6c58, 0049a6a0, 001fde68, 0049a4f8, 0049d580, 0049db08, 0049a360, 0049e780, 0049c140, 0049e918, 0049a200, 004ac118, 005a6900, 0056e2c0, 0056e170, 003e7f08, 003b8ea0, 001c1a50, 001fdd28, 00451238, 00492978, 003e3840, 00492ef0, 003b8530, 003e8790, 0049e2d8, 003e3ed0, 0049f1f8, 00496638, 003b7dd8, 004961b8, 0049d970, 003e2710, 004a6e20, 003d51b0, 0049d728, 0049dcb0, 00499d00, 0044dcc0, 00499948, 004522d8, 00456918, 003e32e8, 00568b40, 0049f170, 005692c0, 0056df58, 0056de38, 00454f40, 00498e48, 00455708, 001c1760, 001c1678
- **not code** (1): 00616f24 is 2800 bytes of a data table in .text (the words decode as `.word`/`tge`/`mfsa` noise); an inventory error rather than a function. 00616f24
- **int-to-float inline asm sequence** (1): `plzcw`/`andi`/`sra $at`/`or` around a call. 00578598
