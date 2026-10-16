/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &v) { *(u128 *)this = *(const u128 *)&v; }
    V &operator=(const V &v) { *(u128 *)this = *(const u128 *)&v; return *this; }
} __attribute__((aligned(16)));
struct SegBase { V pos; V rot; virtual void f(); };
struct Seg : SegBase { V c; float len, scale; };
struct Body : Seg {
    V v50, v60;
    Seg a0, a1, a2, a3, a4, a5, a6, a7, a8;
    V v340, v350;
    Seg b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
};
extern "C" Body *func_00419810(Body *self, const Body *o) {
    *self = *o;
    return self;
}
