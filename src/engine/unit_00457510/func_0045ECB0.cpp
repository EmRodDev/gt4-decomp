/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {
    float x, y;
    V2() {}
};

struct Item {
    char pad[0x20];
    int flags;              /* 0x20 */
    char pad24[0x44 - 0x24];
};

struct Edge {
    float x0, y0;           /* 0x00 */
    float x1, y1;           /* 0x08 */
    float nx, ny, k;        /* 0x10 */
    char pad[0x2C - 0x1C];
};

struct Obj {
    char pad0[8];
    Item items[8];          /* 0x008 */
    Edge edges[8];          /* 0x228 */
    char pad388[4];
    float t0;               /* 0x38C */
    V2 pos;                 /* 0x390 */
    float z;                /* 0x398 */
    float angle;            /* 0x39C */
    float t1;               /* 0x3A0 */
    V2 npos;                /* 0x3A4 */
    float nz;               /* 0x3AC */
    float nangle;           /* 0x3B0 */
    V2 delta;               /* 0x3B4 */
    char pad3bc[0x18];
    V2 low;                 /* 0x3D4 */
    V2 high;                /* 0x3DC */
    V2 size;                /* 0x3E4 */
    int pad3ec;
    int hit;                /* 0x3F0 */
    int hit2;               /* 0x3F4 */
    int pad3f8;
    float time;             /* 0x3FC */
    char pad400[8];
    int edge;               /* 0x408 */
    int other;              /* 0x40C */
    int vertex;             /* 0x410 */
    V2 point;               /* 0x414 */
    char pad41c[0x14];
    int active;             /* 0x430 */
    int front;              /* 0x434 */
    int back;               /* 0x438 */
    int pad43c;
    int contact;            /* 0x440 */
    char pad444[0x64];
    Obj *objects;           /* 0x4A8 */
    char pad4ac[0x18];
    float radius[8];        /* 0x4C4 */
    char pad4e4[0xC];
};

extern "C" float func_0057D2B8(float) throw();
extern "C" float func_0057D1F0(float);

extern "C" int func_0045ECB0(Obj *self, int index)
{
    if (!self->active) return 0;
    Obj *other = &self->objects[index];
    if (!other->active) return 0;
    if (__builtin_fabsf(self->z - other->z) > 4.0f) return 0;
    float dx = other->high.x - self->low.x, dy = other->high.y - self->low.y;
    if (dx < 0.0f) return 0;
    if (dy < 0.0f) return 0;
    if (other->size.x + self->size.x < dx) return 0;
    if (other->size.y + self->size.y < dy) return 0;

    V2 a, b, c, d, e, f, hit, p, q, u, v, w;
    b.x = other->delta.x - self->delta.x;
    b.y = other->delta.y - self->delta.y;
    a.x = other->pos.x - self->pos.x;
    a.y = other->pos.y - self->pos.y;
    float len = b.x * b.x + b.y * b.y;
    float proj = -a.x * b.x - a.y * b.y;
    if (proj <= 0.0f) c = a;
    else if (len <= proj) { c.x = a.x + b.x; c.y = a.y + b.y; }
    else { float t = proj / len; c.x = a.x + b.x * t; c.y = a.y + b.y * t; }
    if (self->radius[index] < c.x * c.x + c.y * c.y) return 0;

    d.x = other->npos.x - self->npos.x;
    d.y = other->npos.y - self->npos.y;
    float angle = other->angle - self->angle;
    float nangle = other->nangle - self->nangle;
    float s0 = func_0057D2B8(-self->angle);
    float c0 = func_0057D1F0(-self->angle);
    float s1 = func_0057D2B8(-self->nangle);
    float c1 = func_0057D1F0(-self->nangle);
    e.x = c0 * a.x - s0 * a.y;
    f.x = c1 * d.x - s1 * d.y;
    e.y = s0 * a.x + c0 * a.y;
    f.y = s1 * d.x + c1 * d.y;
    float sa = func_0057D2B8(angle), ca = func_0057D1F0(angle);
    float sb = func_0057D2B8(nangle), cb = func_0057D1F0(nangle);
    float best = 2.0f;
    int vertex = -1;
    int edge = -1;
    int i, j;
    i = 0;
    do {
        if (other->items[i].flags != 0) continue;
        Edge *pt = &other->edges[i];
        p.x = ca * pt->x0 - sa * pt->y0 + e.x;
        p.y = sa * pt->x0 + ca * pt->y0 + e.y;
        q.x = cb * pt->x0 - sb * pt->y0 + f.x;
        q.y = sb * pt->x0 + cb * pt->y0 + f.y;
        for (j = 0; j < 8; j++) {
            float start = p.x * self->edges[j].nx + p.y * self->edges[j].ny + self->edges[j].k;
            float end = q.x * self->edges[j].nx + q.y * self->edges[j].ny + self->edges[j].k;
            if (end > 0.0f || start < 0.0f) continue;
            u.x = self->edges[j].x0 - p.x;
            u.y = self->edges[j].y0 - p.y;
            v.x = self->edges[j].x1 - p.x;
            v.y = self->edges[j].y1 - p.y;
            w.x = q.x - p.x;
            w.y = q.y - p.y;
            float cross1 = u.x * w.y - u.y * w.x, cross2 = v.x * w.y - v.y * w.x;
            if (cross1 < 0.0f && cross2 < 0.0f) continue;
            if (cross1 > 0.0f && cross2 > 0.0f) continue;
            float den = start - end;
            float t = den != 0.0f ? start / den : 1.0f;
            float time = (self->t1 - self->t0) * t + self->t0;
            bool outside = time < 0.0f || time > 1.0f;
            if (outside) continue;
            if (time < best) {
                best = time;
                vertex = i;
                edge = j;
                hit.x = p.x + w.x * t;
                hit.y = p.y + w.y * t;
            }
        }
    } while (++i < 8);
    if (vertex < 0) return 0;
    if ((self->hit || self->hit2) && self->time < best) return 0;
    self->edge = edge;
    self->time = best;
    self->other = index;
    self->vertex = vertex;
    self->hit = 1;
    self->point = hit;
    self->contact = 1;
    if (self->edge < 3) self->front = 1;
    else if ((unsigned)(self->edge - 4) < 3) self->back = 1;
    other->contact = 1;
    if (self->vertex < 4) other->front = 1;
    else other->back = 1;
    return 1;
}
