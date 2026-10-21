/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Advances the elapsed-time field at +0x30 by deltaTime and returns 1 while the object is still active (inferred): either the flag at
 * +0x4C is set or the elapsed time is still below (f5C - f54 - func_00490640()). Otherwise returns 0. */
typedef int s32;
typedef float f32;

struct S00490640;
extern "C" f32 func_00490640(S00490640 *self);

struct S00490660 {
    char pad0[0x30];
    f32 f30;
    char pad1[0x18];
    s32 i4C;
    char pad2[0x4];
    f32 f54;
    char pad3[0x4];
    f32 f5C;
};

extern "C" s32 func_00490660(S00490660 *self, f32 deltaTime) {
    self->f30 = self->f30 + deltaTime;
    if (self->i4C != 0) {
        return 1;
    }
    f32 tail = func_00490640((S00490640 *)self);
    f32 limit = (self->f5C - self->f54) - tail;
    if (self->f30 < limit) {
        return 1;
    }
    return 0;
}
