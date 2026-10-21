/* Base-object constructor of mShell (class mShell : hObject, per include/gt4/mShell.h): runs the hObject constructor,
 * then stores mShell's vtable at +0x4 (the vptr) and constructs the member at +0x10 with func_002273C8.
 * The hObject constructor is called without arguments because the compiler passes `this` in the register it already holds. */
#include "gt4/mShell.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_002273C8(void *self);
extern "C" char mShell__vtable[];

extern "C" void *mShell__structor_0(void *self)
{
    hObject__structor_0();
    ((struct mShell *)self)->unk4 = mShell__vtable;
    return func_002273C8((char *)self + 0x10);
}
