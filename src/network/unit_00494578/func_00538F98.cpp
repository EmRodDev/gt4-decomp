#include "types.h"

extern "C" s32 func_00538F98(u8 *arg0, u16 *arg1) {
    u8 *p = arg0;
    s32 a;

    if (p == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    a = p[0];
    *arg1 = a;
    *arg1 = a | (p[1] << 8);
    return 0;
}
