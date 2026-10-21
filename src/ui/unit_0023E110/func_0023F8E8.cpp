/* Calls func_002C3BE0 with the handle at +0x10 and the name `arg1`, but only when func_0057F238 says `arg1` matches the string D_00698EF0.
 * func_0057F238 looks like a string comparison (inferred from its use with the literal "keep" in func_0023F938). */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C3BE0(s32, s32);                    /* extern */
s32 func_0057F238(s32, s32);                    /* extern */

extern char D_00698EF0[];
struct func_0023F8E8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0023F8E8(void *obj, s32 name) {
    if (func_0057F238(name, (s32)D_00698EF0) != 0) {
        func_002C3BE0(((struct func_0023F8E8_arg0 *)obj)->unk10, name);
    }
}
