/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V;
extern "C" void func_004878C0(V *,const V *,float);
struct Angle {float v; Angle(float f):v(f){} Angle(const Angle &a):v(a.v){} };
struct V {
 union {struct{float x,y,z,w;};u128 q;};
 V(){} V(const V&o){q=o.q;}
 V &operator=(const V&o){q=o.q;return *this;}
 void negative(const V &v){x=-v.x;y=-v.y;z=-v.z;}
 V operator-() const {V r;r.negative(*this);return r;}
 float length2() const {return x*x+y*y+z*z;}
 V &scale(float s){x*=s;y*=s;z*=s;return *this;}
 V normal() const {
  float l=length2(),s=1.0f; V r(*this);
  __asm__("rsqrt.s %0, %1, %2":"=f"(s):"f"(s),"f"(l));
  r.scale(s);return r;
 }
 V &rotate(const V &axis,const Angle &a) {func_004878C0(this,&axis,a.v);return *this;}
};
struct Base {
 char pad[0x20];
 virtual V position();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual float length();
};
struct Obj : Base {
 char rest[0x2c];
 V &pos() {return *(V *)this;}
 V &rot() {return *(V *)((char *)this+0x10);}
};
struct Plane {V normal;float d;};
struct Self {char pad[0x110]; Obj a,b,c,d;};
extern "C" V func_0041B9E0(Obj *) throw();
extern "C" void func_0048D4C0(V *,const V *,const V *);
static inline V cross(const V &a,const V &b){V r;func_0048D4C0(&r,&a,&b);return r;}
extern "C" float func_0059D2A0(float);
static inline float maxf(float a,float b) {float r;__asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float minf(float a,float b) {float r;__asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float clamp(const float &v,float lo,float hi){float r;__asm__("max.s %0, %0, %2":"=f"(r):"0"(v),"f"(lo));__asm__("min.s %0, %0, %2":"=f"(r):"0"(r),"f"(hi));return r;}
struct Ratio {float v;Ratio(float f):v(f){} Ratio(const Ratio&r):v(r.v){} };
static inline float angle(const float &f){return 0x1.921fb4p+0f-func_0059D2A0(clamp(f,-1.0f,1.0f));}
static inline float clampvalue(float v,float lo,float hi){return minf(maxf(v,lo),hi);}
static inline float distance(const Plane *p,const V &v,float len){return (p->normal.x*v.x+p->normal.y*v.y+p->normal.z*v.z+p->d)/len;}
extern "C" void func_0041F670(Self *self,const Plane *p0,const Plane *p1) {
 for(int i=0;i<2;i++) {
  Obj *a,*b;const Plane *p;
  if(i==0){a=&self->a;b=&self->c;p=p0;}
  else {a=&self->b;b=&self->d;p=p1;}
  V pos=b->pos();
  V end=b->position();
  float len=p->normal.length2();
  __asm__("sqrt.s %0, %0":"+f"(len));
  float de=distance(p,end,len);
  float dp=distance(p,pos,len);
  float length=b->length();
  if(!(de>0.0f)) {
   float ratio[1];
   ratio[0]=dp/length;
   float theta=angle(ratio[0]);
   ratio[0]=(dp-de)/length;
   theta-=angle(ratio[0]);
   theta=clampvalue(theta,-0x1.921fb4p-1f,0x1.921fb4p-1f);
   V dir=func_0041B9E0(b);
   V opposite=-func_0041B9E0(a);
   V axis=cross(dir,opposite);
   if(!(axis.length2()<=0x1.0624dcp-10f)) {
    axis=axis.normal();
    b->rot()=V(b->rot()).rotate(axis,Angle(theta));
   }
  }
 }
}
