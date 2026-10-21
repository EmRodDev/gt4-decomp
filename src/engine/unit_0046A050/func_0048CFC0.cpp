/* Replaces a 2D vector (x, y floats) with the result of func_0048CF78(arg, vector). The copy constructor and operator= are spelled out
 * because the compiled code copies the returned struct through a hidden return slot. */
#include "types.h"

struct Vec2 {
    f32 x, y;
    Vec2() {}
    Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
    Vec2 &operator=(const Vec2 &o) { x = o.x; y = o.y; return *this; }
};

extern "C" Vec2 func_0048CF78(s32, const Vec2 &);

extern "C" void func_0048CFC0(Vec2 *self, s32 arg) {
    *self = func_0048CF78(arg, *self);
}
