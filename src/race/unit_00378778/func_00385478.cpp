/* Steering-like output (inferred from the clamp to +-pi/2 radians): mode 0 negates value 8 from func_0035A540, scales it by 0.4 and
 * clamps it; other modes multiply the negated value by the motorist dynamic parameter from DRIVERSUPPORT when set
 * (func_0044FAB0), else by 0.4. Companion of func_00385548, which uses value 9. */
#include "types.h"

struct Obj;
struct func_0035A540_Obj;

extern "C" f32 func_0035A540(func_0035A540_Obj *self, int k);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 func_0044FAB0(Obj *self);

extern "C" f32 func_00385478(Obj *self, s32 mode)
{
  f32 gain;
  f32 upperLimit;
  f32 lowerLimit;
  f32 rawValue;
  f32 negated;
  f32 clamped;

  if (mode == 0)
  {
    rawValue = func_0035A540((func_0035A540_Obj *) self, 8);
    upperLimit = 0x1.921FB4p+0f;
    negated = -rawValue;
    clamped = negated * 0x1.999998p-2f;
    lowerLimit = -0x1.921FB4p+0f;
    if (clamped < lowerLimit)
    {
      clamped = lowerLimit;
    }
    else if (upperLimit < clamped)
    {
      clamped = upperLimit;
    }
    return clamped;
  }

  gain = 0x1.999998p-2f;
  if (DRIVERSUPPORT_NAME__GetMotoristDynamicParameter() != 0)
  {
    gain = func_0044FAB0((Obj *) DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
  }
  return -func_0035A540((func_0035A540_Obj *) self, 8) * gain;
}
