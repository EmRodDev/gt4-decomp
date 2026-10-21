/* Script-engine registration for MMagnifyActor: sets its name through the vtable, links it to its parent class,
 * then registers 3 attributes (getter/setter), 2 registrations on a global symbol object
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
extern "C" int func_001FF0F8(void);
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);

extern char D_0069C198[];
extern char D_0069C1A8[];
extern char D_0069C1B0[];
extern char D_0069C1C0[];
extern char D_00838A30[];
extern char D_00838A28[];
extern "C" void MMagnifyActor__global_00838A30(void);
extern "C" void MMagnifyActor__global_00838A28(void);
extern "C" void MMagnifyActor__get_repeat(void);
extern "C" void MMagnifyActor__set_repeat(void);
extern "C" void MMagnifyActor__get_reverse_phase(void);
extern "C" void MMagnifyActor__set_reverse_phase(void);
extern "C" void MMagnifyActor__get_period(void);
extern "C" void MMagnifyActor__set_period(void);
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));
extern "C" void func_002F36E0(Obj *cls, void *symbol, void (*method)(void));
extern "C" void func_002F3860(Obj *cls, Str *name, void (*getter)(void), void (*setter)(void));

extern "C" void func_002B9E40(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = D_0069C198;
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
            VEntry *thunk = (VEntry *)(cls->vtbl + 0x190);
            thunk->fn((char *)cls + thunk->delta, &name);
        }
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 blockSize = rep->cap + 0x10;
                func_00326798(rep, blockSize, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F3A30(cls, func_001FF0F8());
    func_00306780(cls, D_00838A30, MMagnifyActor__global_00838A30);
    func_002F36E0(cls, D_00838A28, MMagnifyActor__global_00838A28);
    {
        Str *namePtr = &name;
        const char *literal = D_0069C1A8;
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
        func_002F3860(cls, &name, MMagnifyActor__get_repeat, MMagnifyActor__set_repeat);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 blockSize = rep->cap + 0x10;
                func_00326798(rep, blockSize, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_0069C1B0;
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
        func_002F3860(cls, &name, MMagnifyActor__get_reverse_phase, MMagnifyActor__set_reverse_phase);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 blockSize = rep->cap + 0x10;
                func_00326798(rep, blockSize, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_0069C1C0;
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
        func_002F3860(cls, &name, MMagnifyActor__get_period, MMagnifyActor__set_period);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 blockSize = rep->cap + 0x10;
                func_00326798(rep, blockSize, 4, func_005C11A8()->name);
            }
        }
    }
}
