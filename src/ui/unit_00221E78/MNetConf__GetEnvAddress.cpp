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

struct VEntry_340 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_340 { char pad0[4]; VEntry_340 *vtbl; };
static inline s32 vcall_340(char *o) {
    VEntry_340 *e = &((VObj_340 *)o)->vtbl[104];
    return e->fn(o + e->delta);
}
extern "C" void func_00221B28(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00221AD0(void *, s32);

extern "C" void MNetConf__GetEnvAddress(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s2 = buf1;
    func_00221B28(p_s2);
    func_002FE278(buf0, vcall_340((char *)*p_s2));
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf0, 0x2);
    func_00221AD0(p_s2, 0x2);
}
