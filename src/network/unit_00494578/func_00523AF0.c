typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Entry { s32 h; char pad[0x14]; } Entry;
typedef struct O2 {
    char pad0[0x84];
    s32 f84;
    Entry *f88;
    s32 f8C;
    s32 f90;
    s32 f94;
    s32 f98;
    char pad9C[0x1C];
    u16 fB8;
    char padBA[2];
    u32 fBC;
} O2;
void func_0052D2F8(u16);
s32 func_00538C68(void *);
void func_00523AF0(O2 *p) {
    if (p == 0) return;
    if (p->f88 != 0) {
        u32 i;
        for (i = 0; i < p->fBC; i++)
            func_00538C68(&p->f88[i]);
        func_00538C68(&p->f88);
        func_00538C68(&p->f98);
    }
    func_0052D2F8(p->fB8);
    func_00538C68(&p->f90);
    func_00538C68(&p->f94);
    func_00538C68(&p->f84);
    func_00538C68(&p);
}
