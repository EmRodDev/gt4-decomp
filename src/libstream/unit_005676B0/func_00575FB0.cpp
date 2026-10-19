#include "types.h"

extern "C" s32 malloc(s32 arg0);

extern "C" s32 func_00575FB0(s32 arg0, s32 arg1) {
    return malloc(arg1);
}
