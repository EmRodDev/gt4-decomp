/* compiler: ee-gcc2.96-no-strict-aliasing */
/* With func_005B72A8 / func_005B72F8 around it (they bracket critical sections in this library),
   polls func_00554CA0(o) until it returns non-zero or func_005549A0(o, &o->queue) reports false;
   returns the last func_00554CA0 result. The loop is entered at its test (`b` to the
   func_00554CA0 call): only a do-while entered by goto reproduces that; while/for/do forms
   rotate it differently. The andi is an explicit `& 1` on its bool result. */
#include "types.h"

struct func_00554CF0_a0 {
    char pad0[0xC];
    s32 queue;
};

extern "C" s32 func_005B72A8(void);
extern "C" s32 func_005B72F8(void);
extern "C" bool func_005549A0(struct func_00554CF0_a0 *o, s32 *queue);
extern "C" s32 func_00554CA0(struct func_00554CF0_a0 *o);

extern "C" s32 func_00554CF0(struct func_00554CF0_a0 *o) {
    s32 r;
    func_005B72A8();
    goto test;
    do {
        if (!(func_005549A0(o, &o->queue) & 1))
            break;
    test:
        r = func_00554CA0(o);
    } while (r == 0);
    func_005B72F8();
    return r;
}
