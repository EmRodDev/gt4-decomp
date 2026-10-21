/* compiler: ee-gcc2.96-nsa-nogcse */
typedef unsigned short u16;
struct Slot { u16 id; char pad[14]; };
struct G { int first; Slot slot[16]; unsigned cnt; };
extern G D_00867FF8;
extern "C" int func_0052D390(u16 id, Slot **out) {
    unsigned best = 16;
    if (out == 0) return 2;
    *out = 0;
    unsigned i = 0;
    G *g = &D_00867FF8;
    if (id == 0) return 2;
    for (; i < 16; i++) {
        u16 v = ((g->slot) + i)->id;
        unsigned off = i * 16;
        if (id == v) {
            *out = (Slot *)(off + (unsigned)g->slot);
            return 0;
        }
        if (v != 0) {
            if (best == 16) best = i;
        }
    }
    if (*out == 0) {
        if (best != 16) *out = &D_00867FF8.slot[best];
    }
    return 0;
}
