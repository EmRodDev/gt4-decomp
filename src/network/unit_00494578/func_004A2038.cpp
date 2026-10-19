#include "spr.h"
/* Select the paired packet-chain flags used by the three transfer modes.
 * Unsupported modes leave the current chain untouched. Mode names provisional. */
extern "C" unsigned int *func_004A1F60(void *, unsigned int);
extern "C" unsigned int *func_004A1FA8(void *, unsigned int);
extern "C" void func_004A2038(unsigned int mode) {
    void *state = spr_base();
    unsigned int first, last;
    switch (mode) {
    case 0: first = 0x30000; last = 0x30000; break;
    case 1: first = 0x10000; last = 0x20000; break;
    case 2: first = 0x20000; last = 0x10000; break;
    default: return;
    }
    func_004A1F60(state, first);
    return (void)func_004A1FA8(state, last);
}
