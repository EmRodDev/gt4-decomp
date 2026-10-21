/* Wrapper: if the field at +0x14 is zero it first calls func_00473638 (a lazy setup step, inferred from the zero test), then
 * forwards (arg2, arg1) to func_0049E2D8 with the two arguments swapped. Sibling of func_00472F90, which has the same guard. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_0049E2D8(s32, s32);                    /* extern */

struct func_004732F0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_004732F0(void *self, s32 arg1, s32 arg2) {
    if (((struct func_004732F0_arg0 *)self)->unk14 == 0) {
        func_00473638();
    }
    func_0049E2D8(arg2, arg1);
}
