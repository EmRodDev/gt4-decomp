/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Vec3 { float x, y, z; };
struct Result { float u, v, height; };
struct Query {
    Result r;
    char pad[0x20];
    short a;
    short b;
};
struct Bytes4 { char b[4]; };
struct Hint { short a; short b; };
struct Section { short pad0; short count; short start; };
struct Vert { Vec3 a, b, c; float f24; };
struct Obj {
    char pad[0x14];
    float period;
    char pad18[0x24];
    u16 wrap;
    char pad3E[0x22];
    Vert *verts;
    short *index;
    char pad68[0x14];
    char *sections;
};
extern "C" int GT4Course__RunwayData__search(Obj *, void *, const Vec3 *) throw();
extern "C" int func_003E6610(Result *, const Vec3 *, void *, void *, void *, void *);
extern "C" float fabsf(float);
extern float D_006A39F8;

extern "C" float GT4Course__RunwayData__getVCoord(Obj *o, const Vec3 *pt, Hint *hint) {
    short hb = hint->b;
    if (hint->b < 0 || hb == 0) {
        Query q;
        short *pa = &q.a;
        *pa = -1;
        q.b = -1;
        if (GT4Course__RunwayData__search(o, &q, pt)) {
            *(Bytes4 *)hint = *(Bytes4 *)pa;
        } else {
            return 0.0f;
        }
    }
    Section *sec = (Section *)(o->sections + hint->b * 16);
    float best = D_006A39F8;
    float res = 0.0f;
    int end = sec->start + sec->count;
    int i = sec->start;
    Query q2;
    if (i < end) do {
        int idx = o->index[i];
        Vert *base = o->verts;
        Vert *s3 = base + idx;
        ++idx;
        Vert *s0 = base;
        if (idx != o->wrap) s0 += idx;
        if (func_003E6610(&q2.r, pt, s3, s0, &s3->b, &s0->b)) {
            float d = fabsf(q2.r.height);
            if (d < best) {
                float f2;
                float f3 = s3->f24;
                best = d;
                float f0 = s0->f24;
                f2 = o->period;
                if (f0 < f3) f0 += f2;
                res = f3 + (f0 - f3) * q2.r.u;
                if (f2 < res) res -= f2;
            }
        } else if (func_003E6610(&q2.r, pt, &s3->b, &s0->b, &s3->c, &s0->c)) {
            float d = fabsf(q2.r.height);
            if (d < best) {
                float f2;
                float f3 = s3->f24;
                best = d;
                float f0 = s0->f24;
                f2 = o->period;
                if (f0 < f3) f0 += f2;
                res = f3 + (f0 - f3) * q2.r.u;
                if (f2 < res) res -= f2;
            }
        }
    } while (++i < end);
    return res;
}
