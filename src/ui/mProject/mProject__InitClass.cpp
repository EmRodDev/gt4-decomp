/* Script-engine registration for MProject: sets its name through the vtable, links it to its parent class mComposite (class id from mComposite__GetClassID),
 * then registers 3 methods, 1 registration on a global symbol object
 * so scripts can call into C++ (see knowledge/script-engine.md, section 3.3).
 * Each registration builds the member name as a refcounted string from a literal and releases it afterwards;
 * the repeated inline blocks are the compiler expansion of that string constructor/destructor and are kept as is. */
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
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, Str *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int mComposite__GetClassID(void);
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);

extern char D_00698410[];
extern char D_00698420[];
extern char D_00698430[];
extern char D_00698448[];
extern char D_0082E1E8[];
extern "C" void MProject__global_0082E1E8(void);
extern "C" void MProject__findPage(void);
extern "C" void MProject__exportRootWindow(void);
extern "C" void MProject__getDir(void);
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));
extern "C" void func_002F3818(Obj *cls, Str *name, void (*method)(void));

extern "C" void mProject__InitClass(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = D_00698410;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        {
            VEntry *entry = (VEntry *)(cls->vtbl + 0x190);
            entry->fn((char *)cls + entry->delta, &name);
        }
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F3A30(cls, mComposite__GetClassID());
    func_00306780(cls, D_0082E1E8, MProject__global_0082E1E8);
    {
        Str *namePtr = &name;
        const char *literal = D_00698420;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MProject__findPage);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00698430;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MProject__exportRootWindow);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00698448;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MProject__getDir);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
}
