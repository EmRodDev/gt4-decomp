/* Script method GetVelocityString: when called with arguments (arg1 > 0) it asks the object in argument 0 for a float (virtual slot +0x60, a velocity - name-based inference), converts it with func_00472940 and the factor 0.2778 (1/3.6) when the unit manager PDISTD__UNIT_MANAGER is set, formats the value in tenths (value*10+0.5, with the unit text from func_00472680) using the format string D_00693040 and func_00490A40 into a 0x80-byte buffer and returns it as a new script string through *out. Which direction the 1/3.6 conversion goes (km/h to m/s or the reverse) was not checked. */
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
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObjF {
    char pad[4];
    VEntryF *vtbl;
};

extern Rep D_00659FA8;
extern s32 PDISTD__UNIT_MANAGER;
extern void *D_00624984;
extern char D_00693040[];

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" f32 func_00472940(s32 *p, f32 x);
extern "C" char *func_00472680(s32 *p);
extern "C" void func_00490A40(void *a, void *b, const char *fmt, ...);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline f32 vcallf(VObjF *o) {
    VEntryF *e = &o->vtbl[12];
    return e->fn((char *)o + e->delta);
}

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MUnit__GetVelocityString(void **out, s32 argCount, void **args) {
    if (argCount > 0) {
        char text[0x80];
        Handle result;
        s32 spare[4];
        Str textStr;
        f32 velocity;
        s32 *unitManager;

        velocity = vcallf((VObjF *)*args);
        unitManager = &PDISTD__UNIT_MANAGER;
        if (*unitManager != 0) {
            velocity = func_00472940(unitManager, velocity * 0x1.1C71C6p-2f);
        }
        func_00490A40(D_00624984, text, D_00693040,
                      (s32)(velocity * 10.0f + 0.5f), func_00472680(unitManager));
        {
            Rep *emptyRep = &D_00659FA8;
            Str *textStrPtr;
            char *textPtr;
            char *chars;
            textStrPtr = &textStr;
            textPtr = text;
            if (emptyRep->sel != 0) {
                chars = func_005C2560(emptyRep);
            } else {
                chars = (char *)(emptyRep + 1);
                emptyRep->ref++;
            }
            textStrPtr->p = chars;
            func_005C2630(textStrPtr, 0, -1, textPtr, func_0057F260(textPtr));
            {
                Handle *resultPtr = &result;
                func_00314B20(resultPtr, textStrPtr);
                if ((void *)out != (void *)resultPtr) {
                    void *p = resultPtr->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*out != 0) {
                        func_003285F8(*out);
                    }
                    *out = p;
                }
                func_00312318(resultPtr, 2);
            }
            str_release(textStrPtr);
        }
    }
}
