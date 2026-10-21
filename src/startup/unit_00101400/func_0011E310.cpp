/* Linear interpolation / extrapolation: the straight line through the points (x0, y0) and (x1, y1) evaluated at x
 * (checked algebraically: y = ((y1 - y0) * x + (y0 * x1 - y1 * x0)) / (x1 - x0)). The division is done once as a reciprocal multiply,
 * which is how the compiler schedules it. */
#include "types.h"

extern "C" f32 func_0011E310(f32 x0, f32 x1, f32 y0, f32 y1, f32 x) {
    f32 inv = 1.0f / (x1 - x0);
    return (((y1 - y0) * x) + ((y0 * x1) - (y1 * x0))) * inv;
}
