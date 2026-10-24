/* compiler: ee-gcc2.96-alignlabels */
struct G { unsigned long long x0; unsigned long long x8; unsigned long long x10; unsigned short x18; char pad1a[2]; char x1C; char pad1d[0x43]; char x60; };
extern struct G D_00624CC0;

void func_0049DEF8(unsigned int id) {
    struct G *g = &D_00624CC0;
    switch (id) {
    case 0x1000: g->x1C = 0; break;
    case 0x1001: g->x60 = 0; break;
    case 0x1100: g->x18 &= ~0x8; break;
    case 0x1101: g->x18 &= ~0x10; break;
    case 0x1102: g->x18 &= ~0x20; break;
    case 0x1103: g->x18 &= ~0x40; break;
    case 0x1104: g->x18 &= ~0x80; break;
    case 0x1105: g->x0 &= ~0x1800000000ULL; break;
    case 0x1106: g->x8 &= ~0x20ULL; break;
    case 0x1107: g->x8 &= ~0x1C0ULL; break;
    case 0x1108: g->x10 &= 0xFFFFFFFFFF00000CULL; break;
    case 0x1109: g->x10 &= 0xFFFFF00000FFFFF3ULL; break;
    }
}
