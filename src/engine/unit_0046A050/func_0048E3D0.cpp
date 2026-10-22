/* Divides each of the 16 floats of a 4x4 matrix by one scalar, with a real division per element (the source casts
 * each quotient to f32, as in the matched code). Counterpart of func_0048E240, which subtracts instead. Use of the
 * result is unknown. */
#include "types.h"

struct func_0048E3D0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

extern void func_0048E3D0(struct func_0048E3D0_arg0 *matrix, f32 divisor)
{
  matrix->unk0 = (f32) (matrix->unk0 / divisor);
  matrix->unk4 = (f32) (matrix->unk4 / divisor);
  matrix->unk8 = (f32) (matrix->unk8 / divisor);
  matrix->unkC = (f32) (matrix->unkC / divisor);
  matrix->unk10 = (f32) (matrix->unk10 / divisor);
  matrix->unk14 = (f32) (matrix->unk14 / divisor);
  matrix->unk18 = (f32) (matrix->unk18 / divisor);
  matrix->unk1C = (f32) (matrix->unk1C / divisor);
  matrix->unk20 = (f32) (matrix->unk20 / divisor);
  matrix->unk24 = (f32) (matrix->unk24 / divisor);
  matrix->unk28 = (f32) (matrix->unk28 / divisor);
  matrix->unk2C = (f32) (matrix->unk2C / divisor);
  matrix->unk30 = (f32) (matrix->unk30 / divisor);
  matrix->unk34 = (f32) (matrix->unk34 / divisor);
  matrix->unk38 = (f32) (matrix->unk38 / divisor);
  matrix->unk3C = (f32) (matrix->unk3C / divisor);
}
