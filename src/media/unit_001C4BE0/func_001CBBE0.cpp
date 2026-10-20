#include "types.h"

extern "C" s32 func_001CBBE0(s32 arg0) {
    return (arg0 & 0xF) + ((arg0 >> 4) * 0xA);
}
