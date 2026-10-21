/* Scales two pairs of floats of the embedded record at +0x10: the pair (+0x0, +0x4) by the first factor and the pair (+0xC, +0x10) by the second.
 * The record is probably a rectangle or two 2D points, scaled in place (inferred from the pairing); its meaning is unknown. */
#include "types.h"

struct Inner0024BE78 {
    f32 unk0;
    f32 unk4;
    char pad8[4];
    f32 unkC;
    f32 unk10;
};

struct Obj0024BE78 {
    char pad[0x10];
    struct Inner0024BE78 inner;
};

extern "C" void func_0024BE78(struct Obj0024BE78 *obj, f32 factorA, f32 factorB) {
    struct Inner0024BE78 *rec = &obj->inner;
    rec->unk0 = rec->unk0 * factorA;
    rec->unkC = rec->unkC * factorB;
    rec->unk4 = rec->unk4 * factorA;
    rec->unk10 = rec->unk10 * factorB;
}
