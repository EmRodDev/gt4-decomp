#include "types.h"

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 NormalCarGeometry__getSeatZ(Obj *arg0, s32 arg1);

extern "C" s32 NormalCarGeometry__GetOppositeSeatPosition_Z(Obj *arg0) {
    return NormalCarGeometry__getSeatZ(arg0, arg0->unk4 != 0);
}
