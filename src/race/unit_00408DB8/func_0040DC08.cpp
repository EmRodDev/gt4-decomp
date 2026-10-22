/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef float f32;

struct Quat { f32 x, y, z, w; } __attribute__((aligned(16)));
union Vec {
    struct { f32 x, y, z, w; };
    u128 q;
    Vec() {}
    Vec(const Vec &v) { q = v.q; }
    f32 X() const { return x; }
    f32 Y() const { return y; }
    f32 Z() const { return z; }
};
struct Angle { f32 value; Angle(f32 f) : value(f) {} } __attribute__((aligned(16)));

struct Obj {
    virtual void v0();
    virtual f32 getX(f32 t);
    virtual f32 getY(f32 t);
    virtual f32 getZ(f32 t);
};

extern "C" Vec func_00421DF8(void *m, f32 x, f32 y, f32 z);
extern "C" void func_00487C68(Quat *q, f32 x, f32 y);

static inline void setRotation(Quat *q, const Angle &x, const Angle &y) { func_00487C68(q, x.value, y.value); }

extern "C" void func_0040DC08(Obj *o, f32 *ox, f32 *oy, f32 *oz, f32 p0, f32 p1) {
    *ox = o->getX(0.0f) + 0.0f;
    *oy = o->getY(0.0f) + 0.0f;
    *oz = o->getZ(0.0f) + -6.25f;
    Quat q;
    Angle ax(p1);
    Angle ay(p0);
    setRotation(&q, ax, ay);
    Vec r = func_00421DF8(&q, *ox, *oy, *oz);
    *ox = r.X();
    *oy = r.Y();
    *oz = r.Z();
}
