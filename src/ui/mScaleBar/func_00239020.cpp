/* Stores `requested` clamped to [min, max] into the scale bar's current value at +0xC4. min is the float at +0xC8 and max the one at +0xCC (field roles inferred from the clamp; the fields keep their offsets in their names). */
#include "types.h"

struct Obj {
    char pad[0xC4];
    f32 valueC4;
    f32 minValueC8;
    f32 maxValueCC;
};

extern "C" void func_00239020(Obj *bar, f32 requested) {
    f32 clamped = requested;
    if (clamped < bar->minValueC8) {
        clamped = bar->minValueC8;
    }
    if (bar->maxValueCC < clamped) {
        clamped = bar->maxValueCC;
    }
    bar->valueC4 = clamped;
}
