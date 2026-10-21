/* Asks the object linked at +4 (virtual call, slot 6 of its vtable at +0x10140, with the usual this-adjustment) and, if the
 * answer is non-zero, returns whether the upper 16 bits of the word at +0x104+0x464 are zero. Otherwise returns 0. */
#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Mid {
    char pad[0x10140];
    VEntry *vtbl;
};

struct Obj {
    char pad0[4];
    Mid *f4;
};

extern "C" s32 func_00359AF0(Obj *self) {
    s32 result = 0;
    char *state = (char *)self + 0x104;
    Mid *mid = self->f4;
    VEntry *entry = mid->vtbl + 6;
    if (entry->fn((char *)mid + entry->delta)) {
        result = (*(s32 *)(state + 0x464) & 0xFFFF0000) == 0;
    }
    return result;
}
