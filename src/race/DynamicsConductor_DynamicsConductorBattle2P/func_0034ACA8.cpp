/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef float f32;

struct CarParam {
    char pad0[1];
    u8 x1;
    char pad2[0xB8 - 2];
    u16 xB8;
    char padBA[4];
    u8 xBE;
    char padBF[0x138 - 0xBF];
    s16 gear[10];
    s16 x14C[2];
    s16 x150;
    s16 x152;
    u8 x154;
    u8 x155;
    u8 x156;
    u8 x157;
    u8 x158;
    char pad159[7];
    u8 x160;
    char pad161[1];
    u8 x162;
    char pad163[1];
    s16 x164[2];
    s8 x168[2];
    u8 x16A[2];
    u8 x16C[2];
    u8 x16E[2];
    char pad170[4];
    s16 x174[2];
};

struct GearSet {
    u8 kind;
    u8 f1;
    u8 n;
    u8 f3;
    f32 value;
    f32 weight;
    f32 mass;
    u8 diff[2];
    u8 x12;
    u8 x13;
    f32 x14[2];
    f32 x1C[2];
    f32 x24[2];
    u16 x2C;
    u16 rpm[9];
    f32 ratio[10];
    f32 x68[10];
    f32 x90[2];
    f32 x98[2];
    f32 xA0[2];
    f32 xA8[2];
    f32 xB0;
    f32 xB4[2];
    f32 xBC[2];
    f32 xC4;
    f32 xC8;
    f32 xCC[2];
};

struct Engine {
    char pad0[0xCE];
    u16 xCE;
};

struct DiffMap {
    char pad0[2];
    u8 n;
    char pad3[5];
    u8 type[8];
    u8 map[8];
    int get(int i) { return i < n ? map[i] : 0; }
};

struct Settings {
    char pad0[0x112];
    u8 x112;
};

extern Settings D_00620CD8;

extern "C" {
s8 func_0034AAD8(s8) throw();
void func_0034AC48(unsigned int, int *) throw();
int func_0034ABC8(CarParam *, int) throw();
u8 func_0034BC98(CarParam *, u8 *, u8 *, f32 *, f32 *);
u8 func_003594E0(CarParam *);
DiffMap *func_003594E8(int);
void func_0034BA30(CarParam *, int, f32 *, f32 *, f32 *);
int func_003F1F98(GearSet *);
void func_00367D90(GearSet *);
}

extern "C" void func_0034ACA8(CarParam *a, GearSet *b, Engine *c, int d) {
    f32 w[2];
    int flags[2];
    DiffMap *m;
    int i;
    int v;
    f32 scale;
    f32 f;
    f32 reverse;

    func_0034BC98(a, &b->kind, &b->f3, &b->value, &b->weight);
    for (unsigned int s = 0; s < 2; s++) {
        b->diff[s] = func_0034AAD8(a->x168[s]);
    }
    func_0034AC48(b->kind, flags);
    for (int j = 0; j < 2; j++) {
        if (flags[j]) {
            if (b->diff[j] == 0)
                b->diff[j] = 2;
        } else {
            if (b->diff[j] != 0)
                b->diff[j] = 0;
        }
    }

    m = func_003594E8(func_003594E0(a));
    for (unsigned int t = 0; t < m->n; t++) {
        if (m->type[t] == 1) {
            int idx = m->get(t);
            if (b->diff[idx] != 0)
                b->diff[idx] = 1;
        }
    }

    for (unsigned int s = 0; s < 2; s++) {
        switch (b->diff[s]) {
        case 0:
        case 1:
        case 2:
            b->x14[s] = 0.0f;
            b->x1C[s] = 0.0f;
            b->x24[s] = 0.0f;
            break;
        case 3:
        case 4:
            b->x14[s] = a->x16A[s] * 9.8f;
            b->x1C[s] = a->x16C[s] * 0.01f;
            b->x24[s] = a->x16E[s] * 0.01f;
            break;
        case 5: {
            f32 t = a->x16A[s];
            b->x14[s] = t * t;
            b->x1C[s] = a->x16C[s] * 0.1f * 9.8f;
            b->x24[s] = 0.0f;
            break;
        }
        case 6:
            b->x14[s] = a->x16A[s] * 9.8f;
            b->x1C[s] = a->x16C[s] * 0.01f;
            b->x24[s] = a->x16E[s] * 0.01f;
            break;
        case 7:
            b->x14[s] = a->x16A[s] * 0.01f;
            b->x1C[s] = a->x16C[s] * 0.01f;
            b->x24[s] = a->x16E[s] * 0.01f;
            break;
        }
    }

    func_0034ABC8(a, d);
    b->n = a->x155;
    b->x12 = a->x158;
    switch (a->x158) {
    case 5:
        b->x12 = 2;
        break;
    case 6:
        b->x12 = 0;
        break;
    }
    if (b->n >= 10) {
        b->n = 9;
    } else if (b->x12 == 3 && b->n != 1) {
        b->n = 1;
    } else if (a->x158 == 1 && b->n < 2) {
        b->x12 = 0;
    }

    v = a->x150;
    v = v >= 500 ? v : 4000;
    scale = v * 0.001f;
    for (i = 0; i <= b->n; i++) {
        int x = a->gear[i];
        if (x < 100) {
            if (i >= 2) {
                b->n = i - 1;
                break;
            }
            x = i == 1 ? 4000 : 3500;
        }
        b->ratio[i] = x * 0.001f * scale;
    }
    reverse = -b->ratio[0];
    b->ratio[0] = reverse;

    if (a->x154 != 0 && a->x154 != 4 && a->x152 >= 500) {
        f = a->x152 * 0.001f;
        switch (a->x154) {
        case 1:
            for (i = 0; i <= b->n; i++)
                b->ratio[i] *= f;
            break;
        case 2:
            f /= scale;
            b->ratio[0] = reverse * f;
            for (i = 5; i <= b->n; i++)
                b->ratio[i] *= f;
            break;
        case 3:
            f /= scale;
            b->ratio[0] = reverse * f;
            for (i = 3; i < 5; i++)
                b->ratio[i] *= f;
            break;
        }
    }
    for (i = b->n + 1; i < 10; i++) {
    }

    for (int j = 0; j < 2; j++) {
        func_0034BA30(a, j, &b->x90[j], &b->xA0[j], &b->xA8[j]);
        if (b->x90[j] != 0.0f)
            b->x98[j] = 1.0f / b->x90[j];
    }
    b->f1 = 0;
    if (b->kind == 5 && b->x90[0] != b->x90[1])
        b->f1 = 1;
    if (a->x154 == 4)
        b->f1 = 1;

    for (int j = 0; j < 2; j++)
        w[j] = a->x174[j] * 0.01f;
    for (int j = 0; j < 2; j++) {
        if (w[j] != 0.0f) {
            b->xB4[j] = b->x90[j] / w[j];
            b->xCC[j] = w[j] * b->x98[j] * b->x98[j];
        }
    }
    b->mass = a->xB8 * 0.001f;
    if (a->xB8 != 0)
        b->xC8 = 1.0f / b->mass;
    for (int j = 0; j < 2; j++) {
        f32 k = a->x164[j] * 0.01f;
        if (b->f1 && j != b->f3)
            k *= b->x90[b->f3] / b->x90[j];
        k = k * scale + 2.0f * w[j];
        b->xBC[j] = k;
    }
    b->xC4 = 1.0f / (b->xBC[0] + b->xBC[1]);
    b->x2C = a->x160 * 10;
    b->rpm[0] = a->xBE * 100;
    b->xB0 = a->x162 * 9.8f;
    for (i = 0; i <= b->n; i++)
        b->x68[i] = b->ratio[i] / b->x90[b->f3];

    if (func_003F1F98(b)) {
        b->x2C = c->xCE;
    } else if (b->x2C - 100 < c->xCE) {
        b->x2C = c->xCE + 100;
    }
    for (i = 1; i < b->n; i++) {
        int x = (int)(b->rpm[0] * 0x1.acee9cp-4f * b->ratio[i + 1] / b->ratio[i] * 60.0f / 0x1.921fb4p+2f);
        if (D_00620CD8.x112 && i == 1)
            x = (b->x2C + x) / 2;
        x -= (int)(b->x68[i + 1] * 0x1.638e36p+1f * 60.0f / 0x1.921fb4p+2f);
        if (x < b->x2C + 500)
            x = b->x2C + 500;
        b->rpm[i] = x;
    }
    if (func_003F1F98(b)) {
        for (i = 2; i <= b->n; i++)
            b->ratio[i] /= b->ratio[1];
    }
    func_00367D90(b);
    if (a->x1 == 5)
        b->x13 = 4;
}
