/* Script-engine registration for MHBox: sets its name through the vtable, links it to its parent class,
 * then registers 1 registrations on a global symbol object
 * so scripts can call into C++ (see knowledge/script-engine.md, section 3.3).
 * Each registration builds the member name as a refcounted string from a literal and releases it afterwards;
 * the repeated inline blocks are the compiler expansion of that string constructor/destructor and are kept as is. */
#define GT4_CXX
#include "gt4/hModule.h"
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
extern "C" int mDBox__GetClassID(void);
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);

extern char D_008369F0[];
extern "C" void MHBox__global_008369F0(void);
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));

extern "C" void func_002A0498(Obj *cls) {
    Str name;
    Str *namePtr = &name;
    const char *literal = "MSceneViewFace";
    Rep *emptyRep = &D_00659FA8;
    char *chars = (char *)(emptyRep + 1);
    if (emptyRep->sel != 0) {
        chars = func_005C2560(emptyRep);
    } else {
        emptyRep->ref++;
    }
    namePtr->p = chars;
    func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
    ((hModule *)(void *)cls)->setName(&name);
    {
        Rep *rep = (Rep *)(name.p - 0x10);
        if (--rep->ref == 0) {
            s32 blockSize = rep->cap + 0x10;
            func_00326798(rep, blockSize, 4, func_005C11A8()->name);
        }
    }
    func_002F3A30(cls, mDBox__GetClassID());
    func_00306780(cls, D_008369F0, MHBox__global_008369F0);
}
