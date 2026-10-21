/* Draws one model of a set: positions at (x from +0x3C, 0, z from +0x40) with func_004A7844, rotates by the angle at +0x5C
 * multiplied by 57.324841 (close to 180/pi, so a radians-to-degrees conversion; the constant is kept as in the original),
 * then calls ModelSet2::render with the model that the index at +0x30 selects in the table passed as the last argument. */
#include "types.h"

extern "C" void func_004A7844(f32 a, f32 b, f32 c);
extern "C" void func_004A79B0(f32 a);
extern "C" void ModelSet2___render(s32 a0, s32 a1, s32 a2);

extern "C" void func_003D49D0(void *self, s32 renderArg1, s32 renderArg3, s32 unusedArg, s32 *modelTable) {
    func_004A7844(*(f32 *)((char *)self + 0x3C), 0.0f, *(f32 *)((char *)self + 0x40));
    func_004A79B0(*(f32 *)((char *)self + 0x5C) * 57.324841f);
    ModelSet2___render(renderArg1, modelTable[*(s32 *)((char *)self + 0x30)], renderArg3);
}
