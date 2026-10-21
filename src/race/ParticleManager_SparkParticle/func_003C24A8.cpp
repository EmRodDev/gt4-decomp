struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Obj;
struct Tuning {
    char pad[0x10];
    float f10, f14, f18, f1C, f20, f24, f28, f2C, f30;
};
extern Tuning particle_param_;
extern "C" void func_003C1358(Obj *o, Vec3 *p, Vec3 *v, Vec4 *c, int kind, float mass, float factor, float value) throw();
extern "C" Obj *SparkParticle__structor_0(Obj *m);
extern "C" float pglmRandom(void);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();

static inline float root(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline Obj *next_particle(Obj *mgr) { return SparkParticle__structor_0(mgr); }
extern "C" void func_003C24A8(Obj *mgr, Vec3 *pos, Vec3 *vel, Vec4 *color, int count) {
    Vec3 v;
    int i = 0;
    float len = root(vel->x * vel->x + vel->z * vel->z);
    if (count > 0) {
        do {
            void *work = next_particle(mgr);
            Obj *p = (Obj *)work;
            if (!p)
                break;
            i++;
            work = &particle_param_;
            Tuning *t = (Tuning *)work;
            float a = (pglmRandom() - 0.5f) * 0x1.1df468p-6f * t->f10;
            float sp = pglmRandom() * (t->f18 - t->f14) + t->f14;
            float s = func_0057D2B8(a) * sp;
            float c = func_0057D1F0(a) * sp;
            v.x = c * vel->x - s * vel->z;
            float r3 = pglmRandom();
            float r4 = pglmRandom();
            float q = (r3 + r4) * 0.5f;
            v.y = vel->y + (q - 0.5f) * len * t->f1C;
            v.z = s * vel->x + c * vel->z;
            float sz = pglmRandom() * (t->f24 - t->f20) + t->f20;
            float m = sz * sz * sz * t->f28;
            float w = pglmRandom() * (t->f30 - t->f2C) + t->f2C;
            func_003C1358(p, pos, &v, color, 0xFF229EFF, m, sz, w);
        } while (i < count);
    }
}
