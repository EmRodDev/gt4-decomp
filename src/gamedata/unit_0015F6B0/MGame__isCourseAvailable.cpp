/* Script method isCourseAvailable(name): resolves the course name in args[0] to an index (func_00447C78; nothing is returned when it is -1), asks the course table in the game data at +0x36550 (func_0042EAE8) whether that course is available and returns the answer as a script number through *out. Sibling of isCarAvailable. 'Available' is taken from the method name. */
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
    char pad[0xC];
};

union StrOrHandle {
    Str s;
    Handle res;
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

extern char D_006901F0[];

extern "C" void func_0015F388(void *arg0, int arg1) throw();
extern "C" void *func_0015F3E0(void *arg0, void *arg1) throw();
extern "C" void func_002FC870(void *arg0, int arg1) throw();
extern "C" void func_002FE278(void *arg0, void *arg1) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name) throw();
extern "C" void func_003285A8(void *p) throw();
extern "C" void func_003285F8(void *p) throw();
extern "C" int func_0042EAE8(void *arg0, void *arg1) throw();
extern "C" s32 func_00447C78(s32 arg0) throw();
extern "C" struct S00659988 *func_005C11A8(void) throw();

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006901F0;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MGame__isCourseAvailable(void **out, void *object, s32 argCount, void **args) {
    if (argCount > 0) {
        union StrOrHandle scratch;
        Handle h;
        Handle *gameHandle;

        {
            Obj *o = *(Obj **)args;
            VEntry *e;
            e = (VEntry *)(o->vtbl + 0x18);
            e->fn(&scratch.s, (char *)o + e->delta);
        }
        s32 courseIndex = func_00447C78((s32)c_str(&scratch.s));
        str_release(&scratch.s);
        if (courseIndex != -1) {
            gameHandle = &h;
            func_0015F3E0(gameHandle, object);
            Obj *gameData = *(Obj **)((char *)gameHandle->p + 0x10);
            int answer = func_0042EAE8((char *)gameData + 0x36550, (void *)courseIndex);
            func_002FE278(&scratch.res, (void *)answer);
            if ((void *)out != (void *)&scratch.res) {
                void *p = scratch.res.p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*out != 0) {
                    func_003285F8(*out);
                }
                *out = p;
            }
            func_002FC870(&scratch.res, 2);
            func_0015F388(gameHandle, 2);
        }
    }
}
