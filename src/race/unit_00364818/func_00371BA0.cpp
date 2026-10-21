/* Returns a value in hundredths read from a sub-object: the object is found through virtual slot 0xD8 (index kept at +0x9BC) and its
 * virtual slot 0x110 gives an integer that is divided by 100. Defaults to 8.0 when there is no sub-object. Meaning unknown. */
#include "types.h"

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntry110 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" f32 func_00371BA0(char *self) {
    f32 result = 8.0f;
    void *obj;
    VEntryD8 *findSlot;

    findSlot = (VEntryD8 *)(*(char **)self + 0xD8);
    obj = findSlot->fn(self + findSlot->delta, *(s32 *)(self + 0x9BC));
    if (obj != 0) {
        VEntry110 *valueSlot = (VEntry110 *)(*(char **)obj + 0x110);
        s32 hundredths = valueSlot->fn((char *)obj + valueSlot->delta);
        result = (f32)hundredths / 100.0f;
    }
    return result;
}
