/* compiler: ee-gcc2.96-stl */
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct A { char p[0x364]; int n; };
struct B { char p[0x6c8]; float speed; };
struct Pair { float a,b; };
extern "C" float func_003446A0(B *);
extern "C" float func_0035A540(B *,int);
extern "C" float func_00401048(B *) throw();
extern "C" void func_00406E28(void **,B *);
extern "C" float *func_00407208(void *,void *);
extern "C" void func_0040CD18(void **,void *);
extern "C" float func_0040D068(void **,B *);
extern "C" void func_0040CEC0(void **,float);
extern "C" void func_0040CED0(void **,float);
extern "C" void func_0040CEE0(void **,float);
extern "C" void func_0040CEF0(void **,float);
extern "C" void func_0040CF00(void **,float);
extern "C" void func_0040CF10(void **,float);
extern "C" void func_0040CF20(void **,float);
extern "C" void func_0040CF30(void **,float);
extern "C" void func_0040CF40(void **,float);
extern "C" void func_0040CF50(void **,float);
extern "C" void func_0040CF60(void **,float);
extern "C" void func_0040CF70(void **,float);
extern "C" void func_0040CF80(void **,float);
extern "C" void func_0040CF90(void **,float);
extern "C" void func_0040CFA0(void **,float);
extern "C" void func_0040D018(void **,float);
extern "C" void func_0040D028(void **,float);
extern "C" void func_0040D038(void **,float);
extern "C" void func_0040D048(void **,float);
extern "C" void func_0040D058(void **,float);
static inline float mx(float a,float b) { float r; __asm__("max.s %0,%2,%1" : "=f"(r), "+f"(b) : "f"(a)); return r; }
static inline float mn(float a,float b) { float r; __asm__("min.s %0,%2,%1" : "=f"(r), "+f"(b) : "f"(a)); return r; }
static inline void init(Pair *p,float x0,float y0,float x1,float y1) { p->a=(y1-y0)/(x1-x0); p->b=0x1.79435cp-1f; }
static inline float eval(Pair *p,float x) { return p->a*x+p->b; }
static inline float clamp(float *lo,float *hi,float x) { x=mx(x,*lo); return mn(x,*hi); }
extern "C" void func_00401148(A *self,B *obj,int arg) {
 Pair coeff;
 float lo,hi;
 void *handle;
 void *src=(char *)self+0x160;
 void *dst=(char *)self+0x260;
 self->n=arg;
 init(&coeff,1.0f,0.75f,20.0f,1.0f);
 float speed=obj->speed*60.0f*60.0f*0x1.0624dcp-10f;
 float a=func_0035A540(obj,2);
 float b=func_0035A540(obj,3);
 float c=func_003446A0(obj);
 float d=func_00401048(obj);
 lo=0.75f;
 hi=1.0f;
 float f=clamp(&lo,&hi,eval(&coeff,speed))*d;
 float g=f*0x1.999998p-3f;
 void **h=&handle;
 func_0040CD18(h,src);
 func_0040CEF0(h,b);
 func_0040CF00(h,c);
 func_0040CF10(h,0.0f);
 func_0040CF40(h,a);
 func_0040CF20(h,0.0f);
 func_0040CF30(h,0.0f);
 if((absf(speed))<1.0f) func_0040CF50(h,1.0f);
 else func_0040CF50(h,0.0f);
 func_0040CEC0(h,g);
 func_0040CED0(h,0.0f);
 func_0040CEE0(h,f);
 func_0040CF60(h,0.0f);
 func_0040CF70(h,0.0f);
 func_0040CF80(h,0.0f);
 func_00406E28(h,obj);
 func_0040CF90(h,0.0f);
 func_0040CFA0(h,0.0f);
 func_0040D018(h,__builtin_fabsf(func_0040D068(h,obj)));
 func_0040D028(h,0.0f);
 func_0040D038(h,-4.0f);
 func_0040D048(h,0.0f);
 func_0040D058(h,0.0f);
 func_00407208(dst,src);
}
