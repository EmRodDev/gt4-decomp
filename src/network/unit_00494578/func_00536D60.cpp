struct Ent { char pad[4]; int f4; char pad8[0x1C]; unsigned f24; unsigned f28; };
struct Y { char pad[0x104]; int f104; };
extern "C" Ent *lookup(unsigned) throw();
struct Obj { char pad[0x28]; __typeof__(lookup) *f28; char pad2[0xEC]; Y *f118; };
extern Obj *D_0064B4B4;
extern "C" int func_00536D60(unsigned a, int b) {
    int ok1 = a < 0x1000;
    if (!ok1) return 0x17;
    int ok2 = (unsigned)b < 0x40;
    if (!ok2) return 0x17;
    {
        Obj *o = D_0064B4B4;
        Y *y = o->f118;
        if (y == 0) return 0;
        Ent *e = o->f28(a);
        if (e == 0) return 10;
        int t = e->f4;
        if (t != -1) {
            if (t != y->f104) return 8;
        }
        unsigned *p = &e->f28;
        if (b >= 0x20) {
            p = &e->f24;
            b = b / 2;
        }
        *p |= 1 << b;
        return 0;
    }
}
