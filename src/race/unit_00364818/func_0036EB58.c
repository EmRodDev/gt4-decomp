#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0036EAD8(f32 a);

f32 func_0036EB58(f32 a) {
    f32 var_f1;

    var_f1 = func_0036EAD8(a);
    if (var_f1 > 180.0f) {
        var_f1 -= 360.0f;
    }
    return var_f1;
}
