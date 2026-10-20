#include "types.h"

extern s32 D_008686B8[];

s32 func_00535A18(u32 arg0) {
    if (arg0 < 4U) {
        return D_008686B8[arg0];
    }
    return 0;
}
