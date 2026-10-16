/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
union Vec { struct { float x,y,z,w; }; u128 q; Vec() {} Vec(const Vec &v) { q=v.q; } };
extern "C" void func_00486FF8(void *,Vec *,const Vec *);
extern "C" Vec func_00421DF8(void *m,float x,float y,float z) {
 Vec v;
 v.x=x; v.y=y; v.z=z;
 Vec r;
 func_00486FF8(m,&r,&v);
 return r;
}
