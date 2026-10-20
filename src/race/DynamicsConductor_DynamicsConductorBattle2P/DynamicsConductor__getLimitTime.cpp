#include "types.h"

struct Obj {
    char pad[0xF850];
    u16 unkF850;
};

extern "C" s32 DynamicsConductor__getLimitTime(Obj *arg0) {
    return arg0->unkF850 * 0xEA60;
}
