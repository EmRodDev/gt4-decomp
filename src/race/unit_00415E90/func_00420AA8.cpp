/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &v) { *(u128 *)this = *(const u128 *)&v; }
    V &operator=(const V &v) { *(u128 *)this = *(const u128 *)&v; return *this; }
    float len2() const { return x * x + y * y + z * z; }
    V operator*(float t) const { V r(*this); r *= t; return r; }
    V &operator*=(float t) { x *= t; y *= t; z *= t; return *this; }
    V normalized() const;
    V operator-(const V &v) const {
        V r(*this);
        float &rx = r.x, &ry = r.y, &rz = r.z;
        const float &vx = v.x, &vy = v.y, &vz = v.z;
        rx -= vx; ry -= vy; rz -= vz;
        return r;
    }
} __attribute__((aligned(16)));
static inline float rsqrtf_(float a, float b) { float r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float sqrtf_(float a) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(a)); return r; }
inline V V::normalized() const { V r(*this); r *= rsqrtf_(1.0f, r.len2()); return r; }
struct Q : V { Q() {} };
struct Angle { float x; Angle(float a) : x(a) {} Angle(const Angle &a) : x(a.x) {} };
struct Entry { short delta, index; void (*fn)(V *, void *); };
struct Joint { V pos; Q rot; Entry *vt; };
struct Frame { V pos; Q rot; };
extern "C" int func_00420190(float *, float *, float *, float *, float, float, float, float) throw();
extern "C" void func_0048D4C0(V *, const V *, const V *);
extern "C" void func_00487830(Q *, const V *, float);
extern "C" void func_004878C0(Q *, const V *, float);
extern "C" V Numerical_Math__Quaternion__rotate(Q *, const V &);
extern "C" void func_00488B98(Q *, void *, void *, const V *, const V *);
static inline V cross(const V &a, const V &b) { V r; func_0048D4C0(&r, &a, &b); return r; }
static inline void setRot(Q *q, const V &axis, const Angle &a) { func_00487830(q, &axis, a.x); }
static inline void addRot(Q *q, const V &axis, const Angle &a) { func_004878C0(q, &axis, a.x); }
static inline V getEnd(Joint *j) { Entry *e = j->vt + 1; return ((V (*)(void *))e->fn)((char *)j + e->delta); }
extern "C" int func_00420AA8(int *flag, Joint *j1, Joint *j2, Frame *out, const V *pole, const V *base,
                             const V *target, void *p0, float l1, float l2, float l3, void *p1) {
    V d = *target - *base;
    float angElbow, angWrist, angUnused, angShoulder;
    float len = sqrtf_(d.len2());
    *flag = func_00420190(&angElbow, &angWrist, &angUnused, &angShoulder, l1, l2, l3, len);
    V dir = d * (1.0f / len);
    V axis = cross(dir, *pole).normalized();
    Q q;
    setRot(&q, axis, Angle(0x1.921fb4p+0f));
    V up = Numerical_Math__Quaternion__rotate(&q, dir);
    func_00488B98(&q, p0, p1, &dir, &up);
    addRot(&q, axis, Angle(angShoulder));
    j1->pos = *base;
    j1->rot = q;
    V elbow = getEnd(j1);
    axis = cross((elbow - *base).normalized(), dir);
    axis = axis.normalized();
    angElbow = 0x1.921fb4p+1f - angElbow;
    addRot(&q, axis, Angle(angElbow));
    j2->pos = elbow;
    j2->rot = q;
    V wrist = getEnd(j2);
    angWrist = 0x1.921fb4p+1f - angWrist;
    addRot(&q, axis, Angle(angWrist));
    out->pos = wrist;
    out->rot = q;
    return 1;
}
