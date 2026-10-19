#include "types.h"

extern "C" s32 func_00525648(s32 arg0, s32 arg1) {
    return (arg1 & 0xFFF) | ((arg0 & 0xF) << 0xC);
}
