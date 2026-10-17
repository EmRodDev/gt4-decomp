/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {
    float x, y;
};

struct Point {
    V2 pos;                 /* 0x00 */
    V2 norm;                /* 0x08 */
    char pad10[0x20 - 0x10];
    int flags;              /* 0x20 */
    char pad24[0x2C - 0x24];
    int hit;                /* 0x2C */
    char pad30[0x44 - 0x30];
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
    float radius;           /* 0x388 */
    char pad38c[0x3EC - 0x38C];
    int f3ec;               /* 0x3EC */
    char pad3f0[0x430 - 0x3F0];
    int active;             /* 0x430 */
    char pad434[0x44C - 0x434];
    int arg1;               /* 0x44C */
    int arg3;               /* 0x450 */
    char pad454[0x488 - 0x454];
    int arg2;               /* 0x488 */
    float length;           /* 0x48C */
    float rear;             /* 0x490 */
    float half;             /* 0x494 */
    float mass;             /* 0x498 */
    float inertia;          /* 0x49C */
    float front;            /* 0x4A0 */
    float side;             /* 0x4A4 */
    char pad4a8[0x4E0 - 0x4A8];
    int f4e0;               /* 0x4E0 */
    int f4e4;               /* 0x4E4 */
    int f4e8;               /* 0x4E8 */
    int f4ec;               /* 0x4EC */
};

static inline float fsqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" float func_0045C0D8(void) throw();

extern "C" void func_0045C170(Obj *o, int arg1, int arg2, int arg3, float length, float rear,
                              float width, float front, float side, float mass, float inertia)
{
    o->arg1 = arg1;
    o->length = length;
    o->rear = rear;
    o->front = front;
    o->side = side;
    o->half = width * 0.5f;
    o->mass = mass;
    float scale = func_0045C0D8();
    o->arg2 = arg2;
    o->arg3 = arg3;
    inertia *= scale;
    float h = o->half, l = o->length, r = o->rear, c = o->front, d = o->side;
    o->invmass = 1.0f / o->mass;
    o->invinertia = 1.0f / inertia;
    o->points[0].pos.x = h;     o->points[0].pos.y = l - c;
    o->points[1].pos.x = h - c; o->points[1].pos.y = l;
    o->points[2].pos.x = c - h; o->points[2].pos.y = l;
    o->points[3].pos.x = -h;    o->points[3].pos.y = l - c;
    o->points[4].pos.x = -h;    o->points[4].pos.y = d - r;
    o->points[5].pos.x = d - h; o->points[5].pos.y = -r;
    o->points[6].pos.x = h - d; o->points[6].pos.y = -r;
    o->points[7].pos.x = h;     o->points[7].pos.y = d - r;
    o->inertia = inertia;
    float maxsq = 0.0f;
    for (int i = 0; i < 8; i++) {
        V2 *p = &o->points[i].pos;
        float x = p->x, y = p->y;
        float len = fsqrt(x * x + y * y);
        o->points[i].norm.x = x / len;
        o->points[i].norm.y = y / len;
        o->points[i].flags = 0;
        o->points[i].hit = 0;
        o->edges[i].flags = 0;
        V2 *q = &o->points[(i + 1) & 7].pos;
        o->edges[i].a = *p;
        o->edges[i].b = *q;
        x = q->y - p->y;
        y = -(q->x - p->x);
        len = fsqrt(x * x + y * y);
        o->edges[i].n.x = x / len;
        o->edges[i].n.y = y / len;
        o->edges[i].d = -o->edges[i].n.x * p->x - o->edges[i].n.y * p->y;
        float sq = p->x * p->x + p->y * p->y;
        if (maxsq < sq) maxsq = sq;
    }
    o->radius = fsqrt(maxsq);
    o->active = 1;
    o->f3ec = 0;
    o->f4e0 = 0;
    o->f4e4 = 0;
    o->f4e8 = 0;
    o->f4ec = 0;
}
