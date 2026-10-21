/* Base-object constructor of mPipe (class mPipe : hObject, per include/gt4/mPipe.h): runs the hObject constructor,
 * then stores mPipe's vtable at +0x4 (the vptr) and constructs the member at +0x10 with func_005DA8A0.
 * The hObject constructor is called without arguments because the compiler passes `this` in the register it already holds. */
#include "gt4/mPipe.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_005DA8A0(void *self);
extern "C" char mPipe__vtable[];

extern "C" void *mPipe__structor_0(void *self)
{
    hObject__structor_0();
    ((struct mPipe *)self)->unk4 = mPipe__vtable;
    return func_005DA8A0((char *)self + 0x10);
}
