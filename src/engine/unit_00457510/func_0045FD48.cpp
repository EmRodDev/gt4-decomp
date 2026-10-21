/* Relocation fix-up after a block was moved (inferred): the block's self pointer at +4 is replaced by its new address and the 32
 * pointer words from +0x90 are shifted by the same difference. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
struct func_0045FD48_arg0 {
    char pad0[0x4];
    void *unk4;
};

void func_0045FD48(char *self) {
    s32 *word;
    s32 remaining;
    char *oldBase;

    oldBase = (char *)(((struct func_0045FD48_arg0 *)self)->unk4);
    word = (s32 *)(self + 0x90);
    ((struct func_0045FD48_arg0 *)self)->unk4 = self;
    remaining = 0x1F;
    do {
        remaining -= 1;
        *word += self - oldBase;
        word += 1;
    } while (remaining >= 0);
}

}
