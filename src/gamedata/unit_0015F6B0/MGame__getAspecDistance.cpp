/* Script method getAspecDistance: reads a 64-bit distance counter from the game record at +0x3B8, converts it to the display unit with the unit manager (func_00472C28, float), formats the number into a 0x80-byte text buffer (func_0042E7E8), appends the unit name from func_00472898 (func_005A5DC8) and returns the text as a new script string through *out. The A-spec reading of the counter (driver mode total distance) is inferred from the name only. */
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

struct S00659988 {
    const char *name;
};

extern char PDISTD__UNIT_MANAGER[];
extern Rep D_00659FA8;
extern "C" s32 func_00472898(void *);
extern "C" void * func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, s32);
extern "C" f32 __floatdisf(s64);
extern "C" f32 func_00472C28(void *, f32);
extern "C" s32 func_0057F360(f32);
extern "C" void func_0042E7E8(s32, void *, s32);
extern "C" void * func_005A5DC8(void *, s32);
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void * func_005C2630(void *, s32, s32, void *, s32);
extern "C" void * func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MGame__getAspecDistance(s32 *out, void *object) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 buf7[4];
    s32 buf8[4];
    s32 buf9[4];
    Str textStrObj;
    char *unitManager;
    s32 *gameHandle;
    s32 unitName;
    s32 unitNameCopy;
    s64 distance;
    Str *textStr;
    s32 *text;
    s32 newVal;
    s32 oldVal;
    unitManager = (char *)&PDISTD__UNIT_MANAGER;
    unitName = func_00472898(unitManager);
    gameHandle = buf8;
    unitNameCopy = unitName;
    func_0015F3E0(gameHandle, object);
    distance = *(s64 *)((char *)(*(s32 *)((char *)(*gameHandle) + 0x10)) + 0x3b8);
    func_0015F388(gameHandle, 0x2);
    func_0042E7E8(func_0057F360(func_00472C28(unitManager, __floatdisf(distance))), buf0, 0x80);
    func_005A5DC8(buf0, unitNameCopy);
    textStr = &textStrObj;
    text = buf0;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        textStr->p = d;
    }
    func_005C2630(textStr, 0, -0x1, text, func_0057F260(text));
    func_00314B20(gameHandle, textStr);
    if (out != gameHandle) {
        newVal = *gameHandle;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *out;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *out = newVal;
    }
    func_00312318(gameHandle, 0x2);
    str_release(textStr);
}
