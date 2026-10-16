typedef unsigned int u32;
struct Data { int v[4]; };
struct Entry { int w[4]; Data data; };
struct State { char pad[0xF8]; u32 count; char padFC[0x1FC]; Entry entries[1024]; };
extern int D_0064AE00;
extern State *D_0064B4B4;
extern u32 D_00863670[64];
extern "C" int func_0051B310(int *out, int a, int b, int d, int c, const Data *data) {
    int total = 0;
    if (!out) return 0x17;
    if (b <= 0) return 0x17;
    if (c <= 0) return 0x17;
    int n = D_0064AE00;
    if (n >= 64) return 8;
    u32 count = D_0064B4B4->count;
    if (count >= 1024) return 8;
    for (int i = 0; i < n; ++i) {
        total += D_0064B4B4->entries[count - n + i].w[1] * D_0064B4B4->entries[count - n + i].w[2];
    }
    total += b * c;
    if ((u32)total >= 475) return 31;
    Entry *e = &D_0064B4B4->entries[D_0064B4B4->count];
    if (!e) return 10;
    e->w[0] = a;
    e->w[1] = b;
    e->w[3] = d;
    e->w[2] = c;
    if (data) e->data = *data;
    D_00863670[D_0064AE00] = D_0064B4B4->count;
    *out = D_0064AE00;
    ++D_0064AE00;
    ++D_0064B4B4->count;
    return 0;
}
