/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct Mtx { f32 v[16]; };
struct Cam {
    char pad0[0xC];
    s32 dirty;
    Mtx m;
};

extern "C" {
void func_0042C7C8(Cam *);
f32 func_00486600(Mtx *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *,
                  f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_004A53F8(void);
void func_004A5400(void);
void func_004A7550(Mtx *);
int func_0057F238(const char *, const char *) throw();
extern char D_006A4CD8[];
}

static inline void invert(Mtx *s, Mtx *m) {
    func_00486600(s, &s->v[1], &s->v[2], &s->v[3], &s->v[4], &s->v[5], &s->v[6], &s->v[7], &s->v[8], &s->v[9], &s->v[10], &s->v[11], &s->v[12], &s->v[13], &s->v[14], &s->v[15], m->v[0], m->v[1], m->v[2], m->v[3], m->v[4], m->v[5], m->v[6], m->v[7], m->v[8], m->v[9], m->v[10], m->v[11], m->v[12], m->v[13], m->v[14], m->v[15]);
}

extern "C" void func_0042AF40(Cam *self, const char *name) {
    if (func_0057F238(name, D_006A4CD8) == 0) {
        func_004A53F8();
        func_004A7550(&self->m);
        invert(&self->m, &self->m);
        self->dirty = 1;
        func_004A5400();
        func_0042C7C8(self);
    }
}
