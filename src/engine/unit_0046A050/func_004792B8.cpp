/* Brackets func_004743F8 with the func_004A53F8 / func_004A5400 pair (func_003821F0 also wraps its matrix set-up in this pair, so it is
 * probably a push/pop of the render state; inferred), after passing the area at +0x6E3C to func_004A74B4. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_004743F8(s32, s32);                    /* extern */
s32 func_004A53F8();                            /* extern */
s32 func_004A5400();                            /* extern */
s32 func_004A74B4(s32);                         /* extern */

struct func_004792B8_arg0 {
    char pad0[0x6E14];
    s32 unk6E14;
    char pad6E18[0x8];
    s32 unk6E20;
};

void func_004792B8(char *self) {
    func_004A53F8();
    func_004A74B4((s32)(self + 0x6E3C));
    func_004743F8(((struct func_004792B8_arg0 *)self)->unk6E20, ((struct func_004792B8_arg0 *)self)->unk6E14);
    func_004A5400();
}

}
