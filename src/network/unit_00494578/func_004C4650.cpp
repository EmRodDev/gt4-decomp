/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Entry {
    u8 *a;
    u8 *b;
    int size;
    u8 *c;
    u8 *d;
};

struct State {
    char pad[0x2c];
    struct Entry entry[1];
    char pad2[0xb1 - 0x40];
    u8 count;
};

struct Root {
    char pad[0x24];
    struct State *s;
};

extern struct Root *D_006452D4;

#define GET32(p) ((((p)[0] << 24) & 0xff000000) | (((p)[1] << 16) & 0xff0000) | (((p)[2] << 8) & 0xff00) | ((p)[3] & 0xff))

extern "C" int func_004C4650(u8 *p, long code)
{
    int i;
    int a, size, b, c, d;
    int v;

    v = GET32(p);
    if (v != (int)0x80000001) return 0x80004458;
    v = GET32(p + 0x1c);
    if (v != (int)code) return 0x80004458;
    for (i = 0; i < 1; i++) {
        if (D_006452D4->s->entry[i].a == 0) break;
    }
    if (i == 1) return 0x80004558;
    a = GET32(p + 8);
    size = GET32(p + 4);
    b = GET32(p + 12);
    c = GET32(p + 16);
    d = GET32(p + 24);
    D_006452D4->s->entry[i].a = p + a;
    D_006452D4->s->entry[i].b = p + b;
    D_006452D4->s->entry[i].size = size;
    D_006452D4->s->entry[i].c = p + c;
    D_006452D4->s->entry[i].d = p + d;
    D_006452D4->s->count++;
    return i;
}
