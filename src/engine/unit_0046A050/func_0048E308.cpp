/* Multiplies all 16 floats of a 4x4 matrix (or 16-float vector block, row layout unknown) by one scalar, in place. */
#include "types.h"

struct Vec16 {
    f32 m[16];
};

extern "C" void func_0048E308(struct Vec16 *matrix, f32 scale) {
    matrix->m[0] = matrix->m[0] * scale;
    matrix->m[1] = matrix->m[1] * scale;
    matrix->m[2] = matrix->m[2] * scale;
    matrix->m[3] = matrix->m[3] * scale;
    matrix->m[4] = matrix->m[4] * scale;
    matrix->m[5] = matrix->m[5] * scale;
    matrix->m[6] = matrix->m[6] * scale;
    matrix->m[7] = matrix->m[7] * scale;
    matrix->m[8] = matrix->m[8] * scale;
    matrix->m[9] = matrix->m[9] * scale;
    matrix->m[10] = matrix->m[10] * scale;
    matrix->m[11] = matrix->m[11] * scale;
    matrix->m[12] = matrix->m[12] * scale;
    matrix->m[13] = matrix->m[13] * scale;
    matrix->m[14] = matrix->m[14] * scale;
    matrix->m[15] = matrix->m[15] * scale;
}
