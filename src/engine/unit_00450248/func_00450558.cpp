/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Sub {
    char pad[0x18];
    s32 f18;
};

struct Self {
    char pad[0x1C];
    Sub *f1C;
    s32 f20;
};

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" int func_00499728(void *);
extern "C" void func_0049CC38(s32);
extern "C" void func_0049CE40(s32);
extern "C" void func_0049CE88(s32);
extern "C" void func_0049CEA0(void);
extern "C" void func_0049E430(void);
extern "C" void func_004A1638(s32);
extern "C" int func_004A26F0(s32);
extern "C" void func_004A2750(s32, f32);
extern "C" void func_004A27C8(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004AB040(s32);

extern Vec4 D_00846590;

extern "C" void func_00450558(Self *self) {
    u128 r0, r1, r2, t0, t1, t2, t3;
    Vec4 *v;
    f32 inv;

    if (self == 0)
        return;
    func_004A1638(0x11);
    func_004AB040(0xF);
    func_004A1638(2);
    func_004A1638(8);
    func_004A1638(5);
    func_004A1638(4);
    func_004AB040(3);
    func_004A1638(6);
    func_004A26F0(3);
    func_004A2750(4, 1.0f);
    func_004A27C8(1);
    func_004A2808(0x44, 0.0f);

    __asm__ volatile("vnop");
    __asm__ volatile("vmr32.xyzw $vf5, $vf0");
    __asm__ volatile("vmr32.xyzw $vf6, $vf5");
    func_0049E430();
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
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf5x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf5y");
    __asm__ volatile("vmaddz.xyzw $vf5, $vf22, $vf5z");
    __asm__ volatile("vopmula.xyz ACC, $vf6, $vf5");
    __asm__ volatile("vopmsub.xyz $vf7, $vf5, $vf6");
    v = &D_00846590;
    __asm__ volatile("sqc2 $vf7, %0" : "=m"(*v));
    __asm__("rsqrt.s %0, %2, %1" : "=f"(inv) : "f"(v->x * v->x + v->z * v->z), "f"(1.0f));
    v->x *= inv;
    v->z *= inv;

    func_00499728(self->f1C);
    func_0049CC38((s32)func_0049CEA0);
    func_0049CE88(self->f1C->f18);
    func_0049CE40(self->f20);
}
