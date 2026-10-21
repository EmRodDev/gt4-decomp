/* Returns a float from the currently selected element: elements are 0x16C bytes each, stored inline from offset 0, the index of the
 * current one is at +0x2DC, and inside the element the value is entry 'index' of an array of 0x34-byte records starting at +0x58
 * (same element layout as func_0045AD40, which reads +0x128). What the float is is unknown. */
#include "types.h"
struct Obj {
    char pad[0x2DC];
    s32 currentIndex;
};
extern "C" f32 func_0045ABD0(Obj *self, s32 index) {
    char *element = (char *)self + self->currentIndex * 0x16C;
    return *(f32 *)(element + index * 0x34 + 0x58);
}
