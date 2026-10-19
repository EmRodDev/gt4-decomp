#include "types.h"

struct SuggestedGearDisplay {
    char pad[0x54];
    s32 unk54;
};

struct RaceOnboardPanelLayout {
    char pad0[0xA78];
    SuggestedGearDisplay suggested_gear;
};

extern "C" void RaceOnboardPanel__setBrakingSign(RaceOnboardPanelLayout *arg0, s32 arg1) {
    SuggestedGearDisplay *obj = &arg0->suggested_gear;
    obj->unk54 = (obj->unk54 & 0xFFFFFF) | (arg1 << 24);
}
