/* Returns whether the u16 element at index `index` of an array starting at +0x94 of the object is >= the s16 field at +0xA4.
 * The element is addressed as object + index*2 + 0x94 (so the u16 array is inline in the object); the meaning of the compare is unknown. */
#include "types.h"

struct Elem {
    char pad[0x94];
    u16 unk94;
};

struct Obj {
    char pad[0xA4];
    s16 unkA4;
};

extern "C" s32 func_00251860(Obj *obj, s32 index) {
    s32 byteOffset = index * 2;
    Elem *elem = (Elem *)(byteOffset + (s32)obj);
    return elem->unk94 >= obj->unkA4;
}
