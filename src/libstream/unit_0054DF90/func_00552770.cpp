/* Deleting destructor shape: stores the class's vtable pointer (D_006898D8) at +0x68, runs the base-class destructor func_005659F8, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
#include "types.h"

extern "C" void func_005659F8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006898D8;

struct func_00552770_arg0 {
    char pad0[0x68];
    void *unk68;
};

extern "C" void func_00552770(struct func_00552770_arg0 *self, s32 deleteFlag) {
    self->unk68 = &D_006898D8;
    func_005659F8(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
