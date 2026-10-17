/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Row {
    u128 q;
    f32 f[4];
};

struct Scratch {
    u8 dirty;
    u8 current;
    char pad2[0xED0 - 2];
    u128 matrix[4];
};

extern f32 D_0084AF80[4][4];
extern f32 D_0084AFC0[4];
extern f32 D_0084AFD0[4];
extern f32 D_0084AFE0[4];
extern f32 D_00624DA8;
extern f32 D_00624DAC;
extern f32 D_00624DB0;

extern "C" void func_0049F4C8(Scratch *s, f32 scale) {
    u64 r0, r1, r2, t0, t1, t2, t3;

    __asm__ volatile("vnop");
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
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(D_0084AFC0[0]));
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(D_0084AFD0[0]));
    __asm__ volatile("lqc2 $vf6, %0" : : "m"(D_0084AFE0[0]));
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf20x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf20y");
    __asm__ volatile("vmaddz.xyzw $vf1, $vf6, $vf20z");
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf21x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf21y");
    __asm__ volatile("vmaddz.xyzw $vf2, $vf6, $vf21z");
    __asm__ volatile("vmulax.xyzw ACC, $vf4, $vf22x");
    __asm__ volatile("vmadday.xyzw ACC, $vf5, $vf22y");
    __asm__ volatile("vmaddz.xyzw $vf3, $vf6, $vf22z");
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(*(u128 *)D_0084AF80[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(*(u128 *)D_0084AF80[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(*(u128 *)D_0084AF80[2]));
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
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf0x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf0y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf0z");
    __asm__ volatile("vmaddw.xyzw $vf1, $vf23, $vf0w");
    if (scale != 0.0f) {
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(1.0f / scale));
        __asm__ volatile("vmulx.xyzw $vf1, $vf1, $vf2x");
    }
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(*(u128 *)D_0084AF80[3]));
    D_0084AF80[0][3] = -0.125f;
    D_0084AF80[1][3] = D_00624DA8 + 0.875f;
    D_0084AF80[2][3] = D_00624DAC * -0x1.555554p-3f;
    D_0084AF80[3][3] = D_00624DB0 + 0.5f;
}
