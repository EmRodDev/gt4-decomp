/* Script native for MNetConf.SetDefault (inferred from the symbol name): takes two string arguments and forwards them to a virtual method.
 * The context handle (func_00221B28) wraps an object; its vtable slot 0x338 is called with (this adjusted by delta, firstText, secondText),
 * where both texts come from vtable slot 0x18 of args[0] and args[1]. The call result is boxed by func_002FE278 and stored into ret with
 * retain-new / release-old; both strings and the context handle are then destroyed. What the slot 0x338 method does is unknown. */
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

struct VEntry_18 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj_18 { char pad0[4]; VEntry_18 *vtbl; };
static inline void vcall_18_ret(void *ret, char *o) {
    VEntry_18 *e = &((VObj_18 *)o)->vtbl[3];
    e->fn(ret, o + e->delta);
}

struct VEntry_338 { s16 delta; s16 index; void *(*fn)(void *, void *, void *); };

extern "C" void func_00221B28(void *, void *);
extern "C" void func_00221AD0(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 * func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MNetConf__SetDefault(s32 *ret, void *ctx, s32 argc, char **args) {
    s32 resultHandle[4];
    s32 ctxHandleBuf[4];
    Str firstTextStr;
    Str secondTextStr;
    s32 *ctxHandle;
    Str *firstText;
    char *firstArg;
    char *ctxObj;
    char *vtable;
    VEntry_338 *e;
    char *target;
    char *secondArg;
    void *callResult;
    s32 newVal;
    s32 oldVal;

    ctxHandle = ctxHandleBuf;
    func_00221B28(ctxHandle, ctx);
    firstArg = *(char **)args;
    firstText = &firstTextStr;
    ctxObj = (char *)ctxHandle[0];
    vtable = *(char **)(ctxObj + 4);
    e = (VEntry_338 *)(vtable + 0x338);
    target = ctxObj + e->delta;
    vcall_18_ret((char *)firstText, firstArg);
    secondArg = *(char **)((char *)args + 4);
    vcall_18_ret((char *)&secondTextStr, secondArg);
    callResult = e->fn(target, firstText, &secondTextStr);
    func_002FE278(resultHandle, callResult);
    if (ret != resultHandle) {
        newVal = resultHandle[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *ret;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *ret = newVal;
    }
    func_002FC870(resultHandle, 0x2);
    str_release(&secondTextStr);
    str_release(firstText);
    func_00221AD0(ctxHandle, 0x2);
}
