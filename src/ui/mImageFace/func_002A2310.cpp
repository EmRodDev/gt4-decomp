/* Resizes the image face to the size reported by one of its own virtual methods (vtable offset 0x1B8, which writes two floats: width and height, inferred from func_0025B4C8 taking them as new size).
 * The entry carries a this-adjustment (delta) like a multiple-inheritance thunk, which is why `this` is shifted before the call. */
#include "types.h"

struct Widget;

struct Widget {
    char pad[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, f32 *, f32 *);
};

struct Vec2 {
    f32 x;
    f32 y;
};

extern "C" void func_0025B4C8(struct Widget *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_002A2310(struct Widget *self) {
    struct Vec2 size;
    VEntry *entry = (VEntry *)(self->vtbl + 0x1B8);
    entry->fn((char *)self + entry->delta, &size.x, &size.y);
    func_0025B4C8(self, size.x, size.y);
}
