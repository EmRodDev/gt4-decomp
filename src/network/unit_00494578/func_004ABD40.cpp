/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef float f32;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Spr {
    char pad0[0x48];
    unsigned short flags;
    char pad4A[0xAA0 - 0x4A];
    f32 level;
};

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

extern "C" void func_004ABCE0(Spr *m, int unused, unsigned int which, u64 v) throw();

extern "C" void func_004ABD40(int flag, unsigned int which, u32 value) {
    Spr *p = (Spr *)spr_base();
    if (flag & 1) {
        if (which == 11) {
            p->level = minf(maxf((f32)value, 0.0f), 128.0f);
            p->flags |= 4;
        } else {
            u64 v;
            __asm__ volatile("pextlb %0, $0, %1" : "=r"(v) : "r"(value));
            __asm__ volatile("pextlh %0, $0, %1" : "=r"(v) : "r"(v));
            __asm__ volatile("vnop");
            __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(v));
            __asm__ volatile("vitof0.xyzw $vf1, $vf1");
            v = 0x3B808081;
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(v));
            __asm__ volatile("vmulx.xyzw $vf1, $vf1, $vf2x");
            __asm__ volatile("qmfc2.ni %0, $vf1" : "=r"(v));
            return func_004ABCE0(p, 1, which, v);
        }
    }
}
