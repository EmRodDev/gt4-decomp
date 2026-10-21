/* compiler: ee-gcc2.9-991111 */
typedef struct Pkt {
    unsigned char type;
    char pad1[0xB];
    void *unkC;
    char pad10[0x8];
    unsigned flags;
    char pad1C[4];
    int unk20;
    void *unk24;
    char pad28[4];
    int unk2C;
    char pad30[0x10];
} Pkt;
typedef struct Gl {
    int id;
    int pad4;
    int sem8;
    int semC;
    Pkt *cur;
} Gl;

extern Gl D_0087E180;
extern Pkt D_00875900;
extern char D_00875940[0x400];
extern char D_00875D40[0x400];

extern int func_005AE770(void);
extern int func_005ADB90(void);
extern int func_005ADCF0(int);
extern int func_005ADCE0(int);
extern void func_005ADCC0(int);
extern int func_005ADBD0(int);
extern int func_00587C08(Pkt *);
extern void *func_005A4724(void *, const void *, unsigned);
extern void func_005A6AB0(void *, void *, int);

int func_005878F8(Pkt *p, int flag)
{
    unsigned w;
    unsigned a0;
    unsigned b;
    unsigned a1;
    Pkt *old;
    int ret;
    Pkt *g;
    int n;

    if (D_0087E180.id < 0) {
        return 0x81058001;
    }
    if (func_005AE770() != 0) {
        return 0x81058007;
    }
    if (p->type < 4 || p->type == 9) {
        w = p->flags;
        a0 = w & 0xF000;
        b = w & 0xF00;
        if ((w & 0xFF) >= 3) {
            return 0x81050016;
        }
        if (b != 0 && b != 0x100 && b != 0x200) {
            return 0x81050016;
        }
        a1 = a0 & 0x6000;
        if ((a0 & 0x8000) || a1 == 0x6000) {
            return 0x81050016;
        }
        if (a0 != 0 && b != 0) {
            return 0x81050016;
        }
        if ((p->type == 1 || p->type == 3) && a1 == 0) {
            return 0x81050001;
        }
    }
    if (func_005ADB90() == D_0087E180.id) {
        if (flag != 0) {
            return 0x81050086;
        }
        old = D_0087E180.cur;
        D_0087E180.cur = p;
        func_00587C08(p);
        D_0087E180.cur = old;
        ret = p->unk2C;
    } else if (flag != 0) {
        if (func_005ADCF0(D_0087E180.sem8) < 0) {
            return 0x81050010;
        }
        D_00875900 = *p;
        g = &D_00875900;
        if (g->unkC != 0) {
            func_005A6AB0(D_00875940, g->unkC, 0x400);
            g->unkC = D_00875940;
        }
        n = g->unk20;
        if (n > 0) {
            if (n > 0x400) {
                n = 0x400;
                g->unk20 = n;
            }
            func_005A4724(D_00875D40, g->unk24, n);
            g->unk24 = D_00875D40;
        }
        ret = 0;
        D_0087E180.cur = &D_00875900;
        func_005ADBD0(D_0087E180.id);
    } else {
        func_005ADCE0(D_0087E180.sem8);
        D_0087E180.cur = p;
        func_005ADBD0(D_0087E180.id);
        func_005ADCE0(D_0087E180.semC);
        ret = p->unk2C;
        D_0087E180.cur = 0;
        func_005ADCC0(D_0087E180.sem8);
    }
    return ret;
}
