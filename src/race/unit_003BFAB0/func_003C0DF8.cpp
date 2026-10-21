/* Looks up element number index in the pointer array reached through the field at +0x60 (array at +8 of that record,
 * inferred from the indexed use) and hands the element's member at +0x20 and the value to func_004452F8. */
#include "types.h"

struct S;

extern "C" void func_004452F8(S *target, S *value);

struct Inner60 {
    char pad0[8];
    S **items;
};

struct Obj {
    char pad0[0x60];
    Inner60 *unk60;
};

extern "C" void func_003C0DF8(Obj *self, s32 index, S *value) {
    S *element = self->unk60->items[index];
    func_004452F8((S *)((char *)element + 0x20), value);
}
