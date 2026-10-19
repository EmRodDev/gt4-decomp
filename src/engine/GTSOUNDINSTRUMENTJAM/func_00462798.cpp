#include "types.h"

extern s32 D_00623A38;

extern "C" s32 func_00462798(s32 arg0) {
    s32 old_val = D_00623A38;
    D_00623A38 = arg0;
    return old_val;
}
