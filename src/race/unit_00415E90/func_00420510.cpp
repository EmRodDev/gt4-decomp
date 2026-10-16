/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &o) { *(u128 *)this = *(const u128 *)&o; }
    V &operator=(const V &o) { *(u128 *)this = *(const u128 *)&o; return *this; }
    V &operator-=(const V &o) { float &tx = x, &ty = y, &tz = z; tx -= o.x; ty -= o.y; tz -= o.z; return *this; }
    V &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
} __attribute__((aligned(16)));
static inline V operator-(const V &a, const V &b) { V r(a); r -= b; return r; }
static inline V operator*(const V &a, float s) { V r(a); r *= s; return r; }
struct Q : V { Q() {} };
struct Angle { float x; Angle(float a) : x(a) {} Angle(const Angle &a) : x(a.x) {} };
struct Entry { short delta, index; void (*fn)(V *, void *); };
struct Joint { V pos; Q rot; Entry *vt; };
struct Frame { V pos; Q rot; };
extern "C" float func_0059D2A0(float);
extern "C" void func_0048D4C0(V *, const V *, const V *);
extern "C" void func_00487830(Q *, const V *, float);
extern "C" void func_004878C0(Q *, const V *, float);
extern "C" V Numerical_Math__Quaternion__rotate(Q *, const V &);
extern "C" void func_00488B98(Q *, void *, void *, const V *, const V *);
static inline float sqrtf_(float a) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(a)); return r; }
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float rsqrtf_(float a, float b) { float r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fabsf_(float a) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }
static inline float clampf(const float &v, float lo, float hi) { return minf(maxf(v, lo), hi); }
static inline float acosf_(float c) { return 0x1.921fb4p+0f - func_0059D2A0(clampf(c, -1.0f, 1.0f)); }
static inline float dot(const V &a, const V &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
static inline V normalize(const V &v) { V r(v); r *= rsqrtf_(1.0f, dot(r, r)); return r; }
static inline V cross(const V &a, const V &b) { V r; func_0048D4C0(&r, &a, &b); return r; }
static inline void setRot(Q *q, const V &axis, const Angle &a) { func_00487830(q, &axis, a.x); }
static inline void addRot(Q *q, const V &axis, const Angle &a) { func_004878C0(q, &axis, a.x); }
static inline V getEnd(Joint *j) { Entry *e = j->vt + 1; return ((V (*)(void *))e->fn)((char *)j + e->delta); }
extern "C" int func_00420510(int *flag, Joint *j, Frame *out, const V *pole, const V *base, const V *target,
                             void *p0, void *p1, float l1, float l2, float tol, const float *minAngle) {
    int result = 1;
    float adiff = fabsf_(l1 - l2);
    float sum = l1 + l2;
    V d = *target - *base;
    float len = sqrtf_(d.x * d.x + d.y * d.y + d.z * d.z);
    if (len < 0x1.4f8b58p-17f) len = 0x1.4f8b58p-17f;
    if (sum + tol <= len) {
        *flag = 0;
    } else if (len < adiff) {
        float inv = 1.0f / len;
        d = d * adiff * inv;
        len = adiff;
        *flag = 0;
    } else if (len <= sum - tol) {
        *flag = result;
    } else {
        float inv = 1.0f / len;
        float nl = (sum - tol) + ((len - sum) + tol) * 0.5f;
        d = d * nl * inv;
        len = nl;
        *flag = result;
    }
    float d2 = len * len;
    float a2 = l1 * l1;
    float b2 = l2 * l2;
    float angA = acosf_((d2 + a2 - b2) / ((len + len) * l1));
    float angB = acosf_((a2 + b2 - d2) / ((l1 + l1) * l2));
    if (angB < *minAngle) angB = *minAngle;
    V dir = d * (1.0f / len);
    V axis = normalize(cross(dir, *pole));
    Q q;
    setRot(&q, axis, Angle(0x1.921fb4p+0f));
    V up = Numerical_Math__Quaternion__rotate(&q, dir);
    func_00488B98(&q, p0, p1, &dir, &up);
    addRot(&q, axis, Angle(angA));
    j->pos = *base;
    j->rot = q;
    V elbow = getEnd(j);
    axis = cross(elbow - *base, dir);
    axis = normalize(axis);
    angB = 0x1.921fb4p+1f - angB;
    addRot(&q, axis, Angle(angB));
    out->pos = elbow;
    out->rot = q;
    return result;
}
