/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {
    float x, y;
};

struct V3 {
    float x, y, z;
};

struct Point {
    V2 pos;                 /* 0x00 */
    V2 norm;                /* 0x08 */
    char pad10[0x20 - 0x10];
    int flags;              /* 0x20 */
    char pad24[0x44 - 0x24];
};

struct Edge {
    V2 a;                   /* 0x00 */
    V2 b;                   /* 0x08 */
    V2 n;                   /* 0x10 */
    float d;                /* 0x18 */
    int flags;              /* 0x1C */
    char pad20[0x2C - 0x20];
};

struct Obj {
    float invmass;          /* 0x000 */
    float invinertia;       /* 0x004 */
    Point points[8];        /* 0x008 */
    Edge edges[8];          /* 0x228 */
    char pad388[0x39C - 0x388];
    float angle;            /* 0x39C */
    char pad3a0[0x3C4 - 0x3A0];
    V3 vel;                 /* 0x3C4 */
    float omega;            /* 0x3D0 */
    char pad3d4[0x41C - 0x3D4];
    int vertex;             /* 0x41C */
};

static inline void rotate(V2 &out, const float *m, float x, float y)
{
    out.x = m[0] * x + m[1] * y;
    out.y = m[2] * x + m[3] * y;
}

static inline void unrotate(V2 &out, const float *m, const V2 &v)
{
    out.x = m[0] * v.x + m[2] * v.y;
    out.y = m[1] * v.x + m[3] * v.y;
}

static inline float cross(const V2 &a, const V2 &b)
{
    return a.x * b.y - a.y * b.x;
}

extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void func_0045E288(Obj *, V2 *, float *, V2 *);
extern "C" void func_0045E898(Obj *, V2 *, V2 *, V3 *);
extern "C" void func_0045E450(Obj *, float *);

extern "C" void func_0045E028(Obj *o)
{
    V2 impulse;
    float m[4];
    V2 vel;
    V2 arm;
    V3 extra;
    V2 local;
    m[0] = func_0057D1F0(o->angle);
    float s = func_0057D2B8(o->angle);
    m[2] = s;
    m[3] = m[0];
    m[1] = -s;
    Edge *e = &o->edges[o->vertex];
    rotate(arm, m, e->a.y, -e->a.x);
    vel.x = o->vel.x - o->omega * arm.x;
    vel.y = o->vel.y - o->omega * arm.y;
    func_0045E288(o, &impulse, m, &vel);
    func_0045E898(o, &impulse, &vel, &extra);
    unrotate(local, m, impulse);
    impulse.x += extra.x;
    impulse.y += extra.y;
    func_0045E450(o, m);
    o->points[o->vertex].flags |= 1;
    float k = o->invmass;
    o->vel.x += impulse.x * k;
    o->vel.y += impulse.y * k;
    int below = o->vel.z < 0.0f;
    o->vel.z += extra.z * k;
    if (below ? o->vel.z > 0.0f : o->vel.z < 0.0f)
        o->vel.z = 0.0f;
    e = &o->edges[o->vertex];
    o->omega += cross(e->a, local) * o->invinertia;
}
