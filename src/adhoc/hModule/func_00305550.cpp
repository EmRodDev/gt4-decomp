/* Copies *arg1 into the field at +0x10 unless it is the same address (the self-assignment guard of an assignment operator, inferred from the shape). */
#include "types.h"

struct Struct_00305550 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_00305550(Struct_00305550 *self, s32 *source) {
    s32 *field = &self->unk10;

    if (field != source) {
        *field = *source;
    }
}
