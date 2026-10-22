/* Script native for MUpdateContext.loadGpb (inferred from the symbol name): needs argc >= 2 and passes two strings to a virtual method of the context object.
 * args[0] and args[1] are wrapped into handles (func_00312370) and turned into strings with func_00314920; the context object (func_0024E3D0) is called through vtable slot 0x1B0
 * with (this, text0, text1). Nothing is stored into ret. The meaning of the two strings is unknown (Gpb is probably a packed resource format; inferred from the name). */
#include "types.h"

struct Obj {
    s32 pad0;
    char *vt;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, u8 *, u8 *);
};

extern "C" void func_00312370(void *unusedRet, void *ctx);
extern "C" void func_0024E3D0(void *unusedRet, void *ctx);
extern "C" void func_00312318(void *unusedRet, s32 ctx);
extern "C" void func_0024E378(void *unusedRet, s32 ctx);
extern "C" u8 *func_00314920(u8 *unusedRet);

extern "C" void MUpdateContext__loadGpb(void *unusedRet, void *ctx, s32 argc, char **args) {
    s32 argHandle0[4];
    s32 argHandle1[4];
    s32 ctxHandle[4];
    s32 *argHandle1Ptr;
    s32 *ctxHandlePtr;
    Obj *ctxObj;
    VEntry *slot1B0;
    u8 *text0;
    if (argc >= 0x2) {
        func_00312370(argHandle0, args);
        argHandle1Ptr = argHandle1;
        func_00312370(argHandle1Ptr, (char *)args + 0x4);
        ctxHandlePtr = ctxHandle;
        func_0024E3D0(ctxHandlePtr, ctx);
        ctxObj = (Obj *)ctxHandlePtr[0];
        slot1B0 = (VEntry *)(ctxObj->vt + 0x1B0);
        ctxObj = (Obj *)((char *)ctxObj + slot1B0->delta);
        text0 = func_00314920((u8 *)argHandle0[0]);
        slot1B0->fn((void *)ctxObj, text0, func_00314920((u8 *)argHandle1Ptr[0]));
        func_0024E378(ctxHandlePtr, 0x2);
        func_00312318(argHandle1Ptr, 0x2);
        func_00312318(argHandle0, 0x2);
    }
}
