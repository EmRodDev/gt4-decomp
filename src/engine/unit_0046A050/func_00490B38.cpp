/* Script engine: when f68 is zero, clears the result field f30, runs func_004940E8 with D_00492ED0 (restoring f44 afterwards), clears
 * f78 and returns f30 read back as a float (the callee leaves a float there; inferred). Returns 0.0 otherwise. */
#include "types.h"
extern "C" void func_004940E8(void *a0, void *a1, s32 a2, s32 a3);
extern char D_00492ED0[];
struct Obj {
    char p0[0x30];
    s32 f30;
    char p34[0x44 - 0x34];
    s32 f44;
    char p48[0x68 - 0x48];
    s32 f68;
    char p6C[0x78 - 0x6C];
    s32 f78;
};
extern "C" f32 func_00490B38(struct Obj *self, s32 callArg) {
    f32 result = 0.0f;
    if (self->f68 == 0) {
        s32 savedF44 = self->f44;
        self->f30 = 0;
        func_004940E8(self, D_00492ED0, 1, callArg);
        self->f44 = savedF44;
        self->f78 = 0;
        result = *(f32 *)&self->f30;
    }
    return result;
}
