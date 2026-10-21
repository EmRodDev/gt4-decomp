/* Shutdown helper: clears the field at +0xAC if set, calls func_0054F5E0(0, LLONG_MAX) (the maximum signed 64-bit value, written as the logical shift of -1) and, when the object at +0xB4 exists, passes it to func_0054ED08 with 1.
 * What the callees do is unknown. */
#include "types.h"

struct Obj {
    char p0[0xAC];
    s32 fAC;
    s32 fB0;
    s32 fB4;
};

extern "C" s32 func_0054ED08(char *obj, s32 arg1);
extern "C" void func_0054F5E0(long obj, long arg1);

extern "C" void func_001FE558(Obj *obj) {
    if (obj->fAC != 0) {
        obj->fAC = 0;
    }
    func_0054F5E0(0, (long)((unsigned long)-1 >> 1));
    s32 resource = obj->fB4;
    if (resource != 0) {
        func_0054ED08((char *)resource, 1);
    }
}
