/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P {
    unsigned a, b;
    P() { a = 0; b = 0; }
    P(const P &p) { a = p.a; b = p.b; }
    unsigned end() const { return a + b; }
};
extern char D_00688E30[];
extern "C" int func_00574AE0(void *);
extern "C" void func_00574D78(void *);
struct Base {
    char pad0[0x40];
    int active;
    char *vt;
    char pad48[0x3030];
    int x;
    Base() {
        func_00574AE0(this);
        vt = D_00688E30;
        func_00574D78((char *)this + 0x3048);
        x = 0;
    }
};
struct Owner : Base {
    P p1;
    P parts[2];
    int y;
    Owner(P *src) : p1(*src) {
        active = 1;
        y = 0;
        parts[0].a = p1.a;
        parts[0].b = p1.b >> 1;
        parts[1].a = parts[0].end();
        parts[1].b = parts[0].b;
    }
};
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" int func_004ADEE0(void *o, P *src) {
    new(o) Owner(src);
}
