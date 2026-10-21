/* Stores an angle at +0x104+0x468: the input in degrees is converted to radians and clamped to plus or minus the limit in the
 * car's config at +0x54 (inferred from the 0.01745 factor and the symmetric clamp), then func_003F7EA8 is called. */
struct Inner { char p0[0x54]; float f54; };
struct Obj { char p0[0x10]; Inner *f10; char p14[0x104 - 0x14]; };
struct Sub { char p0[0x468]; float f468; };
extern "C" void func_00343ED0(void);
extern "C" int func_003F7EA8(void *self);

extern "C" int func_003F8460(Obj *self, float fparg0) {
    float angle = fparg0 * 0.017453292f;
    float limit = self->f10->f54;
    float negLimit = -limit;
    Sub *state = (Sub *)((char *)self + 0x104);
    if (angle < negLimit) {
        angle = negLimit;
    } else if (limit < angle) {
        angle = limit;
    }
    func_00343ED0();
    state->f468 = angle;
    return func_003F7EA8(self);
}
