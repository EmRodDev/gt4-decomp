/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned char u8;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Scratch {
    u8 dirty;
    u8 current;
    char pad2[0xED0 - 2];
    u128 matrix[3][4];
};

#define SPR ((Scratch *)spr_base())

/* Loads the view matrix (vf20-vf23) from the current matrix set. */
extern "C" void func_0049E430(void) {
    if (SPR->current == 0) {
        __asm__ volatile("vmove.xyzw $vf20, $vf28");
        __asm__ volatile("vmove.xyzw $vf21, $vf29");
        __asm__ volatile("vmove.xyzw $vf22, $vf30");
        __asm__ volatile("vmove.xyzw $vf23, $vf31");
    } else {
        __asm__ volatile("lqc2 $vf20, %0" : : "m"(SPR->matrix[0][0]));
        __asm__ volatile("lqc2 $vf21, %0" : : "m"(SPR->matrix[0][1]));
        __asm__ volatile("lqc2 $vf22, %0" : : "m"(SPR->matrix[0][2]));
        __asm__ volatile("lqc2 $vf23, %0" : : "m"(SPR->matrix[0][3]));
    }
}
