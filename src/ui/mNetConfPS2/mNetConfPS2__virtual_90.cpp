/* Last of the five string getters, mNetConfPS2 slot 90 (inferred from the symbol name), using func_004EE7A0 on the object at +0x268 to resolve `index` into a C string.
 * The C string is copied into a local std::string, the local is copied into the caller's return slot, and the local's storage is released when its count hits zero; ret is returned in v0 as the ABI wants. */
#include "types.h"

struct Rep {
    s32 len;
    s32 capacity;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct Obj {
    char pad0[4];
};

struct Self {
    char pad0[0x268];
    Obj *p268;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *localStr);
extern "C" void *func_005C2630(Str *localStr, s32 pos, s32 n, const char *text, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" const char *func_004EE7A0(Obj *arg0, s32 arg1);

extern "C" Str *mNetConfPS2__virtual_90(Str *ret, Self *self, s32 index) {
    Str localStr;
    Str *localPtr = &localStr;
    const char *text = func_004EE7A0(self->p268, index);
    {
        Rep *r = &D_00659FA8;
        char *d = (char *)(r + 1);
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        localPtr->p = d;
    }
    func_005C2630(localPtr, 0, -1, text, func_0057F260(text));
    {
        s32 p = *(s32 *)&localStr.p;
        Rep *r = (Rep *)(p - 0x10);
        s32 d = p;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            r->ref++;
        }
        *(s32 *)&ret->p = d;
    }
    {
        Rep *rep = (Rep *)(*(s32 *)&localStr.p - 0x10);
        if (--rep->ref == 0) {
            s32 capacity = rep->capacity + 0x10;
            func_00326798(rep, capacity, 4, func_005C11A8()->name);
        }
    }
    return ret;
}
