/* Teardown/release sequence: runs func_0023F890, func_00460B70, then func_002C3B60 on the handle at +0x10 together with the second argument.
 * Companion of func_0023F890 in the same unit; what the callees do is unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0023F890();                            /* extern */
s32 func_002C3B60(s32, s32);                    /* extern */
s32 func_00460B70();                            /* extern */

struct func_0023F848_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0023F848(void *obj, s32 value) {
    func_0023F890();
    func_00460B70();
    func_002C3B60(((struct func_0023F848_arg0 *)obj)->unk10, value);
}
