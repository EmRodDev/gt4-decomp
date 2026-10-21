/* Script-engine registration for float: sets its name through the vtable, links it to its parent class hObject (class id from hObject__GetClassID),
 * then registers 1 attribute (getter/setter), 24 registrations on a global symbol object
 * so scripts can call into C++ (see knowledge/script-engine.md, section 3.3).
 * Each registration builds the member name as a refcounted string from a literal and releases it afterwards;
 * the repeated inline blocks are the compiler expansion of that string constructor/destructor and are kept as is. */
#define GT4_DECLS
#include "gt4/hObject.h"
typedef int s32;

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
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);
extern "C" void func_002F36E0(Obj *cls, void *symbol, void (*method)(void));
extern "C" void func_002F3860(Obj *cls, Str *name, void (*getter)(void), void (*setter)(void));
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));
extern char D_0069D840[];
extern char D_0069D848[];
extern char D_0083D750[];
extern char D_0083D748[];
extern char D_0083D780[];
extern char D_0083D678[];
extern char D_0083D6A8[];
extern char D_0083D6C8[];
extern char D_0083D6D8[];
extern char D_0083D6D0[];
extern char D_0083D6C0[];
extern char D_0083D6B0[];
extern char D_0083D648[];
extern char D_0083D668[];
extern char D_0083D640[];
extern char D_0083D638[];
extern char D_0083D868[];
extern char D_0083D658[];
extern char D_0083D6F0[];
extern char D_0083D6E8[];
extern char D_0083D670[];
extern char D_0083D698[];
extern char D_0083D680[];
extern char D_0083D690[];
extern char D_0083D6A0[];
extern char D_0083D688[];
extern "C" void float__global_0083D750(void);
extern "C" void float__global_0083D748(void);
extern "C" void float__get_value(void);
extern "C" void float__set_value(void);

extern "C" void func_002F8D10(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = D_0069D840;
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
    func_002F3A30(cls, hObject__GetClassID());
    func_00306780(cls, D_0083D750, float__global_0083D750);
    func_002F36E0(cls, D_0083D748, float__global_0083D748);
    {
        Str *namePtr = &name;
        const char *literal = D_0069D848;
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
        func_002F3860(cls, &name, float__get_value, float__set_value);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F36E0(cls, D_0083D780, 0);
    func_002F36E0(cls, D_0083D678, 0);
    func_002F36E0(cls, D_0083D6A8, 0);
    func_002F36E0(cls, D_0083D6C8, 0);
    func_002F36E0(cls, D_0083D6D8, 0);
    func_002F36E0(cls, D_0083D6D0, 0);
    func_002F36E0(cls, D_0083D6C0, 0);
    func_002F36E0(cls, D_0083D6B0, 0);
    func_002F36E0(cls, D_0083D648, 0);
    func_002F36E0(cls, D_0083D668, 0);
    func_002F36E0(cls, D_0083D640, 0);
    func_002F36E0(cls, D_0083D638, 0);
    func_002F36E0(cls, D_0083D868, 0);
    func_002F36E0(cls, D_0083D658, 0);
    func_002F36E0(cls, D_0083D6F0, 0);
    func_002F36E0(cls, D_0083D6E8, 0);
    func_002F36E0(cls, D_0083D670, 0);
    func_002F36E0(cls, D_0083D698, 0);
    func_002F36E0(cls, D_0083D680, 0);
    func_002F36E0(cls, D_0083D690, 0);
    func_002F36E0(cls, D_0083D6A0, 0);
    func_002F36E0(cls, D_0083D688, 0);
}
