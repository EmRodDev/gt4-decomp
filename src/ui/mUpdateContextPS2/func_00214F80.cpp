/* mUpdateContextPS2 member (class taken from the directory): returns the record to use. If the field at +0x420 is
 * non-zero it is this object's own record at +0x3E4; if it is zero, entry D_0061850C.unk78 of the global table at
 * D_0061850C (0x3C bytes per entry; the field is used as the index, inferred). Meaning of the record unknown. */
#include "types.h"

struct Obj {
    u8 pad[0x420];
    s32 unk420;
};

struct D_Obj {
    u8 pad[0x78];
    s32 index;
};

extern D_Obj D_0061850C;

extern "C" void *func_00214F80(Obj *self) {
    void *result = (char *)self + 0x3E4;
    if (self->unk420 == 0) {
        result = (char *)&D_0061850C + D_0061850C.index * 0x3C;
    }
    return result;
}
