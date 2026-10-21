/* Computes two values from a pair of wheels (the wheel records are 0xEC bytes apart; the pair is looked up in the car's
 * axle table): returns 0.2 * (sum of their f64) and writes 0.012 * |mean f20| + 0.3 to *outFactor. When the two guard values
 * at +0x48C and +0x514 are zero it returns 0 and *outFactor = 1.0. Meaning of both results is unknown. */

typedef int s32;
typedef unsigned char u8;
typedef float f32;
struct func_00369510_p10
{
  char pad0[0x237];
  u8 b237;
};
struct func_00369510_arg0
{
  char pad0[0x10];
  struct func_00369510_p10 *p10;
};
struct func_00369510_ent
{
  char pad0[0x20];
  f32 f20;
  char pad24[0x40];
  f32 f64;
};
extern s32 func_00359538(void *);
extern f32 func_00369510(struct func_00369510_arg0 *self, f32 *outFactor)
{
  char *v = ((char *) self) + 0x104;
  f32 new_var;
  if (((new_var = *((f32 *) (v + 0x48C))) == 0.0f) || ((*((f32 *) (v + 0x514))) == 0.0f))
  {
    *outFactor = 1.0f;
    return 0.0f;
  }
  s32 axleTable = func_00359538(self);
  u8 *axleRow = (u8 *) (axleTable + self->p10->b237);
  u8 wheelIndexA = axleRow[0xC];
  u8 wheelIndexB = ((u8 *) (wheelIndexA + axleTable))[0x24];
  struct func_00369510_ent *wheelA = (struct func_00369510_ent *) ((((char *) self) + (wheelIndexA * 0xEC)) + 0x164);
  struct func_00369510_ent *wheelB = (struct func_00369510_ent *) ((((char *) self) + (wheelIndexB * 0xEC)) + 0x164);
  f32 meanF20 = (wheelA->f20 + wheelB->f20) * 0x1.0p-1f;
  if (meanF20 < 0.0f)
  {
    meanF20 = -meanF20;
  }
  f32 b;
  f32 scaledMean = meanF20 * 0x1.89374Cp-7f;
  f32 baseFactor = 0x1.333332p-2f;
  f32 sumF64 = wheelA->f64 + wheelB->f64;
  f32 factor = scaledMean + baseFactor;
  f32 result = sumF64 * 0x1.999998p-3f;
  *outFactor = factor;
  return result;
}
