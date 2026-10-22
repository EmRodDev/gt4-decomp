/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry {
    char pad0[0x8];
    char x[0x40];
    s32 y;
    char pad4C[0x1C];
};

struct G {
    char pad0[0xD4];
    s32 count;
    Entry e[1];
};

struct List {
    s32 count;
    s32 pad4;
    char **items;
};

struct Self {
    char pad0[0x60];
    List *list;
};

extern G *D_00622F4C;

static inline Entry *entry(G *g, s32 i) { return &g->e[i]; }

extern "C" void func_003C0700(Self *);
extern "C" s32 func_004443A8(void *, void *);
extern "C" s32 func_00445880(void *, s32);

extern "C" void func_00110938(Self *self) {
    s32 i;
    s32 m = D_00622F4C->count + 1;
    List *l = self->list;
    s32 n = l->count;
    if (m < n) n = m;
    i = 1;
    if (i < n) {
        for (;;) {
            char *c = l->items[i] + 0x20;
            func_004443A8(c, entry(D_00622F4C, i)->x);
            func_00445880(c, entry(D_00622F4C, i)->y);
            i++;
            if (i >= n) break;
            l = self->list;
        }
    }
    func_003C0700(self);
}
