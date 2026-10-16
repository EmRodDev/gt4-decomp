/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_004893E8(float *,const float *,const float *) throw();
extern "C" void func_004894B0(float *v,const float *m) {
    float r[4] __attribute__((aligned(16)));
    func_004893E8(r,m,v);
    *(u128*)v=*(u128*)r;
}
