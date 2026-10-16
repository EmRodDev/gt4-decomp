/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { char pad[0xA0]; };
struct Sub { float a; float value; char gap8[4]; float w; char gap10[4]; float h; };
struct State { char pad[0x34]; float x, y, z; char gap40[0xAC - 0x40]; Sub sub; };
struct Result { unsigned short flags; char gap[0x4E]; State *state; };
struct Obj;
struct Entry { short delta, index; Result *(*fn)(Obj *); };
struct Obj { char pad[8]; Entry *vt; };
struct Car { char pad[0x2880]; Obj *obj; };
struct Table { char pad[8]; Car **cars; };
struct Root { char pad[0x60]; Table *table; };
struct Pitmen {
    char pad[0x789C];
    Blk blk[6];
    char gap7C5C[0x9640 - 0x7C5C];
    float values[6];
    int modes[6];
};
extern "C" void func_003CB060(Blk *, float, float, float) throw();
#define maxf(x, y) ({ float _r; __asm__("max.s %0,%1,%2" : "=f"(_r) : "f"(x), "f"(y)); _r; })

extern "C" int func_003CE288(Pitmen *self, int idx, Root **root, int *flag1, int *flag2) {
    Obj *obj = (*root)->table->cars[idx]->obj;
    Entry *e = &obj->vt[10];
    Result *res = e->fn((Obj *)((char *)obj + e->delta));
    State *st = res->state;
    Blk *blk = &self->blk[idx];
    if (st != 0) {
        Sub *sub = &st->sub;
        float w = sub->w;
        float h = sub->h;
        *flag1 = (res->flags >> 2) & 1;
        float big = maxf(maxf(-w, -h), maxf(w, h));
        *flag2 = (res->flags >> 3) & 1;
        func_003CB060(blk, st->x, st->y + 1.0f, st->z);
        self->values[idx] = sub->value;
        if (big == -w) self->modes[idx] = 0;
        else if (big == -h) self->modes[idx] = 1;
        else if (big == w) self->modes[idx] = 2;
        else if (big == h) self->modes[idx] = 3;
        else st = 0;
    }
    if (st == 0) {
        *flag1 = 1;
        *flag2 = 1;
        func_003CB060(blk, 0.0f, 1.0f, 0.0f);
        self->values[idx] = 0.0f;
        self->modes[idx] = 0;
        return 0;
    }
    return 1;
}
