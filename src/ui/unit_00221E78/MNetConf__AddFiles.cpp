/* Script native for MNetConf.AddFiles (inferred from the symbol name): needs four arguments (argc >= 4) and forwards four strings.
 * Each of args[0..3] is wrapped in its own handle (func_00312370) and converted to a string with func_00314920; the context object's
 * vtable slot 0x2F8 is then called with (this, text0, text1, text2, text3). Its result is boxed by func_002FE278 and stored into ret
 * with retain-new / release-old, and the five handles are destroyed in reverse order. Purpose of the four strings unknown. */
#include "types.h"

struct RefCounter;

struct Obj {
    char pad0[4];
    char *vt;
};

struct VEntry_2F8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, u8 *, u8 *, u8 *, u8 *);
};

extern "C" void func_00221B28(void *ret, void *ctx);
extern "C" void func_00312370(void *ret, void *ctx);
extern "C" u8 *func_00314920(u8 *ret);
extern "C" void func_002FE278(void *ret, void *ctx);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *ret, int ctx);
extern "C" void func_00312318(void *ret, int ctx);
extern "C" void func_00221AD0(void *ret, int ctx);

extern "C" void MNetConf__AddFiles(s32 *ret, void *ctx, s32 argc, void *args) {
    s32 ctxHandle[4];
    s32 argHandle0[4];
    s32 argHandle1[4];
    s32 argHandle2[4];
    s32 argHandle3[4];
    s32 resultHandle[4];
    s32 *argHandle1Ptr;
    s32 *argHandle2Ptr;
    s32 *argHandle3Ptr;
    s32 *resultPtr;
    char *ctxObj;
    VEntry_2F8 *e;
    u8 *arg0Target;
    u8 *text0;
    u8 *text1;
    u8 *text2;
    u8 *text3;
    void *callResult;
    s32 newVal;
    s32 oldVal;

    if (argc >= 0x4) {
        func_00221B28(ctxHandle, ctx);
        func_00312370(argHandle0, args);
        argHandle1Ptr = argHandle1;
        func_00312370(argHandle1Ptr, (char *)args + 0x4);
        argHandle2Ptr = argHandle2;
        func_00312370(argHandle2Ptr, (char *)args + 0x8);
        argHandle3Ptr = argHandle3;
        func_00312370(argHandle3Ptr, (char *)args + 0xC);
        arg0Target = (u8 *)argHandle0[0];
        ctxObj = (char *)ctxHandle[0];
        e = (VEntry_2F8 *)(((Obj *)ctxObj)->vt + 0x2F8);
        ctxObj = ctxObj + e->delta;
        text0 = func_00314920(arg0Target);
        text1 = func_00314920((u8 *)argHandle1Ptr[0]);
        text2 = func_00314920((u8 *)argHandle2Ptr[0]);
        text3 = func_00314920((u8 *)argHandle3Ptr[0]);
        callResult = e->fn(ctxObj, text0, text1, text2, text3);
        resultPtr = resultHandle;
        func_002FE278(resultPtr, callResult);
        if (ret != resultPtr) {
            newVal = *resultPtr;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *ret;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *ret = newVal;
        }
        func_002FC870(resultPtr, 0x2);
        func_00312318(argHandle3Ptr, 0x2);
        func_00312318(argHandle2Ptr, 0x2);
        func_00312318(argHandle1Ptr, 0x2);
        func_00312318(argHandle0, 0x2);
        func_00221AD0(ctxHandle, 0x2);
    }
}
