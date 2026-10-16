/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct S { char p[0x1a0]; u128 a[6]; int n; };
struct Pair { float a[2]; float b[2]; };
struct D : S {
 float f210, f214, f218, f21C;
 Pair pr[4];
 float last[2];
 float f268;
 char pad26C[0x280 - 0x26C];
 u128 q280, q290;
 float f2A0, f2A4, f2A8, f2AC;
 u128 q2B0, q2C0;
 char pad2D0[4];
 int n2D4, n2D8;
 int cnt[2];
 char pad2E4[0x2F0 - 0x2E4];
 u128 q2F0, q300, q310;
 float f320, f324, f328, f32C, f330, f334;
 char pad338[8];
 u128 q340;
 float f350;
 void copyWheel(const D *o, int i) {
  pr[0].a[i] = o->pr[0].a[i];
  pr[0].b[i] = o->pr[0].b[i];
  pr[1].a[i] = o->pr[1].a[i];
  pr[1].b[i] = o->pr[1].b[i];
  pr[2].a[i] = o->pr[2].a[i];
  pr[2].b[i] = o->pr[2].b[i];
  pr[3].a[i] = o->pr[3].a[i];
  pr[3].b[i] = o->pr[3].b[i];
  last[i] = o->last[i];
  cnt[i] = o->cnt[i];
 }
};
extern "C" S *func_00418F10(S *o, const S *b);
extern "C" D *func_00416D10(D *self, const D *o) {
 func_00418F10(self, o);
 self->f210 = o->f210; self->f214 = o->f214; self->f218 = o->f218; self->f21C = o->f21C;
 self->f268 = o->f268;
 self->q280 = o->q280; self->q290 = o->q290;
 self->f2A0 = o->f2A0; self->f2A4 = o->f2A4; self->f2A8 = o->f2A8; self->f2AC = o->f2AC;
 self->q2B0 = o->q2B0; self->q2C0 = o->q2C0;
 self->n2D4 = o->n2D4; self->n2D8 = o->n2D8;
 self->q2F0 = o->q2F0; self->q300 = o->q300; self->q310 = o->q310;
 self->f320 = o->f320; self->f324 = o->f324; self->f328 = o->f328; self->f32C = o->f32C; self->f330 = o->f330; self->f334 = o->f334;
 self->q340 = o->q340;
 self->f350 = o->f350;
 for (int i = 0; i < 2; i++) {
  self->pr[0].a[i] = o->pr[0].a[i];
  self->pr[0].b[i] = o->pr[0].b[i];
  self->pr[1].a[i] = o->pr[1].a[i];
  self->pr[1].b[i] = o->pr[1].b[i];
  self->pr[2].a[i] = o->pr[2].a[i];
  self->pr[2].b[i] = o->pr[2].b[i];
  self->pr[3].a[i] = o->pr[3].a[i];
  self->pr[3].b[i] = o->pr[3].b[i];
  self->last[i] = o->last[i];
  self->cnt[i] = o->cnt[i];
 }
 return self;
}
