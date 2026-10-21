/* Stores a pair of floats (src->unk0, src->unk4) into slot `slot` of an inline array of 8-byte entries starting at +0xCC of the object.
 * What the pair represents is unknown. */
#include "types.h"

struct Dst {
    f32 unk0;
    f32 unk4;
};

struct Src {
    f32 unk0;
    f32 unk4;
};

extern "C" void func_002A3800(char *obj, s32 slot, Src *src) {
    Dst *dst = (Dst *)(obj + slot * 8 + 0xCC);
    dst->unk0 = src->unk0;
    dst->unk4 = src->unk4;
}
