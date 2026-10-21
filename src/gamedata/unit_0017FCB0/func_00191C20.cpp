/* Continuation of the MOption script-class registration (knowledge/script-engine.md, section 3.3): registers ten methods on the class passed in, five for the
 * analog controls (clear/unset/set/get/search) and five for the buttons. Each registration builds the member name as a refcounted string from a literal and
 * releases it afterwards; the repeated blocks are the compiler expansion of that string constructor/destructor and are kept as is. */
#define GT4_DECLS
#include "gt4/hObject.h"
typedef int s32;

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

extern "C" char *func_005C2560(Rep *emptyRep);
extern "C" s32 func_0057F260(const char *name);
extern "C" void *func_005C2630(Str *name, s32 pos, s32 n, const char *literal, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_002F3818(Obj *cls, Str *arg1, void (*arg2)(void));
extern "C" void MOption__clearAnalogFunction(void);
extern "C" void MOption__unsetAnalogKey(void);
extern "C" void MOption__setAnalogConfig(void);
extern "C" void MOption__getAnalogConfig(void);
extern "C" void MOption__searchAnalogConfig(void);
extern "C" void MOption__clearButtonFunction(void);
extern "C" void MOption__unsetButtonKey(void);
extern "C" void MOption__setButtonConfig(void);
extern "C" void MOption__getButtonConfig(void);
extern "C" void MOption__searchButtonConfig(void);

extern "C" void func_00191C20(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = "clearAnalogFunction";
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
        func_002F3818(cls, &name, MOption__clearAnalogFunction);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "unsetAnalogKey";
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
        func_002F3818(cls, &name, MOption__unsetAnalogKey);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "setAnalogConfig";
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
        func_002F3818(cls, &name, MOption__setAnalogConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "getAnalogConfig";
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
        func_002F3818(cls, &name, MOption__getAnalogConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "searchAnalogConfig";
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
        func_002F3818(cls, &name, MOption__searchAnalogConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "clearButtonFunction";
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
        func_002F3818(cls, &name, MOption__clearButtonFunction);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "unsetButtonKey";
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
        func_002F3818(cls, &name, MOption__unsetButtonKey);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "setButtonConfig";
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
        func_002F3818(cls, &name, MOption__setButtonConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "getButtonConfig";
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
        func_002F3818(cls, &name, MOption__getButtonConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = "searchButtonConfig";
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
        func_002F3818(cls, &name, MOption__searchButtonConfig);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->capacity + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
}
