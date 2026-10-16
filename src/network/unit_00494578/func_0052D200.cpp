struct Slot { unsigned short id; short pad; int f4, f8, f12; };
struct G { int first; Slot slot[16]; unsigned count; };
extern G D_00867FF8;
extern "C" int func_0052D200(Slot *a, int *out) {
    int r = 2;
    int best = 16;
    unsigned short id;
    if (!a->f4) return r;
    if (!a->f8) return r;
    if (!out) return r;
    id = a->id;
    if (!id) return r;
    r = 0xd301;
    if (D_00867FF8.count >= 16) return r;
    for (int i=0;i<16;i++) {
        unsigned short v = D_00867FF8.slot[i].id;
        if (a->id == v) { r=0xd301; return r; }
        if (!v) best = best == 16 ? i : best;
    }
    if (best != 16) {
        D_00867FF8.slot[best] = *a;
        unsigned count = D_00867FF8.count + 1;
        *out=D_00867FF8.first;
        D_00867FF8.count=count;
        return 0;
    }
    r=0xd301;
    return r;
}
