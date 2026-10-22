/* Script native for MQuickWork.getGridCarName (inferred from the symbol name): returns the name of the car at a starting-grid slot as a string.
 * A context handle is built first (func_00124130); gridIndex is args[0] read through vtable slot 0x58, or 0 when argc == 0. The name pointer
 * comes from func_00127B38(*ctxHandle, gridIndex), is copied into a new std::string (empty-rep clone + replace with string length) and wrapped
 * by func_00314B20 into resultHandle, which is stored into ret with retain-new / release-old. The context handle is destroyed last (func_001240D8, 2). */
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

extern Rep D_00659FA8;
extern "C" void func_00124130(void *, void *);
extern "C" void *func_00127B38(void *, s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(s32);
extern "C" void func_005C2630(void *, s32, s32, s32, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_001240D8(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MQuickWork__getGridCarName(s32 *ret, void *ctx, s32 argc, void **args) {
    s32 ctxHandle[4];
    s32 resultHandle[4];
    Str strStorage;
    Str *str;
    s32 carName;
    s32 *resultPtr;
    s32 newVal;
    s32 oldVal;
    s32 gridIndex;
    func_00124130(ctxHandle, ctx);
    gridIndex = 0;
    if (argc > 0) {
        gridIndex = vcall_58((char *)args[0]);
    }
    str = &strStorage;
    carName = (s32)func_00127B38((void *)ctxHandle[0], gridIndex);
    {
        Rep *emptyRep = &D_00659FA8;
        char *data;
        if (emptyRep->sel != 0) {
            data = func_005C2560(emptyRep);
        } else {
            data = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        str->p = data;
    }
    func_005C2630(str, 0, -0x1, carName, func_0057F260(carName));
    resultPtr = resultHandle;
    func_00314B20(resultPtr, str);
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
    func_00312318(resultPtr, 0x2);
    str_release(str);
    func_001240D8(ctxHandle, 0x2);
}
