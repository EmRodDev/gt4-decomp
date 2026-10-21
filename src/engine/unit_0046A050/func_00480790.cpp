/* Getter: follows the pointer at +0x60 and returns the 32-bit field at +0x20 of the object it points to (purpose unknown). */
#include "types.h"
struct Inner { char pad[0x20]; s32 unk20; };
struct Obj { char pad[0x60]; Inner *unk60; };
extern "C" s32 func_00480790(Obj *self) {
    return self->unk60->unk20;
}
