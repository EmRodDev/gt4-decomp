/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
#include "vu_macros.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

/* $vfN.xyz stored to (p) as one 64-bit and one 32-bit word (no 16-byte alignment). */

/* Four floats read as two 64-bit words. */
struct Point4 {
    u64 xy;
    u64 zw;
} __attribute__((packed));

struct Shape {
    char pad0[3];
    s8 count;
    char pad4[0xC];
    Point4 points[7];
};

struct ShapeEntry {
    char pad0[0x20];
    Shape shape;
};

struct Body {
    char pad0[0x44];
    u8 shape;
};

extern ShapeEntry *D_006D6054;

/* Transforms the points of the body's shape by the VU0 matrix vf20-vf23 into out. */
extern "C" void func_003E3458(Body *body, VuVec3 *out) {
    Shape *s = &D_006D6054[body->shape].shape;
    int i;
    u128 v;
    u64 xy, zw;

    for (i = 0; i < s->count; i++) {
        xy = s->points[i].xy;
        zw = s->points[i].zw;
        __asm__("pcpyld %0, %1, %2" : "=r"(v) : "0"(zw), "r"(xy));
        __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(v));
        __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf1x");
        __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf1y");
        __asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf1z");
        __asm__ volatile("vmaddw.xyzw $vf1, $vf23, $vf1w");
        VU_GET_VEC3(1, out);
        out++;
    }
}
