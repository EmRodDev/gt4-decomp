/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned int u32;
typedef unsigned long long u64;
struct Quad { u32 w0; u32 w4; u64 reg; };
#define SET64(dst, val, addr) do { u64 data = (val); u64 reg = (addr); Quad *q = (dst); q->reg = reg; *(u64 *)q = data; } while (0)
#define SET32(dst, low, high, addr) do { Quad *q = (dst); q->w0 = (low); q->w4 = (high); q->reg = (addr); } while (0)
struct Spr {
    char p0[0x4A]; unsigned short flags4A; char p4C[0x1F8 - 0x4C];
    char *cur; char p1FC[0x248 - 0x1FC]; u32 u248; char p24C[0x26C - 0x24C];
    unsigned short x26C; unsigned short y26E; char p270[0x288 - 0x270];
    int offX; int offY; char p290[0xC20 - 0x290]; u32 uC20;
};
extern "C" void func_0049FE28() throw();
extern "C" void func_004A6140(int x0, int w, int x1, int h) {
    Spr *s = (Spr *)spr_base();
    int ox = s->offX;
    int shift = (((unsigned char *)s)[7] != 0) ? 3 : 4;
    u32 la = s->x26C + (x0 + ox) * 16;
    u32 lb = s->x26C + (x1 + ox) * 16;
    u32 a = (s->y26E + s->offY * 16 + (w << shift)) << 16 | la;
    u32 b = (s->y26E + s->offY * 16 + (h << shift)) << 16 | lb;
    func_0049FE28();
    u32 *p = (u32 *)s->cur;
    p[0] = 0x10000005;
    p[2] = 0x11000000;
    p[3] = 0x50000005;
    p[1] = 0;
    Quad *q0 = (Quad *)(p + 4);
    u64 fl = (s->flags4A | 6) & 0xffef;
    s->cur += 0x60;
    SET64(q0, 0x1000000000008004ULL, 0xE);
    SET32((Quad *)(p + 8), s->uC20, 0x3f800000, 1);
    SET64((Quad *)(p + 12), fl, 0);
    SET32((Quad *)(p + 16), a, s->u248, 0xC);
    SET32((Quad *)(p + 20), b, s->u248, 4);
}
