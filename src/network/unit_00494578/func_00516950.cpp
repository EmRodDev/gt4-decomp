typedef unsigned int u32;
struct Size { int unk, width, height; };
struct Entry { int unk, count; char pad8[0x20]; struct Size *sizes[64]; int offsets[64]; };
struct Global { char pad[0x118]; int handle; char pad11c[0x81dc]; struct Entry entries[16]; };
struct Other { char pad[0x5c]; int value; };
struct Packet { unsigned char kind, index, b2, b3, b4; char pad5; short id; short zero; char pada[2]; int value, other; char name[0x210]; };
extern struct Global D_00854038;
extern char D_00853838[];
extern struct Other *D_0064B47C;
extern "C" int func_00516348(const char *, int, int) throw();
extern "C" int func_00536568(int);
extern "C" int func_00532588(int, int, int, int, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" char *func_005A609C(char *, const char *);

extern "C" int func_00516950(int *out, int unused, int a, int value, int b, int other, int c, char *source, const char *name, u32 index, u32 kind) {
    struct Packet p;
    struct Global *g;
    struct Entry *e;
    struct Entry *tab;
    int id, i, len, size;
    char *dst;

    if (out == 0) return 23;
    if (source == 0) return 23;
    if (name == 0) return 23;
    if (index >= 16) return 23;
    if (kind >= 64) return 23;
    g = &D_00854038;
    if (g->handle == 0) return 23;
    id = func_00516348(name, g->handle, kind);
    *out = id;
    if (id != -1) return 0;
    tab = g->entries;
    e = &tab[index];
    func_005A609C(p.name, name);
    p.id = id;
    p.kind = func_00536568(kind);
    p.index = index;
    p.b2 = b;
    p.b4 = a;
    p.b3 = c;
    p.zero = 0;
    p.value = D_0064B47C->value + value;
    p.other = other;
    dst = D_00853838;
    func_005A4724(dst, &p, 0x24);
    len = 0x24;
    for (i = 0; i < e->count; i++) {
        size = e->sizes[i]->width * e->sizes[i]->height;
        func_005A4724((void *)(len + (int)dst), source + e->offsets[i], size);
        len += size;
    }
    func_00532588(D_00854038.handle, kind, 4, len, D_00853838);
    return 0;
}
