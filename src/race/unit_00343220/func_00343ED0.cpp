/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned char u8; typedef float f32;
struct Info { u8 p0; u8 n; };
struct Ent { f32 f0, f4, f8; char pC[0x18]; f32 f24; char p28[0x64]; f32 f8C; char p90[4]; f32 f94; char p98[0xC]; f32 fA4; char pA8[0x18]; f32 fC0; char pC4[0x28]; };
struct Rec { f32 pos[3]; char pC[8]; f32 f14, f18; char p1C[0x18]; };
struct Vec3 { f32 x, y, z; };
struct Car { char p0[0x60]; Ent ents[4]; char p410[0x4A4 - 0x410]; f32 f4A4; char p4A8[0x568 - 0x4A8]; f32 v568[3]; f32 v574[2]; char p57C[0x5FC - 0x57C]; f32 f5FC, f600; };
struct Self {
    char p0[0x10]; void *p10; char p14[0x104 - 0x14];
    Car car;
    char p708[0x7B8 - 0x104 - sizeof(Car)];
    Rec recs[4];
    char p888[0x8BC - 0x888];
    f32 v8BC[3]; f32 v8C8[2];
    f32 a[4], b[4], c[4], d[4], e[4], f[4], g[4], h[4];
    f32 v[4][3];
    f32 k[4];
    f32 p990;
    f32 f994, f998, f99C;
};
extern "C" Info *func_00359510(void *);
extern "C" void func_00343ED0(Self *self) {
    Car *car = &self->car;
    Info *info = func_00359510(self->p10);
    int i;
    for (i = 0; i < 3; i++) self->v8BC[i] = car->v568[i];
    for (i = 0; i < 2; i++) self->v8C8[i] = car->v574[i];
    for (i = 0; i < info->n; i++) {
        Ent *en = &self->car.ents[i];
        self->a[i] = en->f94;
        self->b[i] = en->f0;
        self->c[i] = en->f4;
        self->d[i] = en->f8;
        self->e[i] = en->f24;
        self->f[i] = en->fA4;
        self->g[i] = self->recs[i].f14;
        self->h[i] = self->recs[i].f18;
        self->v[i][0] = self->recs[i].pos[0];
        self->v[i][1] = en->f8C;
        self->v[i][2] = self->recs[i].pos[2];
        self->k[i] = en->fC0;
    }
    self->f994 = car->f5FC;
    self->f998 = car->f600;
    self->f99C = car->f4A4;
}
