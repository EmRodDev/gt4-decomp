#include "types.h"

/* Layout backed by include/gt4/mNetConfPS2.h and config/class_fields.json:
 *   mNetConfPS2: offset 0x370 is unk370 buffer of 0x100 bytes
 */
struct mNetConfPS2Layout {
    char pad[0x370];
    char unk370[0x100];
};

extern "C" void func_005A6AB0(void *arg0, void *arg1, s32 arg2);

extern "C" void mNetConfPS2__virtual_78(mNetConfPS2Layout *arg0, void *arg1) {
    func_005A6AB0(arg0->unk370, arg1, 0x100);
}
