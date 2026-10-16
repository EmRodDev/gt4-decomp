/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &o) { *(u128 *)this=*(const u128 *)&o; }
 V &operator=(const V &o) { *(u128 *)this=*(const u128 *)&o; return *this; }
 float &at(int i) { return ((float *)this)[i]; }
 float at(int i) const { return ((const float *)this)[i]; }
 const V operator-(const V &o) const { V r(*this); r.at(0)-=o.at(0); r.at(1)-=o.at(1); r.at(2)-=o.at(2); return r; }
 const V operator+(const V &o) const { V r(*this); r.at(0)+=o.at(0); r.at(1)+=o.at(1); r.at(2)+=o.at(2); return r; }
} __attribute__((aligned(16)));
struct M { V rows[3]; };
struct Item { V pos, rot; };
extern "C" Item *func_0041A8C0(void *, unsigned) throw();
extern "C" M func_00421C58(void *);
extern "C" void func_00489300(V *, M *, V *);
static inline V transform(M *m, V *v) { V r; func_00489300(&r,m,v); return r; }
extern "C" void func_0048D530(V *, void *, V *);
static inline V rotate(void *m, V *v) { V r; func_0048D530(&r,m,v); return r; }
extern "C" void *func_0041AEA8(void *self, void *arg1, V *origin) {
 M m=func_00421C58(arg1);
 for(int i=0; i<20; ++i) {
  V pos=func_0041A8C0(self,i)->pos - *origin;
  V rot=func_0041A8C0(self,i)->rot;
  pos=transform(&m,&pos) + *origin;
  rot=rotate(arg1,&rot);
  func_0041A8C0(self,i)->pos=pos;
  func_0041A8C0(self,i)->rot=rot;
 }
 return self;
}
