/* Resets the draw state of the script engine's context (+0x6E14): clears the flag at +0x6E34 and sets three modes through
 * func_00473620 (0,0,0), func_00473608 (3, 0x80, 0xFF) and func_00473538 (1,1,1,1). The meaning of the values is unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473538(s32, s32, s32, s32, s32); /* extern */
s32 func_00473608(s32, s32, s32, s32); /* extern */
s32 func_00473620(s32, s32, s32, s32); /* extern */

struct func_00474750_arg0 {
    char pad0[0x6E14];
    s32 unk6E14;
    char pad6E18[0x1C];
    s32 unk6E34;
};

void func_00474750(void *self) {
    ((struct func_00474750_arg0 *)self)->unk6E34 = 0;
    func_00473620(((struct func_00474750_arg0 *)self)->unk6E14, 0, 0, 0);
    func_00473608(((struct func_00474750_arg0 *)self)->unk6E14, 3, 0x80, 0xFF);
    func_00473538(((struct func_00474750_arg0 *)self)->unk6E14, 1, 1, 1, 1);
}
