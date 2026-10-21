/* Script-engine registration for Class: sets its name through the vtable, links it to its parent class hModule (class id from hModule__GetClassID),
 * then registers 6 registrations on a global symbol object
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

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, Str *);
};

extern Rep D_00659FA8;
extern char D_0069D710[];
extern char D_0083CE50[];
extern char D_0083CE48[];
extern char D_0083CDC8[];
extern char D_0083CD40[];
extern char D_0083CEE8[];
extern char D_0083CD60[];

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int hModule__GetClassID(void);
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);
extern "C" void func_002F36E0(Obj *cls, void *symbol, void (*method)(void));
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));
extern "C" void func_002F3008(void);
extern "C" void func_002F30A0(void);
extern "C" void func_002F2BE8(void);
extern "C" void func_002F2CB0(void);
extern "C" void func_002F2ED8(void);

extern "C" void func_002F3188(Obj *cls) {
    Str name;
    Str *namePtr = &name;
    const char *literal = D_0069D710;
    Rep *emptyRep = &D_00659FA8;
    char *chars = (char *)(emptyRep + 1);
    if (emptyRep->sel != 0) {
        chars = func_005C2560(emptyRep);
    } else {
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
    void (*cb)(void);
    cb = func_002F2ED8;
    func_002F3A30(cls, hModule__GetClassID());
    func_00306780(cls, D_0083CE50, func_002F3008);
    func_002F36E0(cls, D_0083CE48, func_002F30A0);
    func_002F36E0(cls, D_0083CDC8, func_002F2BE8);
    func_002F36E0(cls, D_0083CD40, func_002F2CB0);
    func_002F36E0(cls, D_0083CEE8, cb);
    func_002F36E0(cls, D_0083CD60, cb);
}
