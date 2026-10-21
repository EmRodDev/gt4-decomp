/* Copies a 4x4 float matrix (16 floats) from src into the one embedded at +0xE36C of self. The element order follows the
 * compiler's scheduling, not a transposition. */
#include "types.h"

struct func_005F3C98_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};
struct func_005F3C98_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

void func_005F3C98(struct func_005F3C98_arg0 *self, struct func_005F3C98_arg1 *src) {
    struct func_005F3C98_arg0 *dst = (struct func_005F3C98_arg0 *)((char *)self + 0xE36C);
    dst->unk0 = src->unk0;
    dst->unk10 = src->unk10;
    dst->unk20 = src->unk20;
    dst->unk30 = src->unk30;
    dst->unk4 = src->unk4;
    dst->unk14 = src->unk14;
    dst->unk24 = src->unk24;
    dst->unk34 = src->unk34;
    dst->unk8 = src->unk8;
    dst->unk18 = src->unk18;
    dst->unk28 = src->unk28;
    dst->unk38 = src->unk38;
    dst->unkC = src->unkC;
    dst->unk1C = src->unk1C;
    dst->unk2C = src->unk2C;
    dst->unk3C = src->unk3C;
}
