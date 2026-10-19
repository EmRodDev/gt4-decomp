#include "types.h"
struct Header { u8 type, count; u16 id; };
struct Size { int x, w, h; };
struct Table { int x, n; char pad8[0x20]; Size *sizes[64]; int offsets[64]; };
struct Entry { u8 type; char pad1[3]; int handle; char pad8[0x14]; char *dst1, *dst2; char pad24[0x18]; int *times; };
struct Context { char pad[0x82f8]; Table tables[(0xe638 - 0x82f8) / 0x228]; char padE5F0[0xe638 - 0x82f8 - (0xe638 - 0x82f8) / 0x228 * 0x228]; signed char state[4096]; };
struct Timer { char pad[0x5c]; int time; };
extern Context *D_0064B4B4;
extern Timer *D_0064B47C;
extern "C" Entry *func_00515DD8(u32) throw();
extern "C" void func_00516030(int, int, u32) throw();
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" int func_0051A280(int unused0, int unused1, u32 arg2, Header *h) {
    if (arg2 >= 64) return -1;
    if (h->id >= 4096) return -1;
    Context **gp = &D_0064B4B4;
    Table *t;
    Size *size;
    u32 index, i;
    int total = 4;
    u8 *p = (u8 *)(h + 1);
    if ((*gp)->state[h->id] != 2) {
        t = &(*gp)->tables[h->type];
        for (i = 0; i < h->count; i++) {
            index = *p++;
            if ((int)index >= t->n) return -1;
            size = t->sizes[index];
            total++;
            if (!size) return -1;
            int bytes = size->w * size->h;
            p += bytes;
            total += bytes;
        }
    } else {
        Entry *e = func_00515DD8(h->id);
        if (!e) return -1;
        t = &(*gp)->tables[e->type];
        if (!t) return -1;
        for (i = 0; i < h->count; i++) {
            index = *p++;
            if ((int)index >= t->n) return -1;
            size = t->sizes[index];
            total++;
            if (!size) return -1;
            int offset = t->offsets[index];
            char *dst = e->dst2 + offset;
            func_005A4724(e->dst1 + offset, p, size->w * size->h);
            func_005A4724(dst, p, size->w * size->h);
            int bytes = size->w * size->h;
            e->times[index] = D_0064B47C->time;
            p += bytes;
            total += bytes;
            func_00516030(e->handle, h->id, index);
        }
    }
    return total;
}
