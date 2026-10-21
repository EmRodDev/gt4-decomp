/* Scales the value from func_00350DA0 by a factor read from a float table (at +0x40 of the block at owner+0x234) selected by the
 * index byte at +0x104+0x520 (the byte func_0036BEB8 writes), never returning less than 0. When func_003F1F88 says so, the index is
 * capped at 1. Meaning of the value, table and index unknown. */

typedef int s32;
typedef float f32;
typedef unsigned char u8;
struct func_00350DA0_Obj;
struct S;
extern f32 func_00350DA0(struct func_00350DA0_Obj *self);
extern s32 func_003F1F88(struct S *self);
inline int inline_fn(s32 self)
{
  return self >= 2;
}

extern f32 func_00350E28(char *self)
{
  s32 owner = *((s32 *) (self + 0x10));
  char *state = self + 0x104;
  s32 block = owner + 0x234;
  f32 scaled = func_00350DA0((struct func_00350DA0_Obj *) self);
  s32 index = *((u8 *) (state + 0x520));
  if (func_003F1F88((struct S *) block) != 0)
  {
    index = (inline_fn(index)) ? (1) : (index);
  }
  f32 factor = *((f32 *) (((((s32) index) << 2) + block) + 0x40));
  scaled = scaled * factor;
  if (scaled <= 0.0f)
  {
    scaled = 0.0f;
  }
  return scaled;
}
