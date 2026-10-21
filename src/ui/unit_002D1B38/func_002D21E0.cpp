/* While the object is active (field +0x20 nonzero), stores three floats at +0xC, +0x10 and +0x14 and calls func_002D2288 on it.
 * The second argument is negated and goes last, so the triple looks like an axis swap (x, z, -y), inferred from that pattern; sibling of func_002D2498 and func_002D1FF8. */
#include "types.h"

struct Obj_002D21E0 {
    char pad0[0xC];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    char pad1[0x20 - 0x14 - 4];
    s32 unk20;
};

extern "C" void func_002D2288(struct Obj_002D21E0 *obj);

extern "C" void func_002D21E0(struct Obj_002D21E0 *obj, f32 x, f32 y, f32 z) {
    if (obj->unk20 != 0) {
        obj->unkC = x;
        obj->unk10 = z;
        obj->unk14 = -y;
        func_002D2288(obj);
    }
}
