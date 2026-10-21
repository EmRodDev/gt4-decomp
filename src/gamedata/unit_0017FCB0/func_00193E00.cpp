/* Builds a result object from two float arguments and a fixed string (D_00692238): two 16-byte values are created from f1 and f2 (func_002F9360), combined with a handle (func_002EFBF0 default-constructed, then func_002EEEB0) and passed with arg0/arg2 to func_0023A538; the object it returns is handed to func_00250CE0 together with arg1 and then destroyed. What the objects are is unknown; the string temporary is destroyed inline (expanded basic_string destructor). */
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
extern char D_00692238[];

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

extern "C" void func_00193E00(void *arg0, void *arg1, void *arg2, float firstFloat, float secondFloat) {
    struct { void *p; char pad[0xC]; } handle;
    Obj16 result;
    Obj16 valueA;
    Obj16 valueB;
    Str text;
    const char *literal;
    Obj16 *resultPtr;
    func_002EFBF0(&handle);
    resultPtr = &result;
    {
        Obj16 *valueAPtr = &valueA;
        void *handleRaw = handle.p;
        func_002F9360(valueAPtr, firstFloat);
        func_002EEEB0(resultPtr, handleRaw, valueAPtr);
        func_00309378(resultPtr, 2);
        func_002F7B68(valueAPtr, 2);
    }
    {
        Obj16 *valueBPtr = &valueB;
        void *handleRaw = handle.p;
        func_002F9360(valueBPtr, secondFloat);
        func_002EEEB0(resultPtr, handleRaw, valueBPtr);
        func_00309378(resultPtr, 2);
        func_002F7B68(valueBPtr, 2);
    }
    {
        Str *textPtr = &text;
        literal = D_00692238;
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
        func_0023A538(resultPtr, arg2, arg0, textPtr, &handle);
        func_00250CE0(arg1, resultPtr);
        func_00239F08(resultPtr, 2);
        {
            Rep *rep = (Rep *)(textPtr->p - 0x10);
            if (--rep->ref == 0) {
                s32 size = rep->cap + 0x10;
                func_00326798(rep, size, 4, func_005C11A8()->name);
            }
        }
    }
    func_002ED5C0(&handle, 2);
}
