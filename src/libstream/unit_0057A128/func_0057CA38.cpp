/* Deleting destructor shape: stores the class's vtable pointer (D_00689F10) at +0x8, calls no base-class destructor, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
#include "types.h"

struct S { char pad[0x8]; void *unk8; };

extern void func_005C1628(S *);
extern char D_00689F10;

void func_0057CA38(S *self, s32 deleteFlag)
{
    deleteFlag = deleteFlag & 1;
    self->unk8 = &D_00689F10;
    if (deleteFlag)
    {
        func_005C1628(self);
        return;
    }
}
