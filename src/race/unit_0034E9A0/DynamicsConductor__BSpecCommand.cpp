/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

struct DynamicsConductor {
    char pad0[0xCDEC];
    int w[4][16][6];        /* 0xCDEC */
    s16 h[16];              /* 0xD3EC */
    u8 a[4][16];            /* 0xD40C */
    u8 b[4][16];            /* 0xD44C */
    char padD48C[0xD60C - 0xD48C];
    int x[6];               /* 0xD60C */
    int p[6][16];           /* 0xD624 */
    int q[6][16];           /* 0xD7A4 */
    s16 r[6][16];           /* 0xD924 */
    u16 cnt[6];             /* 0xD9E4 */
    u16 hw[6][4];           /* 0xD9F0 */
    u8 pr[6][8];            /* 0xDA20 */
    char padDA50[0xF898 - 0xDA50];
    int f898;
    int f89c;
};

extern "C" void func_003F10E8(DynamicsConductor *self);

extern "C" void DynamicsConductor__BSpecCommand(DynamicsConductor *self) {
    int i, j, k;

    self->f898 = 0;
    self->f89c = 0;
    func_003F10E8(self);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            for (k = 0; k < 6; k++) self->w[i][j][k] = 0x157529FF;
            self->h[j] = -1;
            self->a[i][j] = 0;
            self->b[i][j] = 0;
        }
    }
    for (j = 0; j < 6; j++) {
        self->x[j] = 0;
        for (k = 0; k < 16; k++) {
            self->p[j][k] = 0x157529FF;
            self->q[j][k] = 0x157529FF;
            self->r[j][k] = -1;
        }
        self->cnt[j] = 0;
        for (k = 0; k < 4; k++) {
            self->hw[j][k] = 0xFFFF;
            self->pr[j][k * 2] = 0xFF;
            self->pr[j][k * 2 + 1] = 0xFF;
        }
    }
}
