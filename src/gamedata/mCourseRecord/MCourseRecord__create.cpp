/* Script native for MCourseRecord.create (inferred from the symbol name): asks the record table to create an entry for a course name and returns whether that worked.
 * The context handle (func_0015C710) holds an object with the table at +0x10; the name is args[0] read as a string through vtable slot 0x18.
 * func_00433AA0(table, name) != 0 gives the success flag, which func_002FE278 boxes into an int handle and stores into out with retain-new / release-old.
 * Needs argc > 0. The handle h is reused for the context first and for the boxed result afterwards, hence a single declaration. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
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
    s16 delta;
    s16 index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct S00659988 {
    const char *name;
};

extern char D_0068FFA0[];

extern "C" void func_0015C710(void *out, void *arg);
extern "C" void func_0015C6B8(void *arg0, int flags);
extern "C" void func_002FE278(void *out, s32 value);
extern "C" void func_002FC870(void *arg0, int flags);
extern "C" s32 func_00433AA0(s32 arg0, const char *ctx);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

static inline void str_release(Str *nameStr) {
    Rep *q = (Rep *)(nameStr->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *nameStr) {
    s32 len = *(s32 *)(nameStr->p - 0x10);
    if (len == 0) return D_0068FFA0;
    nameStr->p[len] = 0;
    return nameStr->p;
}

extern "C" void MCourseRecord__create(s32 *out, void *ctx, s32 argc, Obj **args) {
    if (argc > 0) {
        Handle handle;
        s32 created;
        {
            Str nameStr;
            Obj *nameArg;
            VEntry *slot18;
            Obj *table;

            func_0015C710(&handle, ctx);
            table = *(Obj **)((char *)handle.p + 0x10);
            nameArg = *args;
            slot18 = (VEntry *)(nameArg->vtbl + 0x18);
            slot18->fn(&nameStr, (char *)nameArg + slot18->delta);
            created = func_00433AA0((s32)table, c_str(&nameStr)) != 0;
            str_release(&nameStr);
            func_0015C6B8(&handle, 2);
        }

        s32 newVal;
        s32 oldVal;
        func_002FE278(&handle, created);
        if (out != (s32 *)&handle) {
            newVal = (s32)handle.p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *out;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *out = newVal;
        }
        func_002FC870(&handle, 2);
    }
}
