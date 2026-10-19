#include "types.h"

extern "C" void RaceRoundTachometerBase__setScale(s32 arg0);

extern "C" void RaceOnboardPanel__setTachometerScale(s32 arg0) {
    RaceRoundTachometerBase__setScale(arg0 + 0xC8);
}
