/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned char u8;
typedef unsigned long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Vec {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
};

struct Scratch {
    u8 dirty;
    u8 current;
    char pad2[0xED0 - 2];
    u128 matrix[4];
};

extern u128 D_0084AFF0[3];
extern f32 D_0084B020[3][4];
extern f32 D_0084B050[4];

extern "C" void func_0049F658(f32 x, f32 y, f32 z) throw();

/* Builds the camera basis from the eye direction and up vector, then its view matrix. */
extern "C" void func_0049F7D8(f32 x, f32 y, f32 z, f32 ux, f32 uy, f32 uz) {
    Scratch *s = (Scratch *)spr_base();
    Vec up, dir;
    u64 r0, r1, r2, t0, t1, t2, t3;

    __asm__ volatile("vnop");
    up.v.x = ux;
    up.v.y = uy;
    up.v.z = uz;
    dir.v.x = x;
    dir.v.y = y;
    dir.v.z = z;
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(up.q));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(dir.q));
    __asm__ volatile("vopmula.xyz ACC, $vf2, $vf3");
    __asm__ volatile("vopmsub.xyz $vf4, $vf3, $vf2");
    __asm__ volatile("vmul.xyzw $vf1, $vf3, $vf3");
    __asm__ volatile("vaddy.x $vf1, $vf1, $vf1y");
    __asm__ volatile("vaddz.x $vf1, $vf1, $vf1z");
    __asm__ volatile("vrsqrt Q, $vf0w, $vf1x");
    __asm__ volatile("vwaitq");
    __asm__ volatile("vmulq.xyzw $vf3, $vf3, Q");
    __asm__ volatile("vmul.xyzw $vf1, $vf4, $vf4");
    __asm__ volatile("vaddy.x $vf1, $vf1, $vf1y");
    __asm__ volatile("vaddz.x $vf1, $vf1, $vf1z");
    __asm__ volatile("vrsqrt Q, $vf0w, $vf1x");
    __asm__ volatile("vwaitq");
    __asm__ volatile("vmulq.xyzw $vf4, $vf4, Q");
    __asm__ volatile("vopmula.xyz ACC, $vf3, $vf4");
    __asm__ volatile("vopmsub.xyz $vf2, $vf4, $vf3");
    u128 *row = &D_0084AFF0[2];
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(row[0]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(row[-1]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(row[-2]));
    if (s->current == 0) {
        __asm__ volatile("vmove.xyzw $vf20, $vf28");
        __asm__ volatile("vmove.xyzw $vf21, $vf29");
        __asm__ volatile("vmove.xyzw $vf22, $vf30");
        __asm__ volatile("vmove.xyzw $vf23, $vf31");
    } else {
        __asm__ volatile("lqc2 $vf20, %0" : : "m"(s->matrix[0]));
        __asm__ volatile("lqc2 $vf21, %0" : : "m"(s->matrix[1]));
        __asm__ volatile("lqc2 $vf22, %0" : : "m"(s->matrix[2]));
        __asm__ volatile("lqc2 $vf23, %0" : : "m"(s->matrix[3]));
    }
    __asm__ volatile("vsub.xyz $vf23, $vf0, $vf23");
    __asm__ volatile("qmfc2.ni %0, $vf20" : "=r"(r0));
    __asm__ volatile("qmfc2.ni %0, $vf21" : "=r"(r1));
    __asm__ volatile("qmfc2.ni %0, $vf22" : "=r"(r2));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t0) : "r"(r1), "r"(r0));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t1) : "r"(r1), "r"(r0));
    __asm__ volatile("pextlw %0, $0, %1" : "=r"(t2) : "r"(r2));
    __asm__ volatile("pextuw %0, $0, %1" : "=r"(t3) : "r"(r2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r0) : "r"(t2), "r"(t0));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r1) : "r"(t0), "r"(t2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r2) : "r"(t3), "r"(t1));
    __asm__ volatile("qmtc2.ni %0, $vf20" : : "r"(r0));
    __asm__ volatile("qmtc2.ni %0, $vf21" : : "r"(r1));
    __asm__ volatile("qmtc2.ni %0, $vf22" : : "r"(r2));
    __asm__ volatile("vmulax.xyz ACC, $vf20, $vf23x");
    __asm__ volatile("vmadday.xyz ACC, $vf21, $vf23y");
    __asm__ volatile("vmaddz.xyz $vf23, $vf22, $vf23z");
    __asm__ volatile("sqc2 $vf20, %0" : "=m"(D_0084B020[0]));
    __asm__ volatile("sqc2 $vf21, %0" : "=m"(D_0084B020[1]));
    __asm__ volatile("sqc2 $vf22, %0" : "=m"(D_0084B020[2]));
    __asm__ volatile("vsub.xy $vf1, $vf0, $vf0");
    __asm__ volatile("vsubw.z $vf1, $vf0, $vf0w");
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf0x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf0y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf0z");
    __asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf0w");
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf1y");
    __asm__ volatile("vmaddz.xyzw $vf1, $vf22, $vf1z");
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(D_0084B050[0]));
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(up.q));
    func_0049F658(up.v.x, up.v.y, up.v.z);
}
