/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32; typedef int s32;
struct Settings {
    union {
        unsigned char bytes[128];
        struct {
            char pad0[0x10]; unsigned char f10; char pad11[0xB];
            unsigned char f1C[2]; unsigned char f1E[2]; unsigned char f20[2]; char pad22[2];
            unsigned char f24[2]; char pad26[0xE];
            unsigned char f34[2]; unsigned char f36[2]; unsigned char f38[2]; char pad3A[2];
            unsigned char f3C[2][2]; unsigned char f40[2][2]; unsigned char f44[2][2]; char pad48[4];
            unsigned char f4C[2][2]; unsigned char f50[2][2]; unsigned char f54[2][2];
        };
    };
};
extern Settings D_00622110;
extern float D_00620270[];
extern "C" int func_00353938();
extern "C" void func_0035A818(void *, int, int);
extern f32 D_00620268;
extern f32 D_00843568;
extern f32 D_0084356C;
extern f32 D_00843574;
extern f32 D_00843570;
extern f32 D_00843578;
extern s32 D_0084357C;
extern s32 D_0084358C;
extern f32 D_00843580;
extern f32 D_00843584;
extern f32 D_00843588;
extern f32 D_00843590;
extern f32 D_00620248;
extern f32 D_0062024C;
extern f32 D_00620250;
extern f32 D_0062025C;
extern f32 D_00620260;
extern f32 D_00620264;
extern float D_00843538[];
extern float D_00843548[];
extern float D_00843558[];
extern float D_00843598[];
extern float D_008435A0[];
extern float D_008435A8[];
extern float D_008435B0[];
extern float D_008435B8[][2];
extern float D_008435C8[][2];
extern float D_008435D8[][2];
extern int D_008435E8[];
extern float D_008435F0[];
extern float D_008435F8[];
extern float D_00843600[][2];
extern float D_00843610[][2];
extern float D_00843620[][2];
extern "C" int func_00347A00(unsigned char *arg0) {
    unsigned char *p=D_00622110.bytes;
    float temp_f2, temp_f4, temp_f5;
    temp_f2 = 0x1.9000000000000p+6f / ((f32) p[0x14] * 0x1.e000000000000p+5f);
    D_00620270[0] = temp_f2;
    D_00620270[1] = (f32) (0x1.9000000000000p+6f / ((f32) p[0x15] * 0x1.e000000000000p+5f));
    D_00620270[2] = (f32) (0x1.9000000000000p+6f / ((f32) p[0x16] * 0x1.e000000000000p+5f));
    D_00620270[3] = (f32) (0x1.9000000000000p+6f / ((f32) p[0x17] * 0x1.e000000000000p+5f));
    D_00620270[4] = (f32) (0x1.9000000000000p+6f / ((f32) p[0x18] * 0x1.e000000000000p+5f));
    D_00620270[5] = (f32) (0x1.9000000000000p+6f / ((f32) p[0x19] * 0x1.e000000000000p+5f));
    if (temp_f2 > 0x1.0000000000000p+0f) {
        D_00620270[0] = 0x1.0000000000000p+0f;
    }
    if (D_00620270[1] > 0x1.0000000000000p+0f) {
        D_00620270[1] = 0x1.0000000000000p+0f;
    }
    if (D_00620270[2] > 0x1.0000000000000p+0f) {
        D_00620270[2] = 0x1.0000000000000p+0f;
    }
    if (D_00620270[3] > 0x1.0000000000000p+0f) {
        D_00620270[3] = 0x1.0000000000000p+0f;
    }
    if (D_00620270[4] > 0x1.0000000000000p+0f) {
        D_00620270[4] = 0x1.0000000000000p+0f;
    }
    if (D_00620270[5] > 0x1.0000000000000p+0f) {
        D_00620270[5] = 0x1.0000000000000p+0f;
    }
    D_00620268 = (f32)p[4] * 0x1.47ae14p-7f;
    D_00843568 = (f32)p[0x27] * 0x1.47ae14p-7f;
    D_0084356C = (f32)p[0x23] * 0x1.47ae14p-7f;
    D_00843570 = (f32)p[0x29] * 0x1.47ae14p-7f;
    D_00843574 = temp_f4 = (f32)(p[0x2a]*10)*0x1.1c71c6p-2f;
    D_00843578 = temp_f5 = (f32)(p[0x2b]*10)*0x1.1c71c6p-2f;
    if (temp_f4 < 0x1.638e360000000p+1f) {
        D_00843574 = 0x1.638e360000000p+1f;
    }
    if (temp_f5 < 0x1.638e360000000p+1f) {
        D_00843578 = 0x1.638e360000000p+1f;
    }
    D_0084357C = (s32) p[0x2C];
    if (arg0[0xCBDE] == 2) {
        D_0084357C = 0;
    }
    D_00843580 = (f32) p[0x2D] * 0x1.9999980000000p-4f;
    D_00843584 = (f32) (signed char)p[0x2E] * 0x1.47ae140000000p-7f;
    D_00843588 = (f32) p[0x2F] * 0x1.c9870a0000000p-10f;
    D_0084358C = (s32) p[0x30];
    if (p[0x31] == 0) {
        D_00843590 = 0x1.921fb40000000p+2f;
    } else {
        D_00843590 = (f32) ((f32) p[0x31] * 0x1.1df4680000000p-6f);
    }
    Settings *st = (Settings *)p;
    for (int i = 0; i < 2; i++) {
        D_00843598[i] = st->f1C[i];
        D_008435A0[i] = st->f1E[i];
        D_008435A8[i] = st->f20[i];
        if (!st->f10) D_008435A8[i] = 0;
        D_008435B0[i] = st->f24[i] * 0x1.999998p-4f;
        for (int j = 0; j < 2; j++) {
            D_008435B8[i][j] = st->f3C[i][j] * 0x1.1df468p-6f;
            D_008435C8[i][j] = st->f40[i][j] * 0x1.1df468p-6f;
            D_008435D8[i][j] = st->f44[i][j] * 0x1.1df468p-6f;
        }
        D_008435E8[i] = st->f34 != 0;
        if (st->f36[i] >= st->f38[i]) D_008435E8[i] = 0;
        D_008435F0[i] = st->f36[i] * 0x1.1c71c6p-2f;
        D_008435F8[i] = st->f38[i] * 0x1.1c71c6p-2f;
        for (int j = 0; j < 2; j++) {
            D_00843600[i][j] = st->f4C[i][j] * 0x1.1df468p-6f;
            D_00843610[i][j] = st->f50[i][j] * 0x1.1df468p-6f;
            D_00843620[i][j] = st->f54[i][j] * 0x1.1df468p-6f;
        }
    }
    D_00620248 = (f32) p[0x5C] * 0x1.1df4680000000p-6f;
    D_0062024C = (f32) p[0x5D] * 0x1.1df4680000000p-6f;
    D_00620250 = (f32) p[0x5E] * 0x1.1df4680000000p-6f;
    if (p[0x61] == 0) {
        D_0062025C = 0x1.0000000000000p-12f;
    } else {
        D_0062025C = (f32) (0x1.c200000000000p+9f / ((f32) (p[0x61] * 0x3C) * 0x1.0000000000000p+12f));
    }
    if (p[0x64] == 0) {
        D_00620260 = 0x1.0000000000000p-12f;
    } else {
        D_00620260 = 0x1.c200000000000p+9f / ((f32) (p[0x64] * 0x3C) * 0x1.0000000000000p+12f);
    }
    if (p[0x62] == 0) {
        D_00620264 = 0x1.0000000000000p-12f;
    } else {
        D_00620264 = 0x1.c200000000000p+9f / ((f32) (p[0x62] * 0x3C) * 0x1.0000000000000p+12f);
    }
    func_0035A818(D_00843538, p[0x65], p[0x66]);
    func_0035A818(D_00843548, p[0x6C], p[0x6D]);
    func_0035A818(D_00843558, p[0x70], p[0x71]);
    return func_00353938();
}
