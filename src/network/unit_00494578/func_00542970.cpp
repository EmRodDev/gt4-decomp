/* Releases the four sub-objects at +0xC, +0x10, +0x14 and +0x18 of the object when each is set (func_00538C68), then the object pointer itself. Cleanup/destroy helper; the type is not determined. buf0 is the compiler's saved copy of arg0. */
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

extern "C" void func_00538C68(void *);

struct func_00542970_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00542970(s32 *object) {
    s32 savedObject[4];
    savedObject[0] = (s32)object;
    if (object != 0) {
        if (((struct func_00542970_arg0 *)object)->unkC != 0) {
            func_00538C68((char *)object + 0xc);
        }
        if (((struct func_00542970_arg0 *)object)->unk18 != 0) {
            func_00538C68((char *)object + 0x18);
        }
        if (((struct func_00542970_arg0 *)object)->unk10 != 0) {
            func_00538C68((char *)object + 0x10);
        }
        if (((struct func_00542970_arg0 *)object)->unk14 != 0) {
            func_00538C68((char *)object + 0x14);
        }
        func_00538C68(savedObject);
    }
}
