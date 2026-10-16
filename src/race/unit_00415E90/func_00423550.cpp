/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 union {u128 bits;struct {float x,y,z,w;};};
 V() {} V(const V &v) {bits=v.bits;}
 V &operator=(const V &v) {bits=v.bits;return *this;}
 V &operator*=(float f) {x*=f;y*=f;z*=f;return *this;}
 float squared() const {return x*x+y*y+z*z;}
};
struct Angle {float v; Angle() {} Angle(const Angle &a) {v=a.v;} Angle(float f) {v=f;} operator float() const {return v;} Angle operator-() const {return Angle(-v);} };
extern "C" void func_00424140(V*,const V*,const V*);
extern "C" Angle func_00423988(const V*,const V*,const V*);
extern "C" V func_0048D4C0(const V*,const V*);
static inline V scaled(const V &v,float f) {V r(v);r*=f;return r;}
static inline float rsqrt(float a) {float r;asm("rsqrt.s %0, %1, %2":"=f"(r):"f"(1.0f),"f"(a));return r;}
extern "C" void func_00423550(const V *a,const V *b,const V *c,float *out1,float *out2) {
 V d;
 func_00424140(&d,c,b);
 float s=d.squared();
 if(s>0x1.0624dcp-10f) {
  d=scaled(d,rsqrt(s));
  *out1=func_00423988(a,&d,b);
  V cr; {const V &cross=func_0048D4C0(a,b); cr=cross;}
  float cs=cr.squared();
  if(cs==0.0f) *out2=0.0f;
  else {cr=scaled(cr,rsqrt(cs)); *out2=-func_00423988(&d,c,&cr);}
 } else {
  V cr; {const V &cross=func_0048D4C0(a,b); cr=cross;}
  *out1=0.0f;
  *out2=-func_00423988(a,c,&cr);
 }
}
