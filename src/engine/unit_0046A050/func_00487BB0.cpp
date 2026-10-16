/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec4 {float x,y,z,w;};
static inline float mul(float a,float b) { a *= b; return a; }
extern "C" void func_0057D8A0(float *,float *,float);
extern "C" void func_00487BB0(Vec4 *a,float ang) {
    float sc[2];
    Vec4 r __attribute__((aligned(16)));
    func_0057D8A0(&sc[0],&sc[1],ang*0.5f);
    float x=a->x,y=a->y,w=a->w,z=a->z;
    Vec4 *p=&r;
    p->x=mul(sc[1],x)-mul(sc[0],y);
    p->y=mul(sc[1],y)+mul(sc[0],x);
    p->z=mul(sc[0],w)+mul(sc[1],z);
    p->w=mul(sc[1],w)-mul(sc[0],z);
    *(u128*)a=*(u128*)p;
}
