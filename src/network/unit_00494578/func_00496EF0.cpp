/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
#include "spr.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef u64 u64a __attribute__((aligned(4)));

/* Three floats read as one 64-bit and one 32-bit word. */
struct Point {
    u64a xy;
    u32 z;
};

struct Spr {
    char pad0[7];
    u8 field;
    char pad8[0x248 - 8];
    u32 xyz;
    char pad24C[0x26C - 0x24C];
    u16 offx;
    u16 offy;
};

extern "C" void func_0049E3E0(void);

/* Projects a point with the VU0 view matrix: screen x/y into sx/sy, packed z into the scratchpad; returns the depth. */
extern "C" f32 func_00496EF0(Point *in, f32 *sx, f32 *sy) {
    Spr *spr = (Spr *)spr_base();
    union {
        u128 q;
        f32 f[4];
    } proj;
    union {
        u128 q;
        s32 i[4];
    } fix;
    f32 div = 8.0f;
    u128 v;
    u64 xy;
    u32 z;
    f32 depth;

    if (spr->field == 0)
        div = 16.0f;
    func_0049E3E0();
    __asm__ volatile("vnop");
    z = in->z;
    xy = in->xy;
    __asm__("pcpyld %0, %1, %2" : "=r"(v) : "0"(z), "r"(xy));
    __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(v));
    __asm__ volatile("vmulax.xyzw ACC, $vf24, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf25, $vf1y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf26, $vf1z");
    __asm__ volatile("vmaddw.xyzw $vf1, $vf27, $vf0w");
    __asm__ volatile("vdiv Q, $vf0w, $vf1w");
    __asm__ volatile("vmini.xyzw $vf1, $vf1, $vf22");
    __asm__ volatile("vwaitq");
    __asm__ volatile("vmulq.xyzw $vf1, $vf1, Q");
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(proj.q));
    depth = proj.f[2];
    __asm__ volatile("vmulaw.xyzw ACC, $vf21, $vf0w");
    __asm__ volatile("vmadd.xyzw $vf1, $vf1, $vf20");
    __asm__ volatile("vftoi4.xyzw $vf1, $vf1");
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(fix.q));
    *sx = (f32)(fix.i[0] - spr->offx) * 0.0625f;
    *sy = (f32)(fix.i[1] - spr->offy) / div;
    fix.i[2] >>= 4;
    fix.i[3] >>= 4;
    spr->xyz = fix.i[3] << 24 | fix.i[2];
    return depth;
}
