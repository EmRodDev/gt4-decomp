/* Piecewise-linear curve that falls as the input grows: 16 up to 2, 4 at 15, 1 at 30, 0.1 at 90 and constant 0.1 beyond (the break
 * points are the hex-float constants). What the input and output mean is unknown. */

typedef float f32;
f32 func_0036EDB0(f32 input)
{
  f32 value;
  f32 upperBound;
  ;
  if (input <= 0x1.0p+1f)
  {
    return 0x1.0p+4f;
  }
  if (input < 0x1.ep+3f)
  {
    value = (((0x1.ep+3f - input) * 0x1.8p+3f) / 0x1.ap+3f) + 0x1.0p+2f;
    if (value <= 0x1.0p+2f)
    {
      value = 0x1.0p+2f;
    }
    upperBound = 0x1.0p+4f;
    if (upperBound <= value)
    {
      return upperBound;
    }
    return value;
  }
  if (input < 0x1.ep+4f)
  {
    value = (((0x1.ep+4f - input) * 0x1.8p+1f) / 0x1.ep+3f) + 0x1.0p+0f;
    if (value <= 0x1.0p+0f)
    {
      value = 0x1.0p+0f;
    }
    upperBound = 0x1.0p+2f;
    if (upperBound <= value)
    {
      return upperBound;
    }
    return value;
  }
  if (input < 0x1.68p+6f)
  {
    value = 0x1.0p+0f - (((input - 0x1.ep+4f) * 0x1.CCCCCCp-1f) / 0x1.ep+5f);
    if (value <= 0x1.999998p-4f)
    {
      value = 0x1.999998p-4f;
    }
    if (value >= 0x1.0p+0f)
    {
      return 0x1.0p+0f;
    }
    return value;
  }
  return 0x1.999998p-4f;
}
