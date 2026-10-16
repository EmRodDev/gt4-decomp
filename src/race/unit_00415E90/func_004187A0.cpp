/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
union Vec { struct { float x,y,z,w; }; u128 q; Vec() {} Vec(const Vec &v) { q = v.q; } };
struct Obj { Vec v; float m[16]; };
extern "C" void func_00489300(Vec *, const float *, const Vec *);
extern "C" Vec func_004187A0(Obj *self, const Vec *v) {
    Vec t;
    func_00489300(&t, self->m, v);
    t.x += self->v.x;
    t.y += self->v.y;
    t.z += self->v.z;
    return t;
}
