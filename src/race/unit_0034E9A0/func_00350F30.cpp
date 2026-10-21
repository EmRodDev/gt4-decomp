/* Reads the float stored at +0x738 of the object and returns it truncated to an integer. The 0040CA58 caller feeds the result into thresholds
 * of 1000 and 99999, so it is a large integer-valued quantity such as an engine speed in rpm (inferred from those thresholds; the field's real
 * identity is not confirmed). */
#include "types.h"

extern "C" s32 func_00350F30(void *object) {
    return (s32)*(f32 *)((char *)object + 0x738);
}
