/* When arg1 is non-zero, calls func_0048F4E0 on the first member and func_0048F548 (with arg1) on the second, each only when non-null. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0048F4E0(s32);                         /* extern */
s32 func_0048F548(s32, s32);                    /* extern */

struct func_0048F5B0_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_0048F5B0(void *self, s32 arg1) {
    s32 first;
    s32 second;

    if (arg1 != 0) {
        first = ((struct func_0048F5B0_arg0 *)self)->unk0;
        if (first != 0) {
            func_0048F4E0(first);
        }
        second = ((struct func_0048F5B0_arg0 *)self)->unk4;
        if (second != 0) {
            func_0048F548(second, arg1);
        }
    }
}
