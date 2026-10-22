/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MNetConf.LoadFile (inferred from the symbol name): needs argc >= 3 and forwards one int and two strings to a virtual method.
 * args[0] is wrapped by func_002FC8C8 and unwrapped to an int with func_002FE250; args[1] and args[2] go through func_00312370 and func_00314920 to
 * become strings. The context object (func_00221B28) is called through vtable entry 94 (byte offset 0x2F0, one entry before AddFiles' 0x2F8) with
 * (this, int, text1, text2); the result is boxed by func_002FE278 and stored into ret. What the int selects is unknown. */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct RefCounter;

struct VEntry { s16 delta; s16 index; void *(*fn)(void *, s32, void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern "C" void func_00312370(void *ret, void *ctx) throw();
extern "C" void func_00221B28(void *ret, void *ctx) throw();
extern "C" u8 *func_00314920(u8 *ret);
extern "C" s32 func_002FE250(void *ret);
extern "C" void func_002FC8C8(void *ret, void *ctx);
extern "C" void func_002FE278(void *ret, void *ctx);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *ret, int ctx);
extern "C" void func_00221AD0(void *ret, int ctx) throw();
extern "C" void func_00312318(void *ret, int ctx);

extern "C" void MNetConf__LoadFile(s32 *ret, void *ctx, s32 argc, void *args) {
    if (argc >= 3) {
        s32 ctxHandle[4];
        s32 argHandle0[4];
        s32 argHandle1[4];
        s32 argHandle2[4];
        s32 resultHandle[4];
        s32 *argHandle0Ptr;
        s32 *argHandle1Ptr;
        s32 *argHandle2Ptr;
        s32 *resultPtr;
        char *ctxObj;
        VEntry *e;
        s32 intArg;
        u8 *text1;
        u8 *text2;
        void *callResult;
        s32 newVal;
        s32 oldVal;

        func_00221B28(ctxHandle, ctx);
        argHandle0Ptr = argHandle0;
        func_002FC8C8(argHandle0Ptr, args);
        argHandle1Ptr = argHandle1;
        func_00312370(argHandle1Ptr, (char *)args + 4);
        argHandle2Ptr = argHandle2;
        func_00312370(argHandle2Ptr, (char *)args + 8);
        ctxObj = (char *)ctxHandle[0];
        e = &((VObj *)ctxObj)->vtbl[94];
        ctxObj = ctxObj + e->delta;
        intArg = func_002FE250((void *)argHandle0Ptr[0]);
        text1 = func_00314920((u8 *)argHandle1Ptr[0]);
        text2 = func_00314920((u8 *)argHandle2Ptr[0]);
        callResult = e->fn(ctxObj, intArg, text1, text2);
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
        func_002FC870(resultPtr, 2);
        func_00312318(argHandle2Ptr, 2);
        func_00312318(argHandle1Ptr, 2);
        func_002FC870(argHandle0Ptr, 2);
        func_00221AD0(ctxHandle, 2);
    }
}
