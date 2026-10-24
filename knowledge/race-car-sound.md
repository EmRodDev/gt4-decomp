# RaceCarSound object layout (0x391970 unit)

Tags: [confirmed] = seen in the v1.01 disassembly or in a judged (matched) source;
[inferred] = deduced, reason given. Function names are from config/symbol_addrs.txt (GT HD).

## Layout of the object (self, size unknown, flag at 0xB38)
The matched `RaceCarSound__playStop` (src/race/unit_00391970/RaceCarSound__playStop.cpp) and the
disassembly of `RaceCarSound__playStart` (0x3924D0) agree on this map [confirmed]:

| offset | content | evidence |
|---|---|---|
| 0x000 | 0x14-byte header, not touched by playStart | playStop source layout; unknown purpose |
| 0x014 | `H` block (0x14 bytes), initialised by 0x391EB0 | playStart `jal 391EB0` with a0 = self+0x14 |
| 0x028 | `int/ptr a[2]`: objects returned by 0x559808 | playStart stores v0 at 0($s0), s0 += 4; playStop passes them to 0x559378 |
| 0x030 | two 0x124-byte records; word at +4 of each (0x34, 0x158) is passed as 2nd arg to 0x559470 | playStart `lw a1,0($s1)`, s1 = self+0x34, += 0x124 |
| 0x278 | two 0x20-byte `SePlayer` objects | playStop calls SePlayer__Stop on them |
| 0x2B8 | `H` block, then `int k` at 0x2CC (object from 0x559808), 0x124-byte record at 0x2D0 (word at 0x2D4 passed to 0x559470) | playStart 0x2B8..0x2D4 |
| 0x3F4 | `H` block; 3 `SePlayer` at 0x408; 3 floats at 0x468 | playStart ctor + zero loop 0x470 down to 0x468; playStop stops 3 players |
| 0x474 + n*0x1A0, n=0..3 | group: `H` block, 11 `SePlayer` at +0x14 (0x488+n*0x1A0), 11 floats at +0x174 (0x5E8 + n*0x1A0) | playStart: ctor on 0x474+n*0x1A0, then 11 float zero stores |
| 0xB38 | `int` init flag: playStart does nothing if nonzero, sets it to 1; playStop does nothing if zero, clears it | both disassemblies |

Group float arrays: the retail loop addresses `self + 0x610 + n*0x1A0` downwards in steps of 4,
11 times, i.e. floats 0x5E8 + n*0x1A0 .. 0x610 + n*0x1A0 [confirmed arithmetic]. That is the 11
floats after the 11 `SePlayer`s of each group (matches the `E` struct in playStop).

`H` (0x14 bytes, constructor 0x391EB0, matched in src/race/unit_00391970/func_00391EB0.cpp):
two bytes (0, 1) cleared and four floats at +4..+0x10 set to 0.0f [confirmed].
0x391AF0 (matched) writes the same block with a position/flip state (`flipx`, `flipy`, then x,y,z), so
each `H` looks like a "last listener-relative position" record [inferred: the matched 391AF0
takes a pointer to such a block as 2nd argument and stores x/y/z and two flip bytes in it].

## playStart (0x3924D0, 368 bytes): not matched
- One-time init guarded by 0xB38 [confirmed]. Calls 0x391EB0 on 0x14, 0x2B8, 0x3F4 and the four
  groups [confirmed]; creates 2+1 objects with 0x559808, then 0x559470(obj, word, 0, 0) and
  0x559330(obj) on each [confirmed call order]. 0x559378 is called on the same pointers by playStop,
  so 0x559808 allocates and 0x559378 releases; 0x559470/0x559330 configure and start [inferred:
  pairing with playStop only, no names known].
- Zero stores use `mtc1 $zero,$fN` + `swc1` in down-counting loops with the counter in $v1 [confirmed].
- Best source reached 5 differing instructions of 92 (build/swarm/matheus/003924d0_best.cpp): only
  the order of the preheader instructions of the two zero loops differs.
- What the compiler needed [confirmed by the judge, not a match]:
  - Chained store `p[i] = t = 0.0f;` in an inline helper gives mtc1/swc1 (plain `= 0.0f` gives
    `sw $zero`; a held `f32 zero` local is folded).
  - The pointer arguments of 0x559470 must be pointer types (`Obj *`), otherwise the `lw a1` is
    scheduled above the `sw v0` store.
  - Group float address written `(a + b) + (int)self` with `n, g, b, a` declared in that order
    reproduces retail's three induction registers (s1 = 0x28+0x100n, s3 = 0x5E8+0xA0n, s0 = g).

## 0x392640 (2168 bytes): not matched, structure only
Judged state: no progress beyond the earlier draft (retail keeps self in $s5 and params in $fp;
the draft has them swapped and saves a different number of FPRs).
Facts seen in the disassembly [confirmed]: frame 0xF0; calls 0x391CD8 (master volume) multiplied by
the float at 0x6213E0 (RaceCarSound__external_volume_); three calls to 0x391AF0 with record indices
0, 2, 1 on self+0x14, self+0x3F4, self+0x2B8; SePlayer__Play (0x462A88) calls; 0x392EB8 for the
last 11 triggers.
Everything else in the draft (E8/E12 parameter structs, 0.025f/0.05f smoothing of the floats at
0x468 and the group floats, enable table at 0x88F2C0, trigger table at 0x621418, three position
slots in the params block) is [inferred] from reading that disassembly for the draft; it is not
validated by a match. The "turbo0..turbo3" reading of the four groups and any cockpit-camera
restriction are NOT established.

## The per-view parameter table behind the turbo blow-off level (v1.01 mapping)
Source of the lead: a modder (mat-garcia, Spec II build SCUS_974.36 with its own addresses) found that the
blow-off (BOV) level is `table[row][3] * 0.01 * <float in the car object>`, and that the table rows for the
exterior views hold 0 in slot 3, which closes the `0.001 <= level` gate. His addresses are not v1.01 ones;
the same structure was located in v1.01 (SCUS_973.28 + CORE.GT4) by shape. [confirmed] = read in the v1.01
disassembly or data; [inferred] = our reading.

| what | Spec II (his build) | v1.01 | status |
|---|---|---|---|
| static table, 5 rows x 24 shorts (48 bytes per row) | 0x00663800 | **0x00622330** | [confirmed] unique match of the row pattern |
| float table filled at run time (row*24+slot floats) | 0x0073F6E8 | **0x00845A10** (`D_00845A10`) | [confirmed] |
| getter `float f(row, slot)` | 0x002B2AF8 | **0x003F3A68** (`func_003F3A68`, matched) | [confirmed] |
| setter `void f(row, slot, float)` | 0x002B2B20 | **0x003F3A90** (`func_003F3A90`, matched) | [confirmed] |
| loader: 5 rows x 24 slots, `short * 0.01f` into the float table | 0x002B2B48 loop | **0x003F3AB8** (176 bytes, matched as `SetupBrakeHeatParameters`) | [confirmed] |
| caller that builds `level[band]` on its stack (0x2B0..0x2C8($sp)) | 0x0027E420 | **0x003B5E80** (2,944 bytes, unmatched) | [confirmed] shape: slot 3 and 5 come from the getter and are multiplied by a float in the car object |
| float in the car object ("how far the valve is open") | +0x524 | **+0x504** | [confirmed] `lwc1 $f1, 0x504($s4)` right after the slot-3 getter call at 0x003B65FC |

Values of slot 3 in v1.01 (the short, before `* 0.01`): row 0 = 1200, rows 1..3 = 0, row 4 = 400
[confirmed], the same pattern his build shows. Slot 5: row 0 = 400, rows 1..3 = 30, 150, 0 [confirmed].
Which view uses which row is not established here (row index `s3` in 0x003B5E80 comes from
`func_003FA910`) [unknown].

Names do not agree: GT HD (medium confidence) calls the loader `SetupBrakeHeatParameters` and 0x003B5E80
`pglMatrixMode`, but the loader fills a table read by a sound-level calculation, and 0x003B5E80 is a large
per-frame function that computes the levels, so at least the second name looks wrong [inferred]. The table
may be a general per-view parameter table that more than one system reads; slot 3 may feed other turbo
sounds besides the blow-off [unknown].

## Spec II (SCUS_974.36) call chain reported by mat-garcia (live debugging, 2026-10-22)

All addresses below are Spec II; the v1.01 column is our inference from shape, not checked.

| role | Spec II | v1.01 |
|---|---|---|
| per-car sound update, called through a vtable from 0x283B48 and 0x2980F8 | 0x001E8B80 (call at 0x1E8C6C) | unknown; same code region as RacePS2Base::updateVolume (Spec II 0x1EC328) [inferred] |
| builds level[band] (slot 3 table row x car float) | 0x0027E420 | 0x003B5E80 [confirmed in the table above] |
| band loop (14 bands): gate `0.001 <= level`, then Play | 0x00273480 | 0x00392640 [inferred: it is the voice-group updater that reaches 0x392EB8] |
| `if (x*y != 0) SePlayer::Play` | 0x00273D48 | 0x00392EB8 [matched in this repo] |
