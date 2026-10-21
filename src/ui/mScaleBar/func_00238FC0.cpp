/* Stores the argument clamped to [min, max] into the field at +0xE4; min is the float at +0xC8 and max the one at +0xCC (roles inferred from the clamp).
 * Same clamp as func_00239020 (+0xC4) and func_00238FF0 (+0xE8). */
#include "types.h"

struct Obj {
    char pad0[0xC8];
    f32 unkC8;
    f32 unkCC;
    char pad1[0xE4 - 0xD0];
    f32 unkE4;
};

extern "C" void func_00238FC0(Obj *bar, f32 requested) {
    f32 clamped = requested;
    f32 minValue = bar->unkC8;
    if (clamped < minValue) {
        clamped = minValue;
    }
    f32 maxValue = bar->unkCC;
    if (maxValue < clamped) {
        clamped = maxValue;
    }
    bar->unkE4 = clamped;
}
