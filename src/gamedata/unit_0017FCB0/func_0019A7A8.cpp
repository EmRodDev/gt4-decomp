/* Teardown-shaped (inferred): releases the object held at +0xA0 with func_001C95B0 (mode 3), clears the pointer, then runs func_005CD8E8 on the
 * sub-object at +0xA4. */
#include "types.h"

struct Vec;

extern "C" {
void func_001C95B0(void *self, s32 arg1);      /* extern */
void func_005CD8E8(Vec *v);                    /* extern */

struct func_0019A7A8_arg0 {
    char pad0[0xA0];
    void *unkA0;
    char pad1[0x4];
    char unkA4[0];
};

void func_0019A7A8(void *self) {
    void **slot = &((struct func_0019A7A8_arg0 *)self)->unkA0;
    void *held;

    held = *slot;
    if (held != 0) {
        func_001C95B0(held, 3);
    }
    *slot = 0;
    func_005CD8E8((Vec *)((char *)self + 0xA4));
}
}
