#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0069A5B8[];
extern char D_00668308[];
s32 func_00241C90(s32);
void func_00240398(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_00276810(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x14, 4, D_0069A5B8);
    func_00241C90(temp_v0);
    *(s32 *)(temp_v0 + 4) = (s32)D_00668308;
    sp[0] = temp_v0;
    func_00240398(arg0, sp);
}
