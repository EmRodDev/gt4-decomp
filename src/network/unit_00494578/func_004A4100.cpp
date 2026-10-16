/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long long u64;
struct Tex0 {
    u64 tbp:14, tbw:6, psm:6, tw:4, th:4, tcc:1, tfx:2, cbp:14, cpsm:4, csm:1, csa:5, cld:3;
};
struct Mip {
    u64 bp1:14, bw1:6, bp2:14, bw2:6, bp3:14, bw3:6, pad:4;
};
struct Spr {
    char pad[0x1C0];
    Tex0 tex0;
    Mip mip1;
    Mip mip2;
    u64 flags;
};
extern "C" void func_004A4AA8(Spr *);
extern "C" void func_004A4100(unsigned field, unsigned addr, unsigned psm, int width) {
    Spr *p = (Spr *)spr_base();
    switch (field) {
    case 0:
        p->tex0.tbp = addr >> 6;
        p->tex0.tbw = width >> 6;
        p->tex0.psm = psm;
        func_004A4AA8(p);
        p->flags |= 0x04000400;
        break;
    case 1:
        p->flags |= 0x08000800;
        p->mip1.bp1 = addr >> 6;
        p->mip1.bw1 = width >> 6;
        break;
    case 2:
        p->mip1.bp2 = addr >> 6;
        p->mip1.bw2 = width >> 6;
        p->flags |= 0x08000800;
        break;
    case 3:
        p->mip1.bp3 = addr >> 6;
        p->mip1.bw3 = width >> 6;
        p->flags |= 0x08000800;
        break;
    case 4:
        p->flags |= 0x10001000;
        p->mip2.bp1 = addr >> 6;
        p->mip2.bw1 = width >> 6;
        break;
    case 5:
        p->mip2.bp2 = addr >> 6;
        p->mip2.bw2 = width >> 6;
        p->flags |= 0x10001000;
        break;
    case 6:
        p->mip2.bp3 = addr >> 6;
        p->mip2.bw3 = width >> 6;
        p->flags |= 0x10001000;
        break;
    }
}
