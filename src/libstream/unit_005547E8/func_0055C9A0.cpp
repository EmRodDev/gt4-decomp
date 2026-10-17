/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;
typedef unsigned short u16;
struct Slot {
    u64 mask;
    char pad08[0x12];
    u16 flags;          /* 0x1A */
    char pad1c[0x14];
    int id;             /* 0x30 */
    char pad34[4];
    int f38, f3C, f40, f44;
    char pad48[0x34];
    int f7C;
    char pad80[0x60];
};
struct Filter {
    char pad00[8];
    u64 mask;           /* 0x08 */
    int id;             /* 0x10 */
    int excluded;       /* 0x14 */
    int required;       /* 0x18 */
    int f1C, f20, f24, f28, f2C;
    int need;           /* 0x30 */
};
struct Table { char pad[0xA8]; Slot slots[0x30]; };
extern "C" void func_0055C9A0(Table *t, Filter *f, void (*cb)(Slot *, int), int arg, void (*post)(int)) {
    u64 mask = f->mask;
    if (mask != 0) {
        int need = f->need;
        Slot *s;
        if (need != 0) {
            s = t->slots;
            int excluded = f->excluded;
            int required = f->required;
            int i = 0;
            for (; i < 0x30; i++, s++) {
                if ((s->mask & mask) == 0) continue;
                int m = 0;
                if (s->id == f->id) m = 1;
                if (!(s->flags & excluded)) m |= 2;
                if (((s->flags & required) ^ required) == 0) m |= 4;
                if (s->f38 == f->f1C) m |= 8;
                if (s->f3C == f->f20) m |= 0x10;
                if (s->f40 == f->f24) m |= 0x20;
                if (s->f44 == f->f28) m |= 0x40;
                if ((s->f7C >> 4) == f->f2C) m |= 0x80;
                if ((need & m) == need) cb(s, arg);
            }
        } else {
            s = t->slots;
            for (int i = 0x2F; i >= 0; i--, s++) {
                if (s->mask & mask) cb(s, arg);
            }
        }
        if (post) post(arg);
    }
}
