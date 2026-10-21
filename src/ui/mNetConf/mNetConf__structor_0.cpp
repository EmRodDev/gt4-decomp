/* Base-object constructor of mNetConf (class mNetConf : hObject, per include/gt4/mNetConf.h): runs the hObject constructor,
 * then stores mNetConf's vtable at +0x4 (the vptr) and constructs the member at +0x10 with func_00560548.
 * The hObject constructor is called without arguments because the compiler passes `this` in the register it already holds. */
#include "gt4/mNetConf.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_00560548(void *self);
extern "C" char mNetConf__vtable[];

extern "C" void *mNetConf__structor_0(void *self)
{
    hObject__structor_0();
    ((struct mNetConf *)self)->unk4 = mNetConf__vtable;
    return func_00560548((char *)self + 0x10);
}
