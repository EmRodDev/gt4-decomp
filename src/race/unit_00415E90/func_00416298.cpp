/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Angle { float x; Angle(float a) : x(a) {} Angle(const Angle &a) : x(a.x) {} };
struct Obj { int mode; char pad[0xC]; float a[4]; float b[4]; float c[4]; float d, e; };
extern "C" void func_00415E90(Obj *, float *, Angle, Angle, int, float) throw();
extern "C" void func_00416040(Obj *, float *, float *, Angle, int) throw();
extern "C" void func_00416278(Obj *, float *, float *) throw();
static inline int limit(int mode, const Angle &v) {
    if (mode == 0) {
        if (v.x < -0x1.921fb4p+0f) return 1;
    } else {
        if (v.x > 0x1.921fb4p+0f) return 1;
    }
    return 0;
}
extern "C" int func_00416298(Obj *o, float *a, float *b, int k, float t) {
    float va = *a;
    float vb = *b;
    float blend = va * (1.0f - t) + vb * t;
    func_00415E90(o, o->a, Angle(va), Angle(vb), k, t);
    func_00416040(o, o->b, o->c, Angle(blend), k);
    func_00416278(o, &o->d, &o->e);
    return limit(o->mode, Angle(blend));
}
