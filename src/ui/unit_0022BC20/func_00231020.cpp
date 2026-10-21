/* Translates a 2D position by (dx, dy): reads the current pair with func_00230EC0, adds the offsets and writes the result back with func_00230ED8.
 * (Getter/setter roles inferred from the out-parameters and the write-back.) */
#include "types.h"

extern "C" void func_00230EC0(void *obj, f32 *arg1, f32 *arg2);
extern "C" void func_00230ED8(void *obj, f32 dx, f32 dy);

extern "C" void func_00231020(void *obj, f32 dx, f32 dy) {
    f32 x;
    f32 y;
    f32 newX;
    f32 newY;

    func_00230EC0(obj, &x, &y);
    newX = x + dx;
    newY = y + dy;
    x = newX;
    y = newY;
    func_00230ED8(obj, newX, newY);
}
