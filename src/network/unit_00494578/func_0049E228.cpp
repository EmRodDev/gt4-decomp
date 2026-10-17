/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef float f32;
typedef unsigned char u8;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Src {
    u128 m[4];
    f32 f40;
    u8 f44;
};

struct Glob {
    char pad0[0x20];
    u128 scale[4];
    u8 enable;
};

struct Spr {
    char pad0[0x48];
    unsigned short flags;
    char pad4A[0xA60 - 0x4A];
    u128 m[4];
    char padAA0[0];
    f32 fAA0;
};

extern Glob D_00624CC0;

extern "C" void func_0049E228(Src *src) {
    Spr *p = (Spr *)spr_base();
    Glob *g = &D_00624CC0;
    __asm__ volatile("vnop");
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(src->m[0]));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(src->m[1]));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(src->m[2]));
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(src->m[3]));
    if (g->enable && (u8)(src->f44 & 1)) {
        __asm__ volatile("lqc2 $vf5, %0" : : "m"(g->scale[0]));
        __asm__ volatile("lqc2 $vf6, %0" : : "m"(g->scale[1]));
        __asm__ volatile("lqc2 $vf7, %0" : : "m"(g->scale[2]));
        __asm__ volatile("lqc2 $vf8, %0" : : "m"(g->scale[3]));
        __asm__ volatile("vmul.xyzw $vf1, $vf1, $vf5");
        __asm__ volatile("vmul.xyzw $vf2, $vf2, $vf6");
        __asm__ volatile("vmul.xyzw $vf3, $vf3, $vf7");
        __asm__ volatile("vmul.xyzw $vf4, $vf4, $vf8");
    }
    p->fAA0 = src->f40;
    if (src->f44 & 2)
        p->flags |= 0x80;
    else
        p->flags &= ~0x80;
    p->flags |= 4;
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(p->m[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(p->m[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(p->m[2]));
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(p->m[3]));
}
