#include "types.h"

struct BrakingSignDisplay {
    char pad[0x54];
    s32 unk54;
};

struct RaceSimplePanelLayout {
    char pad0[0x17C];
    BrakingSignDisplay braking_display;
};

extern "C" void RaceSimplePanel__setBrakingSign(RaceSimplePanelLayout *arg0, s32 arg1) {
    BrakingSignDisplay *obj = &arg0->braking_display;
    obj->unk54 = (obj->unk54 & 0xFFFFFF) | (arg1 << 24);
}
