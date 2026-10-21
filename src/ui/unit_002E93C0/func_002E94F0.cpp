/* Calls func_00263B80 with the last two arguments in the given order when the field at +0xC4 is nonzero and swapped otherwise: the flag mirrors a pair (inferred from the swap). */
#include "types.h"

extern "C" void func_00263B80(s32 obj, s32 a, s32 b);

struct D_Obj {
    char pad[0xC4];
    s32 unkC4;
};

extern "C" void func_002E94F0(D_Obj *obj, s32 a, s32 b, s32 c) {
    if (obj->unkC4 != 0) {
        func_00263B80(a, b, c);
    } else {
        func_00263B80(a, c, b);
    }
}
