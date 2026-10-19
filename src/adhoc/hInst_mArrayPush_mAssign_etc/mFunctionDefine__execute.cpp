#include "types.h"

/* Layout backed by config/class_layout.json (mFunctionDefine size 0x10):
 *   0x00..0x07: base
 *   0x08: sym_id
 *   0x0C: unkC (function code pointer)
 */
struct mFunctionDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    s8 *unkC;
};

extern "C" s32 func_002F47F0(s8 *arg0);
extern "C" void func_002F4848(s8 *arg0, s32 arg1);
extern "C" void func_003067C0(s32 arg0, void *arg1, void *arg2);
extern "C" s32 func_00322060(void *arg0);

extern "C" void mFunctionDefine__execute(void *arg0, void *arg1) {
    mFunctionDefineLayout *self = (mFunctionDefineLayout *)arg0;
    s8 **pp = &self->unkC;

    if (func_002F47F0(*pp) == 0) {
        s32 r = func_00322060(arg1);
        func_002F4848(*pp, r);
        func_003067C0(r, &self->sym_id, pp);
    }
}
