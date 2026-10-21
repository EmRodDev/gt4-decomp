/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P8 { char *a; int b; P8() {} P8(const P8 &o) : a(o.a), b(o.b) {} };
struct Obj { char pad[0x30]; int m30; P8 m34; int m3C,m40; char *m44; int m48; char *m4C; int m50,m54; };
extern "C" P8 func_00579CB8(void *, int);
extern "C" void func_00575228(Obj *o, void *arg1) {
    o->m30 = 1;
    o->m34 = func_00579CB8(arg1, 4);
    int b = o->m34.b;
    o->m40 = 0;
    o->m44 = o->m34.a;
    o->m48 = 0;
    o->m4C = o->m34.a + b;
    o->m50 = 0;
    o->m54 = 0;
    o->m3C = b;
}
