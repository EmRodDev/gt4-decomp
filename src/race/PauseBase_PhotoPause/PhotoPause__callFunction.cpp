/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Value { int type; float data; int x,y; };
struct Str { char *p; };
struct VE { short delta,index; float (*fn)(void *); };
struct Camera { VE *vt; };
struct Photo { char pad[0x1ac]; int blink; };
struct Global { char pad[0x38cc4]; int wide; };
extern Global *D_00622F4C;
extern "C" void func_00480FA0(void *,int);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005FBDD0(Str *,const char *,unsigned int,unsigned int);
extern "C" Camera *func_003C3FA0(Photo *) throw();
extern "C" Value *func_003C4078(Value *,char *) throw();
extern "C" int func_00374128(Camera *);
extern "C" int func_00374120(Camera *);
extern "C" int func_00374130(Camera *);
extern "C" int func_003740A8(Camera *);
extern "C" void func_004857C8(const char *);
extern "C" double fptodp(float);
extern "C" void func_0057DA20(char *,const char *,...);
static inline int equal(Str *s,const char *t) { return func_005FBDD0(s,t,0,func_0057F260(t))==0; }
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float get(Camera *c,int slot) { VE *e=c->vt+slot; return e->fn((char *)c+e->delta); }
static inline void number(Value *v,float f) { v->type=6; v->data=f; }
extern "C" Value *PhotoPause__callFunction(Value *ret,Photo *self,Str *name,int arg,void *out) {
 char buf[64];
 func_00480FA0(out,arg);
 if(equal(name,"GETZOOM")) {
  func_0057DA20(buf,"f = %dmm",(int)(get(func_003C3FA0(self),15)*1000.0f+0.5f));
  func_003C4078(ret,buf);
 } else if(equal(name,"GETIRIS")) {
  func_0057DA20(buf,"F %.1f",fptodp(get(func_003C3FA0(self),11)+0.05f));
  func_003C4078(ret,buf);
 } else if(equal(name,"GETSHUTTER")) {
  func_0057DA20(buf,"1/%d''",(int)(1.0f/get(func_003C3FA0(self),12)+0.5f));
  func_003C4078(ret,buf);
 } else if(equal(name,"GETEXPOSURE")) {
  float f=get(func_003C3FA0(self),16);
  float magnitude=absf(f);
  func_0057DA20(buf,"%c%.1f EV",f<0.0f?'-':'+',fptodp(0.05f+magnitude));
  func_003C4078(ret,buf);
 } else if(equal(name,"GETCURCAM")) {
  func_0057DA20(buf,"%d",func_00374128(func_003C3FA0(self))+1);
  func_003C4078(ret,buf);
 } else if(equal(name,"GETNCAM")) {
  func_0057DA20(buf,"%d",func_00374120(func_003C3FA0(self)));
  func_003C4078(ret,buf);
 } else if(equal(name,"ISPORTRAIT")) {
  number(ret,get(func_003C3FA0(self),18)>0.5f?1.0f:0.0f);
 } else if(equal(name,"ISFOCUSTRIGGER")) {
  int f=func_00374130(func_003C3FA0(self));
  if(f) func_004857C8("zoom");
  number(ret,f?1.0f:0.0f);
 } else if(equal(name,"GETFILTER")) {
  float f=get(func_003C3FA0(self),17);
  int n=0;
  if(f<5490.0f) n=1;
  if(f>5510.0f) n=2;
  number(ret,(float)n);
 } else if(equal(name,"GETMF")) {
  number(ret,func_003740A8(func_003C3FA0(self))!=0?0.0f:1.0f);
 } else if(equal(name,"ISWIDE")) {
  number(ret,D_00622F4C->wide?1.0f:0.0f);
 } else if(equal(name,"GETBLINK")) {
  number(ret,(float)self->blink);
 } else { ret->type=1; }
 return ret;
}
