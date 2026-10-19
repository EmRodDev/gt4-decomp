#include "types.h"

extern "C" void RaceOnboardPanel__showSideGravity(char *arg0, u8 arg1) {
    s32 *p = (s32 *)(arg0 + 0xC24);
    *p = (*p & ~0xFF) | arg1;
}
