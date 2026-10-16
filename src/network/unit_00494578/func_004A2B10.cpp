/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Spr { char pad[0x2a8]; float u,v; };
extern "C" int func_004A2BC8(Spr *);
extern "C" int func_004A2B10(float u,float v) {
    union { unsigned int i; float f; } hi;
    hi.i = 0x3f7fffff;
    Spr *s = (Spr *)spr_base();
    float zero = 0.0f;
    __asm__("max.s %0,%0,%1" : "+f"(u) : "f"(zero));
    __asm__("max.s %0,%0,%1" : "+f"(v) : "f"(zero));
    __asm__("min.s %0,%0,%1" : "+f"(u) : "f"(hi.f));
    __asm__("min.s %0,%0,%1" : "+f"(v) : "f"(hi.f));
    s->v = v;
    s->u = u;
    return func_004A2BC8(s);
}
