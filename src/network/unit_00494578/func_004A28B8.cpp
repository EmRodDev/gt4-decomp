/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long long u64;
struct Bits { u64 low : 1; u64 a : 3; u64 b : 8; u64 rest : 20; u64 high : 32; };
struct Spr {
    char pad0[0x1a0];
    Bits bits;
    char pad1[0x1d8-0x1a8];
    u64 flags;
};
extern "C" void func_004A28B8(int x, int y) {
    Spr *p = (Spr *)spr_base();
    u64 flags = p->flags;
    p->bits.a = x;
    p->bits.b = y;
    p->flags = flags | 0x400040;
}
