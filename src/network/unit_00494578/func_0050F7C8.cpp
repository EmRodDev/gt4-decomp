#include "types.h"

struct Obj_0064A55C {
    char pad[0x20];
    s32 (*unk20)(struct Obj_0064A55C *self);
};

extern "C" Obj_0064A55C *D_0064A55C;
extern "C" void func_0057D9C0(const char *msg);

extern "C" s32 func_0050F7C8(void) {
    Obj_0064A55C *temp_a0;

    temp_a0 = D_0064A55C;
    if (temp_a0->unk20(temp_a0) != 0) {
        func_0057D9C0("failed to clear ProductCache\n");
    }
    return 0;
}
