/* Boolean test on the flag word at +0x98, the same word whose low nibble func_00266060..func_002661D8 write.
 * Returns 0 when func_00265E40 is false; otherwise combines the nibbles at bits 0-3, 4-7 and 8-11: if the third nibble is nonzero it is true when nibbles 1 and 2 agree on none of its bits,
 * else if the second is nonzero it is true when it shares a bit with the first, else true. The meaning of the nibbles is unknown. */
#include "types.h"

struct Obj {
    char pad[0x98];
    u32 flags;
};

extern "C" s32 func_00265E40(Obj *obj);

extern "C" s32 func_00265DC8(Obj *obj) {
    s32 precondition = func_00265E40(obj);
    if (precondition == 0) {
        return 0;
    }
    u32 bits = obj->flags;
    if (bits & 0xF00) {
        u32 agreeBits = ((bits >> 4) ^ bits) & (bits >> 8) & 0xF;
        return agreeBits == 0;
    }
    if (bits & 0xF0) {
        u32 sharedBits = (bits >> 4) & bits & 0xF;
        return sharedBits != 0;
    }
    return 1;
}
