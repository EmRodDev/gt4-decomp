/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Second draw variant of the model-set renderer next to func_00452660 (same unit): it takes the model set at
 * inner+0x18 and the target from func_00450FE0, and draws only when both exist. With useWrap set, func_00452418
 * (0.005, 0.02) runs first and func_00452480 last (meaning of both unknown). The draw is begin, then func_004A60E0
 * with 1, 1, 1 and the extra float argument (read as alpha, inferred from it being the only caller-supplied value
 * next to three ones), then func_004A6100 with four zeros, render with mode 3 (func_00452660 uses 2) and end. The
 * order of the two colour setters is reversed against func_00452660. */
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

extern "C" void func_00452998(Self *self, s32 useWrap, float alpha)
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
        func_004A60E0(1.0f, 1.0f, 1.0f, alpha);
        func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
        ModelSet2___render(modelSet, 3, target);
        ModelSet2__end(modelSet);
        if (useWrap != 0) {
            func_00452480(self);
        }
    }
}
