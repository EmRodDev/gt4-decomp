/* Stores the argument clamped to [min, max] into the field at +0xE8; min is the float at +0xC8 and max the one at +0xCC (roles inferred from the clamp).
 * Same clamp as func_00239020, which writes +0xC4 instead. */
#include "types.h"

struct Obj {
    char pad[0xC8];
    f32 minValueC8;
    f32 maxValueCC;
    char pad2[0xE8 - 0xD0];
    f32 unkE8;
};

extern "C" void func_00238FF0(Obj *bar, f32 requested) {
    f32 clamped = requested;
    if (clamped < bar->minValueC8) {
        clamped = bar->minValueC8;
    }
    if (bar->maxValueCC < clamped) {
        clamped = bar->maxValueCC;
    }
    bar->unkE8 = clamped;
}
