/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Random target plus damped spring (stiffness 60, damping 10, step 1/60): every third call a new random target in 0..256 is chosen
 * when a random roll beats a threshold derived from 'chance'; 'trigger' above 1.0 forces the target to 256. The value m0 then
 * follows the target. Purpose unknown (probably a flicker or shake; not proven). */
typedef int s32;
typedef float f32;

struct Obj { f32 m0; f32 m4; f32 m8; s32 mC; };

extern "C" float func_00578598(void *);

extern "C" void func_00384C48(Obj *self, void *arg1, f32 chance, f32 trigger) {
    f32 roll = func_00578598(arg1);
    s32 counter = self->mC;
    if (counter < 2) {
        self->mC = counter + 1;
    } else {
        self->mC = 0;
        chance = chance * -0x1.428f6p-3f + 0x1.fc962ep-1f;
        if (chance < roll)
            self->m4 = func_00578598(arg1) * 256.0f;
    }
    if (trigger > 1.0f)
        self->m4 = 256.0f;
    f32 position = self->m0;
    self->m8 = self->m8 + ((((self->m4 - position) * 60.0f) + (self->m8 * -10.0f)) / 60.0f);
    self->m0 = position + self->m8 / 60.0f;
}
