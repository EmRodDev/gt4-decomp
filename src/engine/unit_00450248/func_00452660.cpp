/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Renders the model set held by this object (the pointer at inner->0x18) once, with a fixed colour state. Both the
 * model set and the target from func_00450FE0 must exist. Around the draw, when useWrap is set, func_00452418 is
 * called first with 0.005 and 0.02 and func_00452480 afterwards (what they set up and undo is unknown). The draw
 * itself is begin, two colour setters (func_004A6100 gets the first three floats of D_008465B0 and 0,
 * func_004A60E0 gets 1, 1, 1 and the fourth float; reading the fourth as alpha is inferred), render with mode 2,
 * then end. The hex float literals are exact copies of the matched values. */
typedef int s32;

struct Inner {
    char pad0[0x18];
    void *f18;
};

struct Self {
    Inner *inner;
};

extern "C" void *func_00450FE0(Self *) throw();
extern "C" void func_00452418(float, float, Self *) throw();
extern "C" void func_00452480(Self *) throw();
extern "C" void ModelSet2__begin(void *, void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2___render(void *, int, void *);
extern "C" void func_004A60E0(float, float, float, float);
extern "C" void func_004A6100(float, float, float, float);

extern float D_008465B0[4];

extern "C" void func_00452660(Self *self, s32 useWrap)
{
    void *modelSet = 0;
    if (self->inner != 0) {
        modelSet = self->inner->f18;
    }
    void *target = func_00450FE0(self);
    if (modelSet != 0 && target != 0) {
        if (useWrap != 0) {
            func_00452418(0x1.47ae14p-8f, 0x1.47ae14p-6f, self);
        }
        ModelSet2__begin(modelSet, target);
        float *colors = D_008465B0;
        func_004A6100(colors[0], colors[1], colors[2], 0.0f);
        func_004A60E0(1.0f, 1.0f, 1.0f, colors[3]);
        ModelSet2___render(modelSet, 2, target);
        ModelSet2__end(modelSet);
        if (useWrap != 0) {
            func_00452480(self);
        }
    }
}
