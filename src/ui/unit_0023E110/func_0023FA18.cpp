/* Calls func_0023FA58 and then func_002C3CA8 with the handle at +0x10 of the object and the second argument. Companion of func_0023F890/func_0023F9C0 in the same unit; the purpose of the callees is unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0023FA58();                            /* extern */
s32 func_002C3CA8(s32, s32);                    /* extern */

struct func_0023FA18_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0023FA18(void *obj, s32 value) {
    func_0023FA58();
    func_002C3CA8(((struct func_0023FA18_arg0 *)obj)->unk10, value);
}
