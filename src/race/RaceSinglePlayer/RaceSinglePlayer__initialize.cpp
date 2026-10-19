#include "types.h"

struct RaceSinglePlayerLayout {
    char pad0[0xCC8];
    u32 unkCC8;
    char padCCC[0x123CC - 0xCCC];
    char race_input[0x100];
};

extern "C" void RaceBasic__initialize();
extern "C" void RaceInput__setRunMode(void *arg0, u32 arg1);

extern "C" void RaceSinglePlayer__initialize(RaceSinglePlayerLayout *arg0) {
    RaceSinglePlayerLayout *s0 = arg0;
    RaceBasic__initialize();
    RaceInput__setRunMode(s0->race_input, s0->unkCC8);
}
