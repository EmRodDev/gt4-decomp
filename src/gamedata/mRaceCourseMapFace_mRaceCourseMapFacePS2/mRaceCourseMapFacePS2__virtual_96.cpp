typedef unsigned int u32;
struct Vec2 { float x, y; };
struct Map { char pad[0x2C]; u32 count; Vec2 *pts; };
struct Obj { char pad[0xC8]; Map *map; char padCC[8]; float length; float d8, dc; Vec2 pos; };
extern "C" float func_0057D788(float, float);
static inline Vec2 *points(Map *m) { if (m->count) return m->pts; return 0; }
extern "C" void mRaceCourseMapFacePS2__virtual_96(Obj *self, float distance) {
    if (self->map) {
        Vec2 *p = points(self->map);
        if (p) {
            distance = func_0057D788(distance, self->length);
            if (distance < 0.0f) distance += self->length;
            u32 n = self->map->count - 1;
            u32 i = (u32)((distance * (float)n) / self->length);
            float t = ((distance - ((self->length * (float)i) / (float)n)) * (float)n) / self->length;
            Vec2 *a = (Vec2 *)(i * 16 + (unsigned int)p);
            Vec2 *b = a + 1;
            Vec2 *c = a + 2;
            float x = (a->x + b->x) * 0.5f;
            float y = (a->y + b->y) * 0.5f;
            Vec2 *e = a + 3;
            float x1 = (c->x + e->x) * 0.5f;
            float y1 = (c->y + e->y) * 0.5f;
            float outX = (x1 - x) * t + x;
            float outY = (y1 - y) * t + y;
            self->pos.x = outX;
            self->pos.y = outY;
        }
    }
}
