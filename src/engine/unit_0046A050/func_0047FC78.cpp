/* Initialiser (class unknown): constructs the member at +0x8C, sets the fields at 0x6C/0x70/0x74/0x78 to 0, 0, 1, 0 and finishes with
 * func_00480100 and func_0047FEC0 on the same argument. */
extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047FEC0(...) throw();
void func_00480100(...) throw();
s32 func_004816F8(...) throw();

struct func_0047FC78_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
};

void func_0047FC78(char *self, s32 initArg) {
    func_004816F8(self + 0x8C, self);
    ((struct func_0047FC78_arg0 *)self)->unk6C = 0;
    ((struct func_0047FC78_arg0 *)self)->unk74 = 1;
    ((struct func_0047FC78_arg0 *)self)->unk70 = 0;
    ((struct func_0047FC78_arg0 *)self)->unk78 = 0;
    func_00480100(self, initArg);
    func_0047FEC0(self, initArg);
}

}
