/* Returns the float at +0x2D4 clamped to be at least zero (uses the EE max.s instruction, hence the inline asm helper). */
#include "types.h"

struct Obj { char pad[0x2D4]; f32 unk2D4; };

static inline f32 max_s(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" f32 func_00120518(Obj *self) {
    return max_s(self->unk2D4, 0.0f);
}
