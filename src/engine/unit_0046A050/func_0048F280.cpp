/* Copies an 8-byte value (two 32-bit words) from 'source' to 'dest'. Runtime code (for example func_005D9310) uses it as the copy
 * constructor of a small value type, which is where its shape comes from. func_0048F298 is the same copy that returns dest. */
#include "types.h"
struct Obj {
    s32 unk0;
    s32 unk4;
};
extern "C" void func_0048F280(Obj *dest, Obj *source) {
    dest->unk0 = source->unk0;
    dest->unk4 = source->unk4;
}
