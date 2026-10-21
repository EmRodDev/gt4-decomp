/* Returns the float at +0x128 of the currently selected element. The elements are 0x16C bytes each, stored inline in the object from
 * offset 0, and the index of the current one is at +0x2DC. What the float is is unknown (purpose unknown). */
#include "types.h"

struct Elem {
    char pad[0x128];
    f32 unk128;
};

struct Obj {
    char pad[0x2DC];
    s32 currentIndex;
};

extern "C" f32 func_0045AD40(Obj *self) {
    return ((Elem *)((char *)self + self->currentIndex * 0x16C))->unk128;
}
