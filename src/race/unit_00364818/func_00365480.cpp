/* Loads the seven tuning bytes stored at +0xF818 into floats (inferred from the scale factors): three values per group are scaled
 * by 0.01, 10.0 and 0.01 (two groups), and the last one is a percentage (0 means 100) times 0.01. With enable == 0 the groups are
 * zeroed and the final scale is 1.0. What the settings control is unknown. */
#include "types.h"

struct func_00365480_arg0 {
    char pad0[0x7C];
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
};

struct func_00365480_src {
    char pad0[0x20];
    u8 unk20;
    char pad21[3];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    char pad27[1];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
};

extern "C" void func_00365480(struct func_00365480_arg0 *self, int enable) {
    struct func_00365480_src *src;
    int percent;

    if (enable != 0) {
        src = (struct func_00365480_src *)((char *)self + 0xF818);
        self->unk80 = (f32)src->unk25;
        self->unk84 = (f32)src->unk26 * 0x1.4000000000000p+3f;
        self->unk7C = (f32)src->unk24 * 0x1.47ae140000000p-7f;
        self->unk8C = (f32)src->unk29;
        self->unk90 = (f32)src->unk2A * 0x1.4000000000000p+3f;
        self->unk88 = (f32)src->unk28 * 0x1.47ae140000000p-7f;
        percent = src->unk20;
        if (percent == 0) {
            percent = 100;
        }
        self->unk94 = (f32)percent * 0x1.47ae140000000p-7f;
        return;
    }
    self->unk94 = 0x1.0000000000000p+0f;
    *(s32 *)&self->unk84 = 0;
    *(s32 *)&self->unk7C = 0;
    *(s32 *)&self->unk8C = 0;
    *(s32 *)&self->unk90 = 0;
    *(s32 *)&self->unk88 = 0;
    *(s32 *)&self->unk80 = 0;
}
