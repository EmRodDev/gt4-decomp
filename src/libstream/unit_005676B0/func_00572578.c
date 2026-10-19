#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void func_00572470(s32 *arg0);

s32 func_00572578(s32 *arg0) {
    s32 temp_s0;

    temp_s0 = *arg0;
    func_00572470(arg0);
    return temp_s0;
}
