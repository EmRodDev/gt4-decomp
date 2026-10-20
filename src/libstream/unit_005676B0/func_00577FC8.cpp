#include "types.h"
struct Obj00577FC8 {
    char pad0[0x24];
    s32 unk24;
};
extern "C" void func_00577F80(void);
extern "C" s32 func_005B17D0(Obj00577FC8 *self, s32 arg1, s32 arg2);

extern "C" void func_00577FC8(Obj00577FC8 *self, s32 arg1, s32 arg2) {
    self->unk24 = 0;
    for (;;) {
        while (func_005B17D0(self, arg1, arg2) < 0) {
            func_00577F80();
        }
        if (self->unk24 != 0) {
            return;
        }
        func_00577F80();
        if (self->unk24 != 0) {
            return;
        }
    }
}
