/* Converts raw tuning bytes into floats, once. The block at D_00620CD8 holds a guard byte at +0xCC (zero = not yet
 * converted, set to 1 at the end, inferred from the check and store) followed by bytes at +0xD0..+0xD8. Each byte
 * becomes a float in params: bytes D1, D4 and D6 are multiplied by the hex float 0x1.0624DCp-10 (0.001) into
 * params +4, +0x10 and +0x18; bytes D0, D2, D3, D7 and D8 are multiplied by 100000 into params +0, +8, +0xC and
 * +0x1C/+0x20 (+0 is negated, +0xC also gets +8 added); byte D5 times 100000 is negated and halved into +0x14.
 * What the nine values are is unknown. +0xC is stored twice (before and after the addition) because that is the
 * store order the compiler produces here. */
#include "types.h"

extern char D_00620CD8[];

struct func_00350678_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct func_00350678_src {
    char pad0[0xCC];
    u8 converted;
    char padCD[3];
    u8 unkD0;
    u8 unkD1;
    u8 unkD2;
    u8 unkD3;
    u8 unkD4;
    u8 unkD5;
    u8 unkD6;
    u8 unkD7;
    u8 unkD8;
};

extern "C" void func_00350678(struct func_00350678_arg0 *params) {
    struct func_00350678_src *config;
    f32 t0;
    f32 t1;
    f32 t2;

    config = (struct func_00350678_src *)D_00620CD8;
    if (config->converted == 0) {
        params->unk4 = (f32)config->unkD1 * 0x1.0624DCp-10f;
        params->unk0 = -(f32)((s32)config->unkD0 * 100000);
        t0 = (f32)((s32)config->unkD2 * 100000);
        params->unk8 = t0;
        t1 = (f32)((s32)config->unkD3 * 100000);
        params->unkC = t1;
        t1 = t1 + t0;
        t2 = (f32)config->unkD4;
        params->unkC = t1;
        params->unk10 = t2 * 0x1.0624DCp-10f;
        params->unk18 = (f32)config->unkD6 * 0x1.0624DCp-10f;
        params->unk14 = -(f32)((s32)config->unkD5 * 100000) * 0.5f;
        params->unk1C = (f32)((s32)config->unkD7 * 100000);
        params->unk20 = (f32)((s32)config->unkD8 * 100000);
        config->converted = 1;
    }
}
