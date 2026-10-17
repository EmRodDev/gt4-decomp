/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {
    float x, y;
};

struct Point {
    V2 pos;                 /* 0x00 */
    V2 norm;                /* 0x08 */
    V2 world;               /* 0x10 */
    char pad18[0x44 - 0x18];
};

struct Obj {
    char pad0[8];
    Point points[8];        /* 0x008 */
    char pad228[0x390 - 0x228];
    V2 pos;                 /* 0x390 */
    float z;                /* 0x398 */
    char pad39c[0x430 - 0x39C];
    int active;             /* 0x430 */
    char pad434[0x4A8 - 0x434];
    Obj *objects;           /* 0x4A8 */
    char pad4ac[0x4C4 - 0x4AC];
    float radius[8];        /* 0x4C4 */
    char pad4e4[0x4F0 - 0x4E4];
};

extern "C" void func_0045CBB8(Obj *, float, float) throw();

extern "C" void func_0045FAD0(Obj *self, int index)
{
    if (!self->active) return;
    Obj *other = &self->objects[index];
    if (!other->active) return;
    if (__builtin_fabsf(self->z - other->z) > 4.0f) return;
    float dx = other->pos.x - self->pos.x, dy = other->pos.y - self->pos.y;
    if (self->radius[index] < dx * dx + dy * dy) return;
    float by = 0.0f, bx = 0.0f, best = 0.0f;
    Point *p = other->points;
    for (int i = 0; i < 8; i++, p++) {
        float px = p->world.x, py = p->world.y;
        float ny = 0.0f, nx = 0.0f, depth = 0.0f;
        int hit = 0;
        Point *prev = &self->points[7];
        Point *cur = &self->points[0];
        int j;
        for (j = 0; j < 8; j++, prev = cur++) {
            float ex = cur->world.x - prev->world.x, ey = cur->world.y - prev->world.y;
            float ax = px - prev->world.x, ay = py - prev->world.y;
            if (ex * ay - ey * ax < 0.0f) break;
            if (hit) continue;
            float c1 = dx * ay - dy * ax;
            if (c1 < 0.0f) continue;
            float bx_ = px - cur->world.x, by_ = py - cur->world.y;
            float c2 = dx * by_ - dy * bx_;
            if (c2 > 0.0f) continue;
            float den = c1 - c2;
            float t = 0.0f;
            if (den != 0.0f) t = c1 / den;
            hit = 1;
            nx = t * ex - ax;
            ny = t * ey - ay;
            depth = nx * dx + ny * dy;
        }
        if (j == 8 && best < depth) {
            best = depth;
            bx = nx;
            by = ny;
        }
    }
    if (best > 0.0f) {
        bx *= 0.5f;
        by *= 0.5f;
        func_0045CBB8(other, bx, by);
        func_0045CBB8(self, -bx, -by);
    }
}
