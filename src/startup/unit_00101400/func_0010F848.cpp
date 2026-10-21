/* Reads the word at +0x39D78 of the object that global D_00622F4C points to and calls func_003C0C40(self, value ^ 1, 0). */
#include "types.h"

struct Obj;

extern "C" void func_003C0C40(struct Obj *arg0, s32 arg1, s32 arg2);
extern "C" void *D_00622F4C;

struct func_0010F848_D_00622F4C {
    char pad0[0x39D78];
    s32 unk39D78;
};

extern "C" void func_0010F848(struct Obj *self) {
    s32 flag = ((struct func_0010F848_D_00622F4C *)D_00622F4C)->unk39D78;
    func_003C0C40(self, flag ^ 1, 0);
}
