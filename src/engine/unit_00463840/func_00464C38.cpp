/* Stores the new mode in the byte at 0x467 of the sub-state at +0x104. For mode 6, or for mode 5 when the old mode was not 4,
 * it writes 0x78 into the byte at 0x52 of the block at +0x14. Both arms of the inner if write the same value; the duplicate is
 * kept as it is (inferred: identical arms, so it is probably there to shape the compiled code). Meaning of the modes unknown. */

typedef unsigned char u8;
struct Sub
{
  char pad[0x467];
  u8 unk467;
};
extern void func_00464C38(void *self, int mode)
{
  struct Sub *state = (struct Sub *) (((char *) self) + 0x104);
  char *block14 = ((char *) self) + 0x14;
  u8 oldMode = state->unk467;
  int modeBelow7 = mode < 7;
  state->unk467 = (u8) mode;
  if ((mode == 6) || ((modeBelow7 && (mode == 5)) && (oldMode != 4)))
  {
    if (modeBelow7 || oldMode)
    {
      *((u8 *) (block14 + 0x52)) = 0x78;
    }
    else
    {
      *((u8 *) (block14 + 0x52)) = 0x78;
    }
  }
}
