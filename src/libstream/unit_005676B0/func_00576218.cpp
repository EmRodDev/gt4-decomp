#include "types.h"

extern "C" int write(s32 a0, s32 a1, s32 a2);

struct Obj {
    s32 m0;
    char buf[0x108 - 4];
    s32 m108;
    s32 m10C;
};

extern "C" s32 func_00576218(Obj *self, s32 v) {
    char *p = (char *)self + 4;
    s32 *cursor = &self->m10C;
    s32 *end = &self->m10C;
    s32 n = *cursor;
    self->m108 = v;
    *(char *)(p + n) = v;
    ++n;
    *cursor = n;
    if (n == 0xFF) {
        write(1, (s32)p, 0xFF);
        *cursor = 0;
    }
    return 0;
}
