/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u128 __attribute__((mode(TI)));

/* The scratchpad's three saved VU0 matrix sets (vf28-vf31 and vi13). */
struct Spr {
    char pad0;
    u8 current;
    char pad2[0xECE];
    u128 matrix[3][4];
    u16 vi13[3];
};

/* Makes matrix set `index` current: saves vf28-vf31/vi13 into the current set, loads the other. */
extern "C" void RaceEntryCar__update(int index) {
    Spr *s = (Spr *)spr_base();
    long current;
    int vi;
    u128 *save;
    u128 *load;

    int old = s->current;
    if (old == index)
        return;
    __asm__ volatile("cfc2.i %0, $vi13" : "=r"(vi));
    current = old;
    if (current == 0) {
        s->vi13[0] = vi;
        save = s->matrix[0];
    } else if (current == 1) {
        s->vi13[1] = vi;
        save = s->matrix[1];
    } else {
        s->vi13[2] = vi;
        save = s->matrix[2];
    }
    if (index == 0) {
        load = s->matrix[0];
        vi = s->vi13[0];
    } else if (index == 1) {
        load = s->matrix[1];
        vi = s->vi13[1];
    } else {
        load = s->matrix[2];
        vi = s->vi13[2];
    }
    __asm__ volatile("sqc2 $vf28, %0" : "=m"(save[0]));
    __asm__ volatile("sqc2 $vf29, %0" : "=m"(save[1]));
    __asm__ volatile("sqc2 $vf30, %0" : "=m"(save[2]));
    __asm__ volatile("sqc2 $vf31, %0" : "=m"(save[3]));
    __asm__ volatile("lqc2 $vf28, %0" : : "m"(load[0]));
    __asm__ volatile("lqc2 $vf29, %0" : : "m"(load[1]));
    __asm__ volatile("lqc2 $vf30, %0" : : "m"(load[2]));
    __asm__ volatile("lqc2 $vf31, %0" : : "m"(load[3]));
    __asm__ volatile("ctc2.i %0, $vi13" : : "r"(vi));
    s->current = index;
}
