/* mInputTextFace member (class taken from the directory): stores the value at +0x168 and forwards the same value to the
 * embedded sub-object at +0x578 (callee func_004B6C60). Purpose of both fields unknown. */
#include "types.h"

struct S002A6C98 {
    char pad0[0x168];
    s32 unk168;
};

extern "C" void func_004B6C60(void *sub, s32 value);

extern "C" void func_002A6C98(struct S002A6C98 *self, s32 value) {
    self->unk168 = value;
    func_004B6C60((char *)self + 0x578, value);
}
