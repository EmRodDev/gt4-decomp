#include "spr.h"
typedef unsigned int u128 __attribute__((mode(TI)));

struct Scratch {
    unsigned char dirty;
    char pad[0xF9F];
    u128 matrix[4];
};

extern "C" void func_0049E480(Scratch *s);

/* Loads the scratchpad's matrix into VU0 vf20-vf23, refreshing it first when it is dirty. */
extern "C" void func_0049E3E0(void) {
    Scratch *s = (Scratch *)spr_base();
    if (s->dirty)
        func_0049E480(s);
    __asm__ volatile("vnop");
    __asm__ volatile("lqc2 $vf20, %0" : : "m"(s->matrix[0]));
    __asm__ volatile("lqc2 $vf21, %0" : : "m"(s->matrix[1]));
    __asm__ volatile("lqc2 $vf22, %0" : : "m"(s->matrix[2]));
    __asm__ volatile("lqc2 $vf23, %0" : : "m"(s->matrix[3]));
}
