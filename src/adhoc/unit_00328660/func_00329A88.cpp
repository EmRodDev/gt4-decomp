/* Script variable setter by name: returns 0 when func_003166F8 does not know the name; otherwise gets a module handle (func_002EC3A0), resolves the name with HSymID::GetID and asks func_003069F8 for the matching variable handle; if one comes back it stores 'value' into it (func_002FE258) and returns 1. The meaning 'set by name' is inferred from the call sequence. The name is copied into a fresh refcounted string for each callee, which is why the string constructor/destructor appears twice. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Tmp {
    s32 field0;
    char pad[0xC];
};

struct Handle16 {
    void *p;
    char pad[0xC];
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" bool func_003166F8(Str *s);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_002ECDE0(Tmp *arg0);
extern "C" void func_002EA590(Tmp *arg0, s32 arg1);
extern "C" void func_002FE2E0(Handle16 *arg0);
extern "C" s32 func_002EC3A0(Handle16 *arg0, s32 arg1);
extern "C" void func_003069F8(void *obj, Handle16 *h, s32 *val);
extern "C" void func_003041B8(Handle16 *arg0, s32 arg1);
extern "C" void func_002FC870(Handle16 *arg0, s32 arg1);
extern "C" void func_002FE258(void *arg0, s32 arg1);

extern "C" s32 func_00329A88(s32 value, const char *name) {
    union {
        Str s;
        Tmp tmp;
    } u;
    Handle16 variableHandle;
    Handle16 moduleHandle;
    s32 symbolId;
    Str nameCopy;
    bool unknownName;

    {
        Str *ps = &u.s;
        const char *src = name;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        unknownName = !func_003166F8(&u.s);
        {
            Rep *q = (Rep *)(u.s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    if (unknownName) {
        return 0;
    }
    {
        Handle16 *variable;
        Handle16 *moduleRef;
        void *module;
        func_002ECDE0(&u.tmp);
        variable = &variableHandle;
        func_002FE2E0(variable);
        moduleRef = &moduleHandle;
        func_002EC3A0(moduleRef, u.tmp.field0);
        module = moduleRef->p;
        {
            Str *ps = &nameCopy;
            s32 *pv = &symbolId;
            const char *src = name;
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
            *pv = HSymID__GetID(ps);
            func_003069F8(module, variable, pv);
            {
                Rep *q = (Rep *)(ps->p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        }
        func_003041B8(moduleRef, 2);
        if (variable->p != 0) {
            func_002FE258(variable->p, value);
            func_002FC870(variable, 2);
            func_002EA590(&u.tmp, 2);
            return 1;
        }
        func_002FC870(variable, 2);
        func_002EA590(&u.tmp, 2);
        return 0;
    }
}
