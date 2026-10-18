/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
struct Src {
    char pad0[0x18];
    int f18, f1C, f20;
    char pad24[4];
    u64 flags;
    int f30;
    char pad34[0x5C - 0x34];
    int f5C;
};
struct Voice {
    u64 id;
    char pad8[8];
    Src *owner;
    char pad14[0x1F - 0x14];
    u8 b1F, b20;
    char pad21[0x2A - 0x21];
    u8 b2A;
    char pad2B;
    u8 b2C, b2D, b2E;
    char pad2F[0x38 - 0x2F];
    int f38, f3C;
    char pad40[4];
    int f44;
    char pad48[4];
    int f4C;
    char pad50[4];
    int f54;
    char pad58[8];
    int f60;
    char pad64[4];
    int f68;
    char pad6C[8];
    int f74, f78, f7C, f80, f84;
    char pad88[4];
    int f8C;
    char pad90[2];
    u16 h92, h94;
};
struct Hdr {
    char pad0[1];
    u8 b1;
    u8 b2;
    signed char b3;
    u8 flags;
    u8 b5;
    char pad6[2];
    u16 h8, hA;
    u8 bC;
    char padD;
    u8 bE, bF;
};
extern "C" {
int func_005599D0(int, Hdr *);
int func_005599F8(int, int);
int func_00559A88(int, int);
void func_0055D680(Voice *, int);
void func_0055D6D0(Voice *);
}
extern "C" void func_0055A8B0(Src *o, Voice *v, int a2, int a3, int t0, Hdr *t1, Hdr *t2) {
    v->owner = o;
    v->f3C = o->f5C;
    v->f38 = o->f30;
    v->f44 = a2;
    v->f74 = o->f20;
    v->b2C = 1;
    int volume = t1->b1 * t2->bC;
    int f18 = o->f18;
    v->f4C = f18;
    v->f54 = volume;
    v->b1F = 1;
    v->f60 = func_005599F8(o->f30, t0);
    v->b1F = 1;
    /* One scratch local for the 0x68 and 0x80 values (retail allocates them as one variable). */
    int value = o->f1C;
    v->f68 = value;
    value = t2->b3;
    int b2 = t2->b2 * 16;
    v->f80 = value;
    v->f78 = b2;
    v->b20 = 1;
    v->f7C = a3 * 16;
    v->f8C = func_005599D0(o->f30, t2);
    v->b2A = 1;
    v->h92 = t2->h8;
    v->b2D = 1;
    v->h94 = t2->hA;
    v->b2E = 1;
    u8 fl = t2->flags;
    int a;
    if (!(fl & 0x40)) a = t2->bF; else a = t1->b5;
    if (a != 0x7F) {
        int p = func_00559A88(o->f30, a);
        if (p != 0) func_0055D680(v, p);
        fl = t2->flags;
    }
    if (fl & 0x10) {
        v->f84 = t1->flags;
        v->b20 = 1;
    } else {
        v->f84 = t2->bE;
        v->b20 = 1;
    }
    func_0055D6D0(v);
    u64 id = v->id;
    o->flags |= id;
}