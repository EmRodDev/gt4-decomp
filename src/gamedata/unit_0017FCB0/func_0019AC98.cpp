/* Calls a script-side function by name: builds a default handle, combines it with two values (the string arg3 as a script string, and the boolean arg4 != 0), then with the fixed string D_006925E8 forms a call via func_0023A538(result, arg2, arg0, name, handle) and hands the result to func_00250CE0 with arg1; all temporaries are destroyed afterwards. The name 'script call' is inferred from the helpers' shape (same family as func_00193E00); the meaning of arg0..arg2 is not determined. */
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
extern char D_006925E8[];

extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, void *, void *, void *, void *);
extern "C" void func_00250CE0(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, void *, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void func_0019AC98(void *arg0, void *arg1, void *arg2, const char *text, s32 flag) {
    struct { void *p; char pad[0xC]; } handle;
    Obj16 result;
    Obj16 textValue;
    Str textStr;
    Obj16 flagValue;
    Str fixedName;
    Obj16 *resultPtr;
    const char *literal;
    func_002EFBF0(&handle);
    resultPtr = &result;
    {
        Str *strPtr = &textStr;
        void *handleRaw = handle.p;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        strPtr->p = chars;
        func_005C2630(strPtr, 0, -1, text, func_0057F260(text));
        Obj16 *textValuePtr = &textValue;
        func_00314B20(textValuePtr, strPtr);
        func_002EEEB0(resultPtr, handleRaw, textValuePtr);
        func_00309378(resultPtr, 2);
        func_00312318(textValuePtr, 2);
        {
            Rep *rep = (Rep *)(strPtr->p - 0x10);
            if (--rep->ref == 0) {
                s32 size = rep->cap + 0x10;
                func_00326798(rep, size, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Obj16 *flagValuePtr = &flagValue;
        void *handleRaw = handle.p;
        func_002FE278(flagValuePtr, flag != 0);
        func_002EEEB0(resultPtr, handleRaw, flagValuePtr);
        func_00309378(resultPtr, 2);
        func_002FC870(flagValuePtr, 2);
    }
    {
        Str *strPtr = &fixedName;
        literal = D_006925E8;
        {
            Rep *emptyRep = &D_00659FA8;
            char *chars;
            if (emptyRep->sel != 0) {
                chars = func_005C2560(emptyRep);
            } else {
                chars = (char *)(emptyRep + 1);
                emptyRep->ref++;
            }
            strPtr->p = chars;
        }
        func_005C2630(strPtr, 0, -1, literal, func_0057F260(literal));
        func_0023A538(resultPtr, arg2, arg0, strPtr, &handle);
        func_00250CE0(arg1, resultPtr);
        func_00239F08(resultPtr, 2);
        {
            Rep *rep = (Rep *)(strPtr->p - 0x10);
            if (--rep->ref == 0) {
                s32 size = rep->cap + 0x10;
                func_00326798(rep, size, 4, func_005C11A8()->name);
            }
        }
    }
    func_002ED5C0(&handle, 2);
}
