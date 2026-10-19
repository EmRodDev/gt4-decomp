#include "types.h"

extern "C" void func_004BC818(u16 *arg0, u8 *arg1, s32 arg2) {
    s32 half = (arg2 + (s32)((unsigned)arg2 >> 31)) >> 1;
    u16 *dst = arg0;
    u8 *src = arg1;
    if (half > 0) {
        do {
            s32 v = *src << 8;
            src++;
            *dst = (u16)v;
            v = v | *src;
            src++;
            *dst = (u16)v;
            dst++;
            half--;
        } while (half > 0);
    }
}
