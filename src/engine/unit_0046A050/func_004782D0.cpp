/* Calls func_00476B78(target, product) where the product is func_00477460() multiplied by func_00477460(arg1): two lookups of the
 * same routine, the second taking arg1. What func_00477460 returns (a float scale?) and what func_00476B78 does with it are unknown
 * (purpose unknown). func_00477460 is declared without a prototype because the original passes no visible argument the first time. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00476B78(s32, f32);                    /* extern */
f32 func_00477460(...);                             /* extern */

void func_004782D0(s32 target, s32 arg1) {
    f32 firstFactor;

    firstFactor = func_00477460();
    func_00476B78(target, firstFactor * func_00477460(arg1));
}

}
