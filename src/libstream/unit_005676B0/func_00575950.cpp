typedef unsigned int u32;
struct Blk {
    u32 w0;
    Blk *f4;
};
struct Ent {
    u32 f0;
    Blk *blk;
};
struct Obj {
    char p0[0x34];
    Blk *f34;
    char p1[8];
    Blk *f40;
    Blk *f44;
    char p2[4];
    Ent *f4C;
    int f50;
};
extern "C" void func_00575A78(void);
extern "C" int func_005A47D4(void *, void *, int);
extern "C" void func_00575950(Obj *self) {
    Blk *last = 0;
    func_00575A78();
    Ent *e = self->f4C;
    self->f40 = 0;
    Blk *cur = self->f34;
    Ent *end = e + self->f50;
    do {
        Blk *blk = e->blk;
        if (blk != 0) {
            u32 hdr = blk->w0;
            if (cur != blk) {
                if (hdr & 1) {
                    cur->f4 = 0;
                    cur->w0 = (u32)((char *)blk - (char *)cur) - 4;
                    if (last == 0) {
                        self->f40 = cur;
                    } else {
                        last->f4 = cur;
                    }
                    last = cur;
                    cur = blk;
                } else {
                    func_005A47D4(cur, blk, hdr + 4);
                    e->blk = cur;
                }
            }
            cur = (Blk *)((char *)cur + ((cur->w0 >> 2) << 2) + 4);
        }
        e++;
    } while (e != end);
    self->f44 = cur;
}
