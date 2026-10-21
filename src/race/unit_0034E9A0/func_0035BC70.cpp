/* Consumes a one-shot request: when bit 0 of the u16 at +0x5BC is set it is cleared, bit 0x10 is set, and the function returns a mask
 * made of 1 (7 when bit 4 is set), bit 8 and 0x10 when the mode byte at +0x104+0x466 equals 1. Returns 0 when bit 0 was clear.
 * The names of the bits are unknown. */

typedef int s32;
typedef unsigned short u16;
typedef signed char s8;
inline int inline_fn(s32 arg0, s32 arg1)
{
  return arg0 | arg1;
}

s32 func_0035BC70(char *arg0)
{
  u16 *flagsPtr = (u16 *) (arg0 + 0x5BC);
  s8 *state = (s8 *) (arg0 + 0x104);
  s32 mask;
  s32 flags;
  s32 newFlags;
  s32 bit4;
  s32 bit8;
  s8 modeByte;
  s32 notMode1;
  flags = (s32) (*flagsPtr);
  mask = 0;
  flags = flags ^ 1;
  newFlags = inline_fn(flags, 0x10);
  flags = flags & 1;
  if (flags != 0)
  {
    return mask;
  }
  *flagsPtr = (u16) newFlags;
  mask = 1;
  bit4 = newFlags & 4;
  bit8 = newFlags & 8;
  if (bit4 != 0)
  {
    mask = 7;
  }
  modeByte = state[0x466];
  mask = inline_fn(bit8, mask);
  notMode1 = ((s32) modeByte) ^ 1;
  if (notMode1 == 0)
  {
    mask = mask | 0x10;
  }
  return mask;
}
