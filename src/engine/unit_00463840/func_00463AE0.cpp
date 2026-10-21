/* Maintains the byte at +0x14+0x1A: it is set to 1 unless a condition holds, and when it is still 0 afterwards it takes the byte at
 * 0xCBE9 of the object linked at +4. The condition (call it active) needs the mode byte at +0x104+0x466 to be 1 or 2, func_0034C998 on
 * the linked object to return 0, the float at +0x104+0x53C to be below 0x1.0AAAA8p+3 (25/3, about 8.33), the byte at +0x104+0x467 to
 * be 0, and the flag argument to be non-zero. Meaning of all these fields unknown. */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern s32 func_0034C998(char *c);
extern void func_00463AE0(char *self, s32 flag)
{
  char *state = self + 0x104;
  char *block14 = self + 0x14;
  u8 mode466 = *((u8 *) (state + 0x466));
  char *linked = *((char **) (self + 4));
  s32 active;
  if (!(((u32) (mode466 - 1)) < 2))
  {
    active = 0;
  }
  else
  {
    s32 blocked = func_0034C998(linked);
    active = 0;
    if (blocked == 0)
    {
      if (!(0x1.0AAAA8p+3f <= (*((f32 *) (state + 0x53C)))))
      {
        if ((*((u8 *) (state + 0x467))) == 0)
        {
          active = flag != 0;
        }
      }
    }
  }
  if (active == 0)
  {
    *((u8 *) (block14 + 0x1A)) = 1;
  }
  if ((*((u8 *) (block14 + 0x1A))) == 0)
  {
    *((u8 *) (block14 + 0x1A)) = *((u8 *) (linked + 0xCBE9));
  }
}
