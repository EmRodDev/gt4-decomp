/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s128 __attribute__((mode(TI)));
inline void *operator new(unsigned int, void *p) { return p; }
struct Pair {
    s128 m0, m10;
    Pair() {}
    Pair(const Pair &o) : m0(o.m0), m10(o.m10) {}
};
struct D_006865C8 : Pair { virtual ~D_006865C8(); };
extern "C" void func_005FFA28(D_006865C8 *dst, const D_006865C8 *src) {
    new (dst) D_006865C8(*src);
}
