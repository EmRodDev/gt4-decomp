#include "types.h"

struct RaceOnboardPanelLayout {
    char pad0[0xC8];
    char tachometer[0x58];
};

extern "C" void RaceRoundTachometerBase__setRedZone(void *arg0, f32 arg1);

extern "C" void RaceOnboardPanel__setTachometerRedZone(RaceOnboardPanelLayout *arg0, s32 arg1) {
    RaceRoundTachometerBase__setRedZone(arg0->tachometer, (f32)arg1);
}
