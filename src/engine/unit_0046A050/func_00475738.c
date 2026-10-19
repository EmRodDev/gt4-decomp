#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void func_00480638(void *, s32);                /* extern */

struct func_00475738_arg0 {
    void *unk0;
    char pad4[0x18];
    f32 unk1C;
};

/* Forwards its second argument unchanged to the callee. */
void func_00475738(struct func_00475738_arg0 *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = arg0->unk0;
    if (temp_v0 != 0) {
        func_00480638(temp_v0, arg1);
        arg0->unk1C = 1.0f;
    }
}
