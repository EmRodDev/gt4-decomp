/* Teardown sequence: runs func_0023FA58 on the object, releases the handle stored at +0x10 with func_002C3BA0 and calls func_00460B90.
 * What each step does is unknown; the order is what the original does. */
#include "types.h"

struct S {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_0023FA58(struct S *obj);
extern "C" void func_002C3BA0(s32 obj);
extern "C" void func_00460B90(void);

extern "C" void func_0023F890(struct S *obj) {
    struct S *self = obj;
    func_0023FA58(self);
    func_002C3BA0(self->unk10);
    func_00460B90();
}
