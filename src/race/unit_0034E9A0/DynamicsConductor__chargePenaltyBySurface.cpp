/* GT4 car event handler. The car id from func_00359538 selects up to two
   per-car callbacks at self+0x10140 (entry 0x170 for idA, 0x178 for idB); the
   larger positive result is folded into r. The byte at car+0x104+0x4B6 is then
   set for r==2 (-1/0xFF), incremented for r==1, or cleared otherwise, and
   car+0x4B3 becomes 4 (idA ran) or 2 when that byte is non-zero. */
/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef int s32;
struct VEntry {
    short delta;
    short index;
    s32 (*fn)(char *);
};
struct Info { char pad0[1]; u8 id; };
extern "C" Info *func_00359538(void *);
extern "C" void DynamicsConductor__chargePenaltyBySurface(char *self, char *car, int idA, int idB) {
    u8 *p = (u8 *)car + 0x104;
    if (p[0x4B3] != 0)
        return;
    if (*(signed char *)(p + 0x466) != 0)
        return;
    int r = 0;
    int usedA = 0;
    int id = func_00359538(car)->id;
    if (idA == id) {
        char *v = *(char **)(self + 0x10140) + 0x170;
        usedA = 1;
        int x = ((VEntry *)v)->fn(self + ((VEntry *)v)->delta);
        if (x > 0) r = x;
    }
    if (idB == id) {
        char *v = *(char **)(self + 0x10140) + 0x178;
        int x = ((VEntry *)v)->fn(self + ((VEntry *)v)->delta);
        r = r < x ? x : r;
    }
    switch (r) {
    case 2:
        p[0x4B6] = -1;
        break;
    case 1:
        p[0x4B6] = p[0x4B6] + 1;
        break;
    default:
        p[0x4B6] = 0;
        break;
    }
    if (p[0x4B6] != 0) {
        if (!usedA)
            p[0x4B3] = 2;
        else
            p[0x4B3] = 4;
    }
}
