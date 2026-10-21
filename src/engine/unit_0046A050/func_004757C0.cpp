/* Sets the field at +0x70 of the object that this object points to (its first member) to 1; purpose of the flag unknown. */
#include "types.h"
struct Inner {
    char pad[0x70];
    s32 unk70;
};
struct Obj {
    Inner *inner;
};
extern "C" void func_004757C0(Obj *self) {
    self->inner->unk70 = 1;
}
