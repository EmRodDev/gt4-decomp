/* Returns 1 when the course position stored at +0x104+0x4A4 lies between the two limits func_0034C780(conductor, +1) and
 * func_0034C780(conductor, -1); 0 otherwise. It only answers for mode bytes 2..4 (the byte at +0x104+0x467, the one
 * func_00464C38 writes; same offset, inferred) and returns 0 for any other mode. A position in the first half of the course is
 * first moved forward by one DynamicsConductor::GetCourseLength (name from the symbol table), so it compares in lap-unwrapped form. */
#include "types.h"

extern "C" f32 DynamicsConductor__GetCourseLength(char *arg0);
extern "C" f32 func_0034C780(char *arg0, s32 arg1);

extern "C" s32 func_0035AE58(char *self) {
    s32 result = 0;
    char *state = self + 0x104;
    char *conductor = *(char **)(self + 0x4);
    u32 modeMinus2 = (u32)((*(u8 *)(state + 0x467) + 0xFE) & 0xFF);
    if (!(modeMinus2 < 3)) {
        return result;
    }
    f32 courseLength = DynamicsConductor__GetCourseLength(conductor);
    f32 coursePosition = *(f32 *)(state + 0x4A4);
    if (coursePosition < courseLength * 0.5f) {
        coursePosition += courseLength;
    }
    if (coursePosition < func_0034C780(conductor, 1)) {
        return result;
    }
    if (func_0034C780(conductor, -1) < coursePosition) {
        return 0;
    }
    return 1;
}
