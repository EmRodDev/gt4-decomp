/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long u64;
struct Bits { u64 low:32; u64 off:1; u64 high:31; };
struct Spr { char pad[0x188]; Bits bits; char pad190[0x48]; u64 dirty; char pad1E0[0xF4]; unsigned char off, active; };
extern "C" void func_004A29A8(unsigned char on) {
    Spr *p = (Spr *)spr_base();
    p->off = !on;
    if (p->active) {
        unsigned char off = p->off;
        u64 dirty = p->dirty;
        p->bits.off = off;
        p->dirty = dirty | 0x80008UL;
    }
}
