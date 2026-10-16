/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long u64;
struct Bits { u64 low:12; u64 mode:2; u64 high:50; };
struct Spr { char pad[0x1A0]; Bits bits; char pad1A8[0x30]; u64 dirty; };
extern "C" void func_004A27C8(unsigned mode) {
    Spr *p = (Spr *)spr_base();
    p->bits.mode = mode;
    p->dirty |= 0x400040UL;
}
