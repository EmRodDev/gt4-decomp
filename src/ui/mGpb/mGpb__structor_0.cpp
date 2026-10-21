/* Base-object constructor of mGpb (class mGpb : hObject, per include/gt4/mGpb.h): runs the hObject constructor,
 * then stores mGpb's vtable at +0x4 (the vptr) and constructs the member at +0x10 with func_0048F270.
 * The hObject constructor is called without arguments because the compiler passes `this` in the register it already holds. */
#include "gt4/mGpb.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_0048F270(void *self);
extern "C" char mGpb__vtable[];

extern "C" void *mGpb__structor_0(void *self)
{
    hObject__structor_0();
    ((struct mGpb *)self)->unk4 = mGpb__vtable;
    return func_0048F270((char *)self + 0x10);
}
