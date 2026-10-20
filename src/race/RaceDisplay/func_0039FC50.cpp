#include "types.h"

struct Inner0039FC50 {
    char pad0[0xDC];
    s32 unkDC;
};

struct Obj0039FC50 {
    char pad0[0x4];
    struct Inner0039FC50 *unk4;
    char pad1[0x3C - 0x8];
    u8 unk3C;
    char pad3D[0x1170 - 0x3D];
    char unk1170[1];
};

extern "C" void func_003A3A00(void *arg0);

extern "C" void func_0039FC50(struct Obj0039FC50 *arg0) {
    if (arg0->unk3C != 0 && arg0->unk4->unkDC == 0) {
        func_003A3A00(arg0->unk1170);
    }
}
