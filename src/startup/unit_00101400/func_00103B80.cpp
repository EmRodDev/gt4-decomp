/* One-time lazy initialisation of a group of globals, each step guarded by 'still zero' (inferred from the tests): D_00618300 gets the
 * buffer D_0068C080 (initialised by func_00498B28); D_00618304 and D_00618308 get the result of func_00103B40 on a string
 * (the first on D_0068BE40, the second on the string at D_006184A0); finally a handler object is created (exception__structor_0
 * allocates 0x6C bytes, func_001031F0 constructs it around the record from func_00575070(0)), hooked into that record at +0x38 and +0x3C,
 * and the object D_006DE820 is constructed and its virtual slot 1 is called. The purpose of the whole group is unknown. */
#include "types.h"
struct Base { char pad[0x64]; virtual void v0(); virtual void v1(); };
struct Obj : public Base { char pad2[0x1000]; };
extern "C" {
void func_00102840(void *);
void func_001031D0();
void func_001031F0(void *, void *);
s32 func_00103B40(const char *) throw();
void func_00498B28(void *);
char *func_00575070(s32);
void func_005788B8(void *);
void *exception__structor_0(s32);
}
extern s32 D_00618300;
extern s32 D_00618304;
extern s32 D_00618308;
extern s32 D_00618318;
extern s32 D_0061831C;
extern s32 D_006184A0;
extern const char D_0068BE40[];
extern char D_0068C080[];
extern Obj D_006DE820;

extern "C" void func_00103B80(void) {
    if (D_00618300 == 0) {
        D_00618300 = (s32)D_0068C080;
        func_00498B28(D_0068C080);
    }
    s32 *secondSlot = &D_00618304;
    if (*secondSlot == 0) {
        *secondSlot = func_00103B40(D_0068BE40);
    }
    if (D_00618308 == 0) {
        D_00618308 = func_00103B40((const char *)D_006184A0);
    }
    if (D_00618318 == 0) {
        char *record = func_00575070(0);
        s32 *handlerSlot = (s32 *)&D_0061831C;
        *(void **)(record + 0x38) = (void *)func_001031D0;
        void *handler = exception__structor_0(0x6C);
        func_001031F0(handler, record);
        *handlerSlot = (s32)handler;
        *(void **)(record + 0x3C) = handler;
        func_005788B8(record);
        Obj *object = &D_006DE820;
        if (object) func_00102840(object);
        D_00618318 = (s32)object;
        object->v1();
    }
}
