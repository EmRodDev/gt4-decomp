/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Spawns one particle (inferred from the pool, free list, life, fade and random size/speed/angle fields). Maps the input type to a
 * particle type, skips it when that type is disabled or the alpha is nearly zero, takes a record from the free list (or recycles one),
 * fills it with randomised look values and stores the plane it sits on (height solved from the plane equation a*x+b*y+c*z+d=0). */
struct Vec3 { float x,y,z; };
struct Node {
    int link:13; unsigned kind:3; unsigned char flags; signed char type;
    int color; float size, alpha, fade, angle, speed;
    short life; signed char jitter, frame;
    Vec3 pos; float height; float a,b,c,d;
};
struct Params { Vec3 color; float enabled; float size, p14, speed; char pad[0x14]; float fade; char pad34[0xC]; unsigned count; };
struct Config { char pad[0x4D0]; Params types[16]; };
struct Pool { Node *recs; unsigned short head; short free; unsigned counters[12]; Config *config; int pad3c; float scale; };
struct Input { unsigned flags; int type; Vec3 pos; float pad14, factor; float a,b,c,d,alpha; };
extern int D_006A3A00[];
extern const float D_006A3A60[];
extern "C" int func_003E79F8(Pool *);
extern "C" float pglmRandom();
extern "C" int func_004AA0D0(float,float,float,float,float);
extern "C" void func_003E75E8(Pool *p, Input *in, int kind) {
    int type = D_006A3A00[in->type];
    if (p->config->types[type].enabled < 0.01f) return;
    if (++p->counters[type] > p->config->types[type].count) p->counters[type] = 0;
    float alpha = in->alpha;
    if (alpha <= 0.001f) return;
    int idx;
    if (p->free < 0) idx = func_003E79F8(p);
    else {
        idx = p->free;
        Node *n = (Node *)(idx * 64 + (int)p->recs);
        p->free = n->link;
        n->link = p->head;
        p->head = idx;
    }
    Node *n = p->recs + idx;
    int frame = (int)(pglmRandom() * 8.0f);
    if (frame >= 8) frame = 7;
    n->flags = frame;
    alpha *= D_006A3A60[frame];
    if (in->flags & 1) n->flags = frame | 0x20;
    n->type = type;
    n->flags |= (idx & 3) << 6;
    float mix = *(float *)((char *)p->config + 0x910);
    float scale = (in->factor * (1.0f - mix) + mix) * p->scale;
    n->color = func_004AA0D0(p->config->types[type].color.x * scale, p->config->types[type].color.y * scale, p->config->types[type].color.z * scale, 0.0f, 128.0f);
    n->size = p->config->types[type].size * alpha;
    n->alpha = alpha;
    float speed = (pglmRandom() - 0.2f) * 0.3f + 1.0f;
    n->speed = p->config->types[type].speed * speed;
    n->angle = pglmRandom() * 360.0f;
    n->fade = alpha + (1.0f - alpha) * p->config->types[type].fade;
    float life = pglmRandom() * ((float)p->config->types[type].count + 0.2f) + 1.0f;
    if (life >= 255.0f) life = 255.0f;
    n->life = (int)(life * 256.0f);
    n->frame = (int)(pglmRandom() * 64.0f);
    n->jitter = (int)(((pglmRandom() - 0.5f) * 0.2f + 1.0f) * 128.0f);
    n->pos.x = in->pos.x;
    n->pos.y = in->pos.y;
    n->pos.z = in->pos.z;
    n->a = in->a;
    n->b = in->b;
    n->c = in->c;
    n->d = in->d;
    n->height = -(n->a * n->pos.x + n->c * n->pos.z + n->d) / n->b;
    n->kind = kind;
}
