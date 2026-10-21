/* Returns the field at +0x1310 of the block pointed to by the field at +0x50, but 1 instead when that field is -1 (-1 looks like an 'unset' marker, inferred from the substitution). */
#include "types.h"

struct Inner {
    char pad[0x1310];
    s32 unk1310;
};

struct Obj {
    char pad[0x50];
    Inner *unk50;
};

extern "C" s32 func_004ED570(Obj *self) {
    s32 value = self->unk50->unk1310;
    return (value == -1) ? 1 : value;
}
