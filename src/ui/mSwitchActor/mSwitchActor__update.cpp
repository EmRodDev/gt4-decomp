/* compiler: ee-gcc2.96-stl */
struct Widget { int x; char *vt; };
struct Obj { char p[0x14]; void *face; Widget *a,*b,*c; int count; float x,y,w,h,unknown,amount,speed; };
struct VE { short delta,index; void (*fn)(void *,const char *); };
struct VF { short delta,index; void (*fn)(void *,float); };
extern "C" unsigned int func_002661C8(void *);
extern "C" int func_00265FE0(void *);
extern "C" int func_00266088(void *);
extern "C" void *func_0025C2A0(void *);
extern "C" float mWidget__getWindowW(void *);
extern "C" float mWidget__getWindowH(void *);
extern "C" void mWidget__setWindowPosition(void *,float,float);
extern char D_0083B678[],D_0083B688[],D_0083B638[],D_0083B648[],D_0083B698[],D_0083B6A8[],D_0083B658[],D_0083B668[],D_0083B628[];
static inline void set(Widget *w,const char *s) { VE *e=(VE *)(w->vt+0x1e0); e->fn((char *)w+e->delta,s); }
static inline void fade(Widget *w,float f) { VF *e=(VF *)(w->vt+0x1d0); e->fn((char *)w+e->delta,f); }
extern "C" void mSwitchActor__update(Obj *o) {
 if(o->a) {
  if(func_002661C8(o->face)) {
   if(func_00265FE0(o->face)) set(o->a,D_0083B678);
   else set(o->a,D_0083B688);
  } else {
   if(func_00265FE0(o->face)) set(o->a,D_0083B638);
   else set(o->a,D_0083B648);
  }
 }
 if(o->b) {
  if(func_002661C8(o->face)) {
   if(func_00265FE0(o->face)) set(o->b,D_0083B698);
   else set(o->b,D_0083B6A8);
  } else {
   if(func_00265FE0(o->face)) set(o->b,D_0083B658);
   else set(o->b,D_0083B668);
  }
 }
 if(o->c) {
  if(func_00266088(o->face)) {
   if(++o->count>=7) o->count=0;
   if(o->count<4) set(o->c,D_0083B638);
   else set(o->c,D_0083B628);
  } else {
   if(func_002661C8(o->face)) set(o->c,D_0083B688);
   else { o->count=0; set(o->c,D_0083B648); }
  }
 }
 o->amount+=o->speed;
 if(o->speed>0.0f && o->amount>1.0f) { o->amount=1.0f; o->speed=0.0f; }
 float f=o->amount;
 if(o->speed<0.0f && f<0.0f) { o->amount=0.0f; o->speed=0.0f; f=o->amount; }
 float square=f*f;
 if(o->face) {
  if (func_0025C2A0(o->face)) {
      float cx=mWidget__getWindowW(func_0025C2A0(o->face))*0.5f;
      float cy=mWidget__getWindowH(func_0025C2A0(o->face))*0.5f;
      float hw,hh,scale;
      hw=o->w*0.5f;
      float x=o->x+hw;
      hh=o->h*0.5f;
      scale=(1.0f-square)*0.6f+1.0f;
      float y=o->y+hh;
      mWidget__setWindowPosition(o->face,((x-cx)*scale+cx)-hw,((y-cy)*scale+cy)-hh);
      f=o->amount;
  } else {
      f=o->amount;
  }
 }
 if(o->a) fade(o->a,f);
 if(o->b) fade(o->b,f);
 if(!func_002661C8(o->face)) { if(o->c) fade(o->c,f); }
}
