/* Copies an 8-byte value (two 32-bit words) from 'source' to 'dest' and returns dest: the assignment-operator twin of func_0048F280. */
#include "types.h"
struct Obj {
    s32 unk0;
    s32 unk4;
};
extern "C" Obj *func_0048F298(Obj *dest, Obj *source) {
    dest->unk0 = source->unk0;
    dest->unk4 = source->unk4;
    return dest;
}
