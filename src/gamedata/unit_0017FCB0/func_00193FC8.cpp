/* Purpose unknown. It is not a registration function although it sits in the script-registration unit: it creates a handle
 * object (func_002EFBF0), builds a 16-byte object from the float argument (func_002F9360 / func_002EEEB0), builds a refcounted
 * string from the literal at D_00692250 and passes it, with the three object arguments, to func_0023A538 and func_00250CE0,
 * then destroys everything. The inline string block is the compiler expansion of the string constructor/destructor. */
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

struct Obj16 {
    char pad[0x10];
};

extern Rep D_00659FA8;
extern char D_00692250[];

extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, void *, void *, void *, void *);
extern "C" void func_00250CE0(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, void *, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_002F7B68(void *, int);
extern "C" void func_002F9360(void *, float);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void func_00193FC8(void *first, void *second, void *third, float amount) {
    struct { void *p; char pad[0xC]; } handle;
    Obj16 result;
    Obj16 temp;
    Str text;
    const char *literal;
    Obj16 *resultPtr;
    func_002EFBF0(&handle);
    resultPtr = &result;
    {
        Obj16 *tempPtr = &temp;
        void *handleObj = handle.p;
        func_002F9360(tempPtr, amount);
        func_002EEEB0(resultPtr, handleObj, tempPtr);
        func_00309378(resultPtr, 2);
        func_002F7B68(tempPtr, 2);
    }
    {
        Str *textPtr = &text;
        literal = D_00692250;
        {
            Rep *emptyRep = &D_00659FA8;
            char *chars = (char *)(emptyRep + 1);
            if (emptyRep->sel != 0) {
                chars = func_005C2560(emptyRep);
            } else {
                emptyRep->ref++;
            }
            textPtr->p = chars;
        }
        func_005C2630(textPtr, 0, -1, literal, func_0057F260(literal));
        func_0023A538(resultPtr, third, first, textPtr, &handle);
        func_00250CE0(second, resultPtr);
        func_00239F08(resultPtr, 2);
        {
            Rep *rep = (Rep *)(textPtr->p - 0x10);
            if (--rep->ref == 0) {
                s32 bytes = rep->cap + 0x10;
                func_00326798(rep, bytes, 4, func_005C11A8()->name);
            }
        }
    }
    func_002ED5C0(&handle, 2);
}
