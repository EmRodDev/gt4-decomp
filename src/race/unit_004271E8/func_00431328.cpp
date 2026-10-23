/* Use the original shared strings so this routine can be linked from source. */
extern const char resourcePrefix[] __asm__("D_006A5520");
extern const char resourceNameFormat[] __asm__("D_006A5518");
#include "types.h"

extern "C" s32 func_004311A0(s32 arg0, const char *arg1, const char *arg2, u8 arg3, s32 arg4, s32 arg5);

extern "C" s32 func_00431328(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_004311A0(arg0, (const char *)resourcePrefix, (const char *)resourceNameFormat, (u8)(arg1 & 0xFF), arg2, arg3);
}
