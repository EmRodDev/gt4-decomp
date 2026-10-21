/* When either value is non-zero, stores the pair at +0x34/+0x38 and at +0xC/+0x10. In every case then calls
 * func_004A0BB0 with the current pair at +0xC/+0x10. Field purposes unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A0BB0(s32, s32);                    /* extern */

struct func_00106258_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    char pad14[0x20];
    s32 unk34;
    s32 unk38;
};

void func_00106258(void *self, s32 valueA, s32 valueB) {
    if ((valueA != 0) || (valueB != 0)) {
        ((struct func_00106258_arg0 *)self)->unk34 = valueA;
        ((struct func_00106258_arg0 *)self)->unk38 = valueB;
        ((struct func_00106258_arg0 *)self)->unkC = valueA;
        ((struct func_00106258_arg0 *)self)->unk10 = valueB;
    }
    func_004A0BB0(((struct func_00106258_arg0 *)self)->unkC, ((struct func_00106258_arg0 *)self)->unk10);
}
