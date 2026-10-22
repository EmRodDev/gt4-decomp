/* Script native for MCourseRecord.getUnit (inferred from the symbol name): looks a record up by name and returns it as a handle.
 * The context handle (func_0015C710) holds an object whose +0x10 member is the table; args[0] is read as a string through vtable slot 0x18
 * and passed to func_00433C10(table, name), which returns the record or 0. A non-null record is wrapped (func_0015AD00) and assigned to ret
 * with retain-new / release-old; the handle is then destroyed with func_0015AA68(&h, 2). Only runs when argc > 0. */
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

struct Handle {
    void *p;
    char pad[0x1C];
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern char D_0068FFA0[];

extern "C" void func_0015AA68(void *ret, int ctx) throw();
extern "C" void func_0015AD00(void *ret, void *ctx) throw();
extern "C" void func_0015C6B8(void *ret, int ctx) throw();
extern "C" void func_0015C710(void *ret, void *ctx) throw();
extern "C" s32 func_00433C10(Obj *o, const char *name) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" void func_003285A8(void *p) throw();
extern "C" void func_003285F8(void *p) throw();
extern "C" struct S00659988 *func_005C11A8(void) throw();

static inline void str_release(Str *nameStr) {
    Rep *q = (Rep *)(nameStr->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_0068FFA0;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MCourseRecord__getUnit(void **ret, void *ctx, s32 argc, void **args) {
    if (argc > 0) {
        Handle handle;
        Str nameStr;
        Str *namePtr;
        int unit;

        func_0015C710(&handle, ctx);
        {
            Obj *o = *(Obj **)args;
            Obj *table = *(Obj **)((char *)handle.p + 0x10);
            VEntry *e;
            namePtr = &nameStr;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(namePtr, (char *)o + e->delta);
            unit = func_00433C10(table, c_str(namePtr));
        }
        str_release(namePtr);
        func_0015C6B8(&handle, 2);
        if (unit != 0) {
            func_0015AD00(&handle, (void *)unit);
            if ((void *)ret != (void *)&handle) {
                void *p = handle.p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*ret != 0) {
                    func_003285F8(*ret);
                }
                *ret = p;
            }
            func_0015AA68(&handle, 2);
        }
    }
}
