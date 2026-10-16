/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_004894E8(float *,const float *,const float *) throw();
extern "C" void func_00489510(float *v,const float *m) {
    float r[4] __attribute__((aligned(16)));
    func_004894E8(r,m,v);
    *(u128*)v=*(u128*)r;
}
