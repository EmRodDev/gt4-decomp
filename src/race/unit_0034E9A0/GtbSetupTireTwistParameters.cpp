/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;

struct TireSrc {
    char pad0[0xB];
    u8 count;               /* 0xB */
    u8 a[8];                /* 0xC */
    u8 b[8];                /* 0x14 */
    u8 c[0x18];             /* 0x1C */
    s16 h[0x18];            /* 0x34 */
    u8 d[0x18];             /* 0x64 */
    u8 e[0x18];             /* 0x7C */
    u8 f[0x18];             /* 0x94 */
};
struct TireDst {
    char pad0[0xC];
    float x[8];             /* 0xC */
    float y[8];             /* 0x2C */
    float z[0x18];          /* 0x4C */
    float w[0x18];          /* 0xAC */
    float v[0x18];          /* 0x10C */
    u8 o1[0x18];            /* 0x16C */
    u8 o2[0x18];            /* 0x184 */
};
extern TireDst D_00620938;
extern TireSrc D_00620CD8;

extern "C" void func_003F2F78(void);
extern "C" int func_00359A38(TireDst *, int, float *, float *, u8 *, u8 *) throw();
extern "C" int func_0034C998(void *);

extern "C" void GtbSetupTireTwistParameters(void *car) {
    int i;
    func_003F2F78();
    int n = D_00620CD8.count;
    for (i = 0; i < n; i++) {
        D_00620938.x[i] = (float)(D_00620CD8.a[i] * 2) * 0x1.1c71c6p-2f;
        D_00620938.y[i] = (float)D_00620CD8.b[i] * 0x1.0624dcp-10f;
    }
    func_00359A38(&D_00620938, n, D_00620938.x, D_00620938.y, 0, 0);
    if (car != 0) {
        for (i = 0; i < 0x18; i++) {
            int k = i;
            if (car != 0 && func_0034C998(car) == 2) k = (i == 5) ? 15 : i;
            D_00620938.z[i] = (float)D_00620CD8.h[k] * 0.01f;
            D_00620938.w[i] = (float)D_00620CD8.c[k] * 0x1.0624dcp-10f;
            D_00620938.v[i] = 0x1.921fb4p+2f / ((float)D_00620CD8.d[k] * 0x1.999998p-4f);
            D_00620938.o1[i] = D_00620CD8.e[k];
            D_00620938.o2[i] = D_00620CD8.f[k];
        }
    }
}
