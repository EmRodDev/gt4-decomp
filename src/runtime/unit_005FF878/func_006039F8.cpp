/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { s32 a, b; };
struct H { s32 a; s32 b; };
struct R { H *p; };
extern "C" char *func_006039F8(R *r, s32 i) {
    H *base = r->p;
    Ent *t = (Ent *)((char *)base + 0x10);
    char *tb = (char *)t;
    s32 x = *(s32 *)(tb + (i << 3)) + 2;
    char *q = (char *)(t + base->b);
    return q + x;
}
