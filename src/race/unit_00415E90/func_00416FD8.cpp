/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec {
 union { u128 q; struct { float x,y,z,w; } f; };
 Vec() {}
 Vec(const Vec &v) { q=v.q; }
 Vec &operator=(const Vec &v) { q=v.q; return *this; }
} __attribute__((aligned(16)));
struct M3 { u128 r[3]; };
struct Transform { Vec v; M3 m; Transform(Transform *t); };
struct Frame { char data[0xc0]; } __attribute__((aligned(16)));
struct Input { int mode; char pad[12]; Vec v; };
extern "C" M3 *func_00421C58(M3 *,void *);
extern "C" Vec func_004187A0(Transform *,const Vec *);
inline Transform::Transform(Transform *t) {v=t->v; func_00421C58(&m,&t->m);}
static inline Transform inverted(Transform *t) {return Transform(t);}
extern "C" void func_00418F88(Frame *);
extern "C" void func_004173B0(void *,void *,Transform *,Frame *);
extern "C" int func_0041C3F8(void *,void *,Frame *,Vec *,void *,void *);
static inline void negate(float &x) {x=-x;}
extern "C" void *func_00416FD8(char *out,void *a,Transform *t,Input *in,void *extra) {
 Vec v;
 Vec *pv=0;
 if (in) {
  pv=&v;
  v.q=in->v.q;
  if (in->mode==0) {
   v=func_004187A0(&inverted(t),&v);
  } else if (in->mode==1) {
   negate(v.f.x); negate(v.f.z);
   v=func_004187A0(&inverted(t),&v);
  }
 }
 Frame frame;
 func_00418F88(&frame);
 func_004173B0(out,a,t,&frame);
 func_0041C3F8(out,a,&frame,pv,extra,out+0xe0);
 return out;
}
