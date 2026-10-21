/* Wrapper: if the field at +0x14 is zero it first calls func_00473638 (a lazy setup step, inferred from the zero test), then
 * forwards its four arguments to func_0049C6C8 with a trailing 0. Sibling of func_004732F0, which has the same guard. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_0049C6C8(s32, s32, s32, s32, s32); /* extern */

struct func_00472F90_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00472F90(void *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (((struct func_00472F90_arg0 *)self)->unk14 == 0) {
        func_00473638();
    }
    func_0049C6C8(arg1, arg2, arg3, arg4, 0);
}
