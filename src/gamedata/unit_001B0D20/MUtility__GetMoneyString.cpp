/* Script native for MUtility.GetMoneyString (inferred from the symbol name): returns the first int argument formatted as money text.
 * With argc > 0 it reads the int through vtable slot 0x58 of args[0], formats it into a 0x40-byte buffer with func_0042E7C8(value, buf, 0x40)
 * (buf0..buf3 are the four 16-byte pieces of that one buffer), copies the C string into a fresh std::string (empty-rep clone,
 * then replace(0, npos, text, string length)), wraps it in a string handle (func_00314B20) and stores that handle into ret with the
 * retain-new / release-old idiom. arg1 and arg2 are declared as a void pointer and an s32 because that is how the compiler saw argc and the args pointer. */
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
extern "C" void func_0042E7C8(s32, void *, s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void func_005C2630(void *, s32, s32, void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MUtility__GetMoneyString(s32 *ret, void *argc, s32 args) {
    s32 moneyBuf0[4];
    s32 moneyBuf1[4];
    s32 moneyBuf2[4];
    s32 moneyBuf3[4];
    s32 resultHandle[4];
    s32 unusedBuf5[4];
    Str strStorage;
    Str *str;
    s32 *text;
    s32 *resultPtr;
    s32 newVal;
    s32 oldVal;
    if ((s32)argc > 0) {
        func_0042E7C8(vcall_58((char *)(*(s32 *)(char *)args)), moneyBuf0, 0x40);
        str = &strStorage;
        text = moneyBuf0;
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
        func_005C2630(str, 0, -0x1, text, func_0057F260(text));
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
    }
}
