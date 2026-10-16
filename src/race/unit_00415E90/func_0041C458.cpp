/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &X() {return x;} float &Y() {return y;} float &Z() {return z;}
 V operator-() const { V r;r.X()=-x;r.Y()=-y;r.Z()=-z;return r; }
 V operator-(const V &v) const { V r=*this;r.X()-=v.x;r.Y()-=v.y;r.Z()-=v.z;return r; }
 V operator+(const V &v) const { V r=*this;r.X()+=v.x;r.Y()+=v.y;r.Z()+=v.z;return r; }
 int iszero() const { return x==0.0f && y==0.0f && z==0.0f; }
} __attribute__((aligned(16)));
struct E {short delta,index;void (*fn)(V *,char *);};
struct O {V pos,rot;E *vt;};
extern "C" void func_00421D88(V *,V *);
extern "C" V func_00421DC0(V *);
extern "C" void func_00488948(V *,V *,V *);
extern "C" void func_00488DF0(V *,V *,V *,V *,V *);
extern "C" void func_00488E28(V *,float,V *,V *);
extern "C" void func_004878C0(V *,V *,float);
static inline void neg(V *r,const V &v) {r->X()=-v.x;r->Y()=-v.y;r->Z()=-v.z;}
static inline void sf(float &a,const float &b) {a-=b;}
static inline void sub(V *r,const V &a,const V &b) { *r=a;sf(r->X(),b.x);sf(r->Y(),b.y);sf(r->Z(),b.z); }
static inline void add(V *r,const V &a,const V &b) { *r=a;r->X()+=b.x;r->Y()+=b.y;r->Z()+=b.z; }
static inline void getpos(V *r,O *o) { E *e=o->vt+1;e->fn(r,(char *)o+e->delta); }
extern "C" int func_0041C458(void *,O *o,O *other,V *target,V *out,const float &factor,float t) {
 V origin;getpos(&origin,o);
 V pos=o->pos;
 V rot=other->rot;
 V before=rot;
 V dir;
 V temp=func_00421DC0(&rot);
 V point;
 neg(&point,temp);dir=point;
 if(out->iszero()) func_00488948(&rot,&dir,target);
 else {
  func_00421D88(&temp,&rot);
  func_00488DF0(&rot,&dir,&temp,target,out);
 }
 func_00488E28(&temp,t,&before,&rot);
 V inv=func_00421DC0(&temp);
 V negative;neg(&negative,inv);point=negative;
 dir=point;
 point.X()=factor;
 func_004878C0(&temp,&dir,factor);
 o->rot=temp;
 getpos(&point,o);
 V arith;sub(&arith,origin,point);negative=arith;add(&arith,pos,negative);o->pos=inv=arith;
 return 1;
}
