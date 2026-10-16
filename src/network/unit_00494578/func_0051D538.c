/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Ctx Ctx;
typedef struct Owner Owner;
struct Ctx { char p0[8]; int mode; char pC[0x64]; char timer[8]; };
struct Owner { int state; char p4[0x1c]; char timer[0x10]; unsigned delay; char timer34[8]; int count; unsigned timeout; int busy; union { int value; unsigned short half; } code; char p4C[0x20]; char queue[16]; };
int func_0051E028(Ctx *, Owner *);
int func_0051E158(Owner *, unsigned, int, const void *, unsigned, int);
int func_0051F9D8(Owner *);
int func_0051FE10(Owner *);
int func_00538460(void *, int, int);
int func_00538530(void *, int *);
int func_00538F70(void *, unsigned);
int func_0053A860(void *);
int func_0053A890(void *, unsigned *);
static __inline__ int put(unsigned char *p, unsigned v, Ctx *ctx) { *p = v; return ctx->mode; }
int func_0051D538(unsigned context, Owner *s) {
 Ctx *ctx = (Ctx *)context;
 unsigned char data[16];
 unsigned char tmp[16];
 unsigned elapsed;
 int queued;
 int work = 0;
 int retry = 0;
 void *q;
 int mode;
 mode = put(data, 0xa5, ctx);
 queued = 0;
 elapsed = 0;
 if (mode == 8) {
  if (s->delay != 0) {
   void *timer = s->timer34;
   func_0053A890(timer, &elapsed);
   if (s->delay < elapsed) {
    int r = func_0051E158(s, 5, 0xffff, data, 1, 0);
    if (r != 0) return r;
    func_0053A860(timer);
    s->count++;
   }
  }
 } else if (mode == 6 && s->state == 1) {
  func_0053A890(ctx->timer, &elapsed);
  if (elapsed >= 201) {
   int r = func_0051E028(ctx, s);
   if (r != 0) return r;
  }
 }
 if (s->busy != 0 && s->code.value != 0xffff) {
  unsigned type;
  void *p;
  unsigned len;
  int r;
  if (s->code.value == 0xfffe) {
   type = 15;
   p = 0;
   len = 0;
  } else {
   type = 16;
   func_00538F70(tmp, s->code.half);
   p = tmp;
   len = 2;
  }
  r = func_0051E158(s, type, 0xffff, p, len, 0);
  if (r != 0) return r;
 }
 func_0053A890(s->timer, &elapsed);
 if (s->timeout < elapsed || s->timeout == 0 || s->busy != 0 || ctx->mode != 8) {
  work = 1;
  if (func_0051FE10(s) == 0xcb2c) retry = 1;
  else s->busy = 0;
 }
 q = s->queue;
 func_00538530(q, &queued);
 if (queued != 0) {
  if (work != 0) {
   int r = func_0051F9D8(s);
   if (r != 0) return r;
   r = func_00538460(q, 0, 0);
   if (r != 0) return r;
  }
  if (retry && func_0051FE10(s) != 0xcb2c) s->busy = 0;
 }
 return 0;
}
