/* Frees the three heap blocks held at +0x734 and zeroes the slots, then clears the field at +8. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 free(s32);                         /* extern */

struct func_00470D60_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_00470D60(char *self) {
    s32 *slot;
    s32 block;
    s32 remaining;

    slot = (s32 *)(self + 0x734);
    remaining = 2;
    do {
        block = *slot;
        if (block != 0) {
            free(block);
        }
        remaining -= 1;
        *slot = 0;
        slot += 1;
    } while (remaining >= 0);
    ((struct func_00470D60_arg0 *)self)->unk8 = 0;
}

}
