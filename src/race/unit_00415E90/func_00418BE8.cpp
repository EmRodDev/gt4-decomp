/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
 V(const V &v) {*(u128 *)this=*(const u128 *)&v;}
 V &operator=(const V &v) {*(u128 *)this=*(const u128 *)&v;return *this;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator-=(const V &v) {V r(*this);r[0]-=v.x;r[1]-=v.y;r[2]-=v.z;*this=r;return *this;}
} __attribute__((aligned(16)));
struct Q {
 union {u128 bits;struct {float x,y,z,w;};};
 Q() {}
 Q(const Q &v) {bits=v.bits;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 Q operator=(const Q &v) {bits=v.bits;return *this;}
} __attribute__((aligned(16)));
struct Obj {V pos;Q rot;};
extern "C" Q func_0048D530(const Q &,const Q &);
extern "C" V Numerical_Math__Quaternion__rotate(const Q &,const V &);
static inline Q inverseRotation(const Obj *v) {Q r;r[0]=-v->rot.x;r[1]=-v->rot.y;r[2]=-v->rot.z;r[3]=v->rot.w;return r;}
static inline Q mul(const Q &a,const Q &b) {return func_0048D530(a,b);}
static inline V rotate(const Q &a,const V &b) {return Numerical_Math__Quaternion__rotate(a,b);}
extern "C" void func_00418BE8(Obj *o,const Obj *b) {
 Q inv=inverseRotation(b);
 o->rot=mul(inv,o->rot);
 o->pos-=b->pos;
 o->pos=rotate(inv,o->pos);
}
