/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
#include "spr.h"
typedef unsigned int u128 __attribute__((mode(TI)));
/* Light selectors are 101..108. Vector parameters accept byte-aligned input;
 * scalar parameters read one float. Remaining light fields are provisional. */
struct Light { char unknown[0xD0]; };
struct Scratch { char unknown0[0x3E0]; Light lights[8]; };
struct __attribute__((packed)) VectorValue { unsigned long long low, high; };
static inline u128 loadVector(const void *value) {
    const VectorValue *v = (const VectorValue *)value;
    unsigned long long high = v->high;
    unsigned long long low = v->low;
    u128 result;
    /* This compiler cannot express the corresponding 128-bit integer shift. */
    __asm__ volatile("pcpyld %0,%2,%1" : "=r"(result) : "r"(low), "r"(high));
    return result;
}
extern "C" void func_004ABEC0(Scratch *, Light *, unsigned int, u128);
extern "C" void func_004ABE10(Scratch *, Light *, unsigned int, float);
extern "C" void func_004A5BF8(unsigned int selector, unsigned int parameter, const void *value) {
    Scratch *state = (Scratch *)spr_base();
    if (selector - 101 < 8) {
        switch (parameter) {
        case 0: case 1: case 4: case 5: case 13:
            func_004ABEC0(state, &state->lights[selector - 101], parameter, loadVector(value));
            break;
        case 6: case 7: case 8: case 9: case 10:
            func_004ABE10(state, &state->lights[selector - 101], parameter, *(const float *)value);
            break;
        }
    }
}
