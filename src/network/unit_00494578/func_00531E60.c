#include "types.h"
void func_00531E60(char *arg0, s32 arg1) {
    if ((u32)arg1 >= 0x40U) return;
    if (arg1 < *(s32 *)(arg0 + 8)) *(s32 *)(arg0 + 8) = arg1;
    if (*(s32 *)(arg0 + 0xC) < arg1) *(s32 *)(arg0 + 0xC) = arg1;
    *(u8 *)(arg0 + (arg1 >> 3)) |= 1 << (arg1 & 7);
}
