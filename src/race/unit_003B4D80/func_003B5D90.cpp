/* Resets the sub-object at +0x2900 with 003923A0 and, the first time only (flag at +0x28FC, named isSetUp here because it is set to 1
 * after the one-time step; inferred), fills it from two values that 00445518 and 00445548 read from the part at +0x20. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_003923A0(void *);
extern "C" s32 func_00445518(void *);
extern "C" s32 func_00445548(void *);
extern "C" void func_003923D0(void *, s32, s32);

struct func_003B5D90_arg0 {
    char pad0[0x28FC];
    s32 isSetUp;
};

extern "C" void func_003B5D90(s32 *self) {
    char *subObject;
    char *source;
    s32 firstValue;
    subObject = (char *)self + 0x2900;
    source = (char *)self + 0x20;
    func_003923A0(subObject);
    if (((struct func_003B5D90_arg0 *)self)->isSetUp == 0) {
        firstValue = func_00445518(source);
        func_003923D0(subObject, firstValue, func_00445548(source));
        ((struct func_003B5D90_arg0 *)self)->isSetUp = 0x1;
    }
}
