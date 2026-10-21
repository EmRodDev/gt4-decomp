/* Returns a signed gain applied to value 9 of func_0035A540 (negated). mode 0: gain 0.4, and 0 when the angle from func_00385478
 * is outside +-pi/2; other modes use the motorist dynamic parameter from DRIVERSUPPORT when set (func_0044FAB0), else 0.4.
 * Meaning of the modes is unknown. */
#include "types.h"

struct Obj;
struct func_0035A540_Obj;

extern "C" f32 func_0035A540(func_0035A540_Obj *self, int k);
extern "C" f32 func_00385478(Obj *self, s32 mode);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 func_0044FAB0(Obj *self);

extern "C" f32 func_00385548(Obj *self, s32 mode)
{
  f32 gain;
  f32 scaled;
  f32 angle;
  f32 upperLimit;
  f32 lowerLimit;

  if (mode == 0)
  {
    gain = -func_0035A540((func_0035A540_Obj *) self, 9) * 0x1.999998p-2f;
    angle = func_00385478(self, 0);
    upperLimit = 0x1.921FB4p+0f;
    lowerLimit = -0x1.921FB4p+0f;
    if (angle < lowerLimit)
    {
      gain = 0.0f;
    }
    else if (upperLimit < angle)
    {
      gain = 0.0f;
    }
    return gain;
  }

  gain = 0x1.999998p-2f;
  if (DRIVERSUPPORT_NAME__GetMotoristDynamicParameter() != 0)
  {
    gain = func_0044FAB0((Obj *) DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
  }
  scaled = -func_0035A540((func_0035A540_Obj *) self, 9);
  return scaled * gain;
}
