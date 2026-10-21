/* Sets a 4x4 float matrix at the start of the object to identity, then stores four more values: 1.0 at +0x40 and +0x4C, 0.1 at +0x44,
 * 750.0 at +0x48 and 0 at +0x50. They look like projection settings (near/far-like), but that is only a guess from the magnitudes. */

typedef int s32;
typedef float f32;
void func_003FB430(char *self)
{
  char *cell;
  f32 *diagonal;
  s32 i;
  s32 j;
  s32 rowOffset;
  for (i = 0, rowOffset = 0; i < 4; i++, rowOffset += 4)
  {
    cell = self + rowOffset;
    diagonal = (f32 *) (cell + (i * 16));
    for (j = 0; j < 4; j++)
    {
      if (!(i != j))
      {
        *diagonal = 1.0f;
      }
      else
      {
        *((s32 *) cell) = 0;
      }
      cell = cell + 16;
    }

  }

  *((f32 *) (self + 0x44)) = 0x1.9999980000000p-4f;
  *((f32 *) (self + 0x48)) = 750.0f;
  *((f32 *) (self + 0x40)) = (*((f32 *) (self + 0x4C)) = 1.0f);
  *((s32 *) (self + 0x50)) = 0;
}
