/* Script accessor MRenderContext.get_follow_mode (inferred from the symbol name): getter and setter of a follow-mode flag.
 * The render context object comes from the handle func_0022AD20 returns; the flag is the word at +0x1D50. Unlike the other accessors the setter is selected by argc == 1 (not argc > 0):
 * it stores (args[0] via vtable slot 0x58) != 0. Otherwise func_002FE278 boxes (flag != 0) and the handle is assigned to ret with retain-new / release-old.
 * The context handle is destroyed at the end in both paths (func_0022ACC8, 2). */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}
extern "C" void * func_0022AD20(void *);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0022ACC8(void *, s32);

extern "C" void MRenderContext__get_follow_mode(s32 *ret, void *ctx, s32 argc, char **args) {
    s32 ctxHandle[4];
    s32 resultHandle[4];
    s32 *resultPtr;
    s32 renderContext;
    s32 newVal;
    s32 oldVal;
    func_0022AD20(ctxHandle);
    resultPtr = resultHandle;
    if (argc == 0x1) {
        renderContext = ctxHandle[0];
        *(s32 *)((char *)renderContext + 0x1d50) = vcall_58((char *)(*(s32 *)(char *)args)) != 0;
    } else {
        func_002FE278(resultPtr, *(s32 *)((char *)ctxHandle[0] + 0x1d50) != 0);
        if (ret != resultPtr) {
            newVal = *resultPtr;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *ret;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *ret = newVal;
        }
        func_002FC870(resultPtr, 0x2);
    }
    func_0022ACC8(ctxHandle, 0x2);
}
