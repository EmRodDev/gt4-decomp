/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V3 { float x,y,z,w; };
extern "C" void func_004887D8(float *, V3 *, V3 *);
extern "C" void func_00418B60(char *self, V3 *a, V3 *b) {
    float r[4] __attribute__((aligned(16)));
    func_004887D8(r,a,b);
    *(u128 *)(self+16)=*(u128 *)r;
}
