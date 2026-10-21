/* Base-object constructor of mColorObject (class mColorObject : hObject, per include/gt4/mColorObject.h): runs the hObject constructor,
 * then stores mColorObject's vtable at +0x4 (the vptr) and constructs the member at +0x10 with func_002030A0.
 * The hObject constructor is called without arguments because the compiler passes `this` in the register it already holds. */
#include "gt4/mColorObject.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_002030A0(void *self);
extern "C" char mColorObject__vtable[];

extern "C" void *mColorObject__structor_0(void *self)
{
    hObject__structor_0();
    ((struct mColorObject *)self)->unk4 = mColorObject__vtable;
    return func_002030A0((char *)self + 0x10);
}
