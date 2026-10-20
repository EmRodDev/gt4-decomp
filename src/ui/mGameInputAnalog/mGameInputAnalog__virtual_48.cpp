#include "types.h"

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

struct GameInputAnalogObj {
    char pad0[0x10];
    char device[1];
};

static inline s32 vcall_58(VObj *o) {
    VEntry *e = &o->vtbl[11];
    return e->fn((char *)o + e->delta);
}

extern "C" s32 func_0055EF50(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void mGameInputAnalog__virtual_48(GameInputAnalogObj *arg0, void *arg1, s32 arg2, char **arg3, VObj **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if ((s32)arg3 > 0) {
        func_002FE278(buf0, func_0055EF50(arg0->device, vcall_58(*arg4)));
        if (arg1 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *(s32 *)arg1;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *(s32 *)arg1 = newVal;
        }
        func_002FC870(buf0, 0x2);
    }
}
