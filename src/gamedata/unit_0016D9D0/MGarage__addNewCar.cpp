/* Script method addNewCar(carName, a, [b]): needs at least 2 arguments; takes the garage record from the object handle (+0x10), the car name from args[0], the integer args[1] and the optional integer args[2] (0 when absent), plus the global value at D_00622F4C+0xBC28, calls func_00435800 to add the car to the garage and returns its result as a script number through *out. Which argument is which game value (color, price, ...) is not determined; names are by position. */
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

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntryI {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryV {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

extern char D_00690A30[];
extern void *D_00622F4C;

extern "C" void func_0016D7F0(void *arg0, int arg1);
extern "C" void func_0016D848(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_00435800(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_00690A30;
    t->p[len] = 0;
    return t->p;
}

static inline s32 vcall58(void *obj) {
    Obj *o = (Obj *)obj;
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void MGarage__addNewCar(void **out, void *object, s32 argCount, void **args) {
    if (argCount >= 2) {
        Str scratch;
        s32 optionalArg = 0;
        s32 garage;
        s32 globalValue;
        s32 secondArg;

        func_0016D848(&scratch, object);
        garage = *(s32 *)((char *)scratch.p + 0x10);
        func_0016D7F0(&scratch, 2);
        globalValue = *(s32 *)((char *)D_00622F4C + 0xBC28);
        if (argCount >= 3) {
            optionalArg = vcall58(args[2]);
        }
        secondArg = vcall58(args[1]);
        {
            Obj *o = *(Obj **)args;
            VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
            e->fn(&scratch, (char *)o + e->delta);
        }
        globalValue = func_00435800(garage, (s32)c_str(&scratch), secondArg, globalValue, optionalArg);
        str_release(&scratch);
        func_002FE278(&scratch, (void *)globalValue);
        if ((void *)out != (void *)&scratch) {
            void *p = scratch.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*out != 0) {
                func_003285F8(*out);
            }
            *out = p;
        }
        func_002FC870(&scratch, 2);
    }
}
