#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Obj {
    char pad[0x10];
    char *dat;
};

extern "C" s32 func_00314B10(Obj *arg0) {
    return ((Rep *)arg0->dat)[-1].len;
}
