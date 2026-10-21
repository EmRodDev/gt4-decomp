/* Script-engine registration for int: sets its name through the vtable, links it to its parent class hObject (class id from hObject__GetClassID),
 * then registers 1 attribute (getter/setter), 30 registrations on a global symbol object
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
extern char D_0069D9E8[];
extern char D_0069D9F0[];
extern char D_0083E050[];
extern char D_0083E048[];
extern char D_0083E080[];
extern char D_0083DF78[];
extern char D_0083DF50[];
extern char D_0083DFA8[];
extern char D_0083DFC8[];
extern char D_0083DFD8[];
extern char D_0083DFD0[];
extern char D_0083E170[];
extern char D_0083DFC0[];
extern char D_0083DFB8[];
extern char D_0083DFB0[];
extern char D_0083DF48[];
extern char D_0083DF68[];
extern char D_0083DF40[];
extern char D_0083DF38[];
extern char D_0083E168[];
extern char D_0083DF58[];
extern char D_0083E160[];
extern char D_0083DFF0[];
extern char D_0083DFE8[];
extern char D_0083DF70[];
extern char D_0083DF98[];
extern char D_0083DF80[];
extern char D_0083DFE0[];
extern char D_0083DF90[];
extern char D_0083DFA0[];
extern char D_0083DF88[];
extern char D_0083E028[];
extern "C" void int__global_0083E050(void);
extern "C" void int__global_0083E048(void);
extern "C" void int__get_value(void);
extern "C" void int__set_value(void);

extern "C" void func_002FDB98(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = D_0069D9E8;
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
    func_00306780(cls, D_0083E050, int__global_0083E050);
    func_002F36E0(cls, D_0083E048, int__global_0083E048);
    {
        Str *namePtr = &name;
        const char *literal = D_0069D9F0;
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
        func_002F3860(cls, &name, int__get_value, int__set_value);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F36E0(cls, D_0083E080, 0);
    func_002F36E0(cls, D_0083DF78, 0);
    func_002F36E0(cls, D_0083DF50, 0);
    func_002F36E0(cls, D_0083DFA8, 0);
    func_002F36E0(cls, D_0083DFC8, 0);
    func_002F36E0(cls, D_0083DFD8, 0);
    func_002F36E0(cls, D_0083DFD0, 0);
    func_002F36E0(cls, D_0083E170, 0);
    func_002F36E0(cls, D_0083DFC0, 0);
    func_002F36E0(cls, D_0083DFB8, 0);
    func_002F36E0(cls, D_0083DFB0, 0);
    func_002F36E0(cls, D_0083DF48, 0);
    func_002F36E0(cls, D_0083DF68, 0);
    func_002F36E0(cls, D_0083DF40, 0);
    func_002F36E0(cls, D_0083DF38, 0);
    func_002F36E0(cls, D_0083E168, 0);
    func_002F36E0(cls, D_0083DF58, 0);
    func_002F36E0(cls, D_0083E160, 0);
    func_002F36E0(cls, D_0083DFF0, 0);
    func_002F36E0(cls, D_0083DFE8, 0);
    func_002F36E0(cls, D_0083DF70, 0);
    func_002F36E0(cls, D_0083DF98, 0);
    func_002F36E0(cls, D_0083DF80, 0);
    func_002F36E0(cls, D_0083DFE0, 0);
    func_002F36E0(cls, D_0083DF90, 0);
    func_002F36E0(cls, D_0083DFA0, 0);
    func_002F36E0(cls, D_0083DF88, 0);
    func_002F36E0(cls, D_0083E028, 0);
}
