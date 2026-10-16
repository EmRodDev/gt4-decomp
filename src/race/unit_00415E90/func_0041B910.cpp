/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &o) {*(u128 *)this=*(const u128 *)&o;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator-(const V &v) const {V r(*this);r[0]-=v.x;r[1]-=v.y;r[2]-=v.z;return r;}
} __attribute__((aligned(16)));
struct Obj {
 V pos;
 char pad[0x10];
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual V getPosition();
};
extern "C" V func_0041B910(Obj *o) {
 return o->getPosition()-o->pos;
}
