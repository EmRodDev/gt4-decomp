/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int U128 __attribute__((mode(TI)));
struct V { float x,y,z; };
extern "C" char *func_0041A8C0(char *, unsigned int) throw();
extern "C" char *func_0041AA50(char *, const U128 *, const V *) throw();
extern "C" void func_0041AE20(char *self, const U128 *src) {
    for (int i = 0; i < 20; ++i) {
        *(U128 *)(func_0041A8C0(self, i) + 0x10) = src[i];
    }
    V v;
    v.z = v.y = v.x = 0.0f;
    func_0041AA50(self, src, &v);
}
