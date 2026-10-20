#include "types.h"

struct VEntry_003BCBD0 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Obj_003BCBD0 {
    char pad0[0x64];
    VEntry_003BCBD0 *vtbl;
};

extern "C" int RaceBase__getRaceModeKeyString(int arg0);

extern "C" int RaceTraining__getRaceModeKey(struct Obj_003BCBD0 *arg0, void *arg1) {
    VEntry_003BCBD0 *e = &arg0->vtbl[96];
    s32 r = e->fn((char *)arg0 + e->delta, arg1);

    return RaceBase__getRaceModeKeyString(r);
}
