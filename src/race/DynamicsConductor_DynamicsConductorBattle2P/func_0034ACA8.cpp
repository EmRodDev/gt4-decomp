/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds the drivetrain model (GearSet) of a car from its parameter block, then derives the shift points. In order: the layout kind and
 * driven axle come from 0034BC98; each of the two differentials gets a type (0034AAD8 per axle byte) corrected by what the layout allows,
 * and the per-differential values (x14, x1C, x24) are scaled by type (9.8 factors suggest gravity-unit inputs, 0.01 factors percentages;
 * inferred). Gear ratios are the car's gear table in thousandths times the final drive (the value at +0x150 in thousandths, 4000 when below
 * 500; the role is inferred from the multiplication), with the reverse ratio negated, gear count capped at 9, and one of four adjustment modes
 * (+0x154) rescaling all, the upper or the middle gears. Mass, inverse mass and damping-like terms are read from the block (units of 0.001 and
 * 0.01), and the shift rpm for each gear is computed from the ratio between neighbouring gears (the rpm and 60/2pi conversion constants are in
 * hex float form). The two-element arrays (x90..xCC) are one per differential. The meaning of most x?? values is purpose unknown. */
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

extern "C" void func_0034ACA8(CarParam *carParams, GearSet *drivetrain, Engine *engine, int variant) {
    f32 value174[2];
    int diffFlags[2];
    DiffMap *diffMap;
    int i;
    int v;
    f32 finalDriveRatio;
    f32 overrideFactor;
    f32 reverseRatio;

    func_0034BC98(carParams, &drivetrain->kind, &drivetrain->f3, &drivetrain->value, &drivetrain->weight);
    for (unsigned int s = 0; s < 2; s++) {
        drivetrain->diff[s] = func_0034AAD8(carParams->x168[s]);
    }
    func_0034AC48(drivetrain->kind, diffFlags);
    for (int j = 0; j < 2; j++) {
        if (diffFlags[j]) {
            if (drivetrain->diff[j] == 0)
                drivetrain->diff[j] = 2;
        } else {
            if (drivetrain->diff[j] != 0)
                drivetrain->diff[j] = 0;
        }
    }

    diffMap = func_003594E8(func_003594E0(carParams));
    for (unsigned int t = 0; t < diffMap->n; t++) {
        if (diffMap->type[t] == 1) {
            int idx = diffMap->get(t);
            if (drivetrain->diff[idx] != 0)
                drivetrain->diff[idx] = 1;
        }
    }

    for (unsigned int s = 0; s < 2; s++) {
        switch (drivetrain->diff[s]) {
        case 0:
        case 1:
        case 2:
            drivetrain->x14[s] = 0.0f;
            drivetrain->x1C[s] = 0.0f;
            drivetrain->x24[s] = 0.0f;
            break;
        case 3:
        case 4:
            drivetrain->x14[s] = carParams->x16A[s] * 9.8f;
            drivetrain->x1C[s] = carParams->x16C[s] * 0.01f;
            drivetrain->x24[s] = carParams->x16E[s] * 0.01f;
            break;
        case 5: {
            f32 t = carParams->x16A[s];
            drivetrain->x14[s] = t * t;
            drivetrain->x1C[s] = carParams->x16C[s] * 0.1f * 9.8f;
            drivetrain->x24[s] = 0.0f;
            break;
        }
        case 6:
            drivetrain->x14[s] = carParams->x16A[s] * 9.8f;
            drivetrain->x1C[s] = carParams->x16C[s] * 0.01f;
            drivetrain->x24[s] = carParams->x16E[s] * 0.01f;
            break;
        case 7:
            drivetrain->x14[s] = carParams->x16A[s] * 0.01f;
            drivetrain->x1C[s] = carParams->x16C[s] * 0.01f;
            drivetrain->x24[s] = carParams->x16E[s] * 0.01f;
            break;
        }
    }

    func_0034ABC8(carParams, variant);
    drivetrain->n = carParams->x155;
    drivetrain->x12 = carParams->x158;
    switch (carParams->x158) {
    case 5:
        drivetrain->x12 = 2;
        break;
    case 6:
        drivetrain->x12 = 0;
        break;
    }
    if (drivetrain->n >= 10) {
        drivetrain->n = 9;
    } else if (drivetrain->x12 == 3 && drivetrain->n != 1) {
        drivetrain->n = 1;
    } else if (carParams->x158 == 1 && drivetrain->n < 2) {
        drivetrain->x12 = 0;
    }

    v = carParams->x150;
    v = v >= 500 ? v : 4000;
    finalDriveRatio = v * 0.001f;
    for (i = 0; i <= drivetrain->n; i++) {
        int x = carParams->gear[i];
        if (x < 100) {
            if (i >= 2) {
                drivetrain->n = i - 1;
                break;
            }
            x = i == 1 ? 4000 : 3500;
        }
        drivetrain->ratio[i] = x * 0.001f * finalDriveRatio;
    }
    reverseRatio = -drivetrain->ratio[0];
    drivetrain->ratio[0] = reverseRatio;

    if (carParams->x154 != 0 && carParams->x154 != 4 && carParams->x152 >= 500) {
        overrideFactor = carParams->x152 * 0.001f;
        switch (carParams->x154) {
        case 1:
            for (i = 0; i <= drivetrain->n; i++)
                drivetrain->ratio[i] *= overrideFactor;
            break;
        case 2:
            overrideFactor /= finalDriveRatio;
            drivetrain->ratio[0] = reverseRatio * overrideFactor;
            for (i = 5; i <= drivetrain->n; i++)
                drivetrain->ratio[i] *= overrideFactor;
            break;
        case 3:
            overrideFactor /= finalDriveRatio;
            drivetrain->ratio[0] = reverseRatio * overrideFactor;
            for (i = 3; i < 5; i++)
                drivetrain->ratio[i] *= overrideFactor;
            break;
        }
    }
    for (i = drivetrain->n + 1; i < 10; i++) {
    }

    for (int j = 0; j < 2; j++) {
        func_0034BA30(carParams, j, &drivetrain->x90[j], &drivetrain->xA0[j], &drivetrain->xA8[j]);
        if (drivetrain->x90[j] != 0.0f)
            drivetrain->x98[j] = 1.0f / drivetrain->x90[j];
    }
    drivetrain->f1 = 0;
    if (drivetrain->kind == 5 && drivetrain->x90[0] != drivetrain->x90[1])
        drivetrain->f1 = 1;
    if (carParams->x154 == 4)
        drivetrain->f1 = 1;

    for (int j = 0; j < 2; j++)
        value174[j] = carParams->x174[j] * 0.01f;
    for (int j = 0; j < 2; j++) {
        if (value174[j] != 0.0f) {
            drivetrain->xB4[j] = drivetrain->x90[j] / value174[j];
            drivetrain->xCC[j] = value174[j] * drivetrain->x98[j] * drivetrain->x98[j];
        }
    }
    drivetrain->mass = carParams->xB8 * 0.001f;
    if (carParams->xB8 != 0)
        drivetrain->xC8 = 1.0f / drivetrain->mass;
    for (int j = 0; j < 2; j++) {
        f32 k = carParams->x164[j] * 0.01f;
        if (drivetrain->f1 && j != drivetrain->f3)
            k *= drivetrain->x90[drivetrain->f3] / drivetrain->x90[j];
        k = k * finalDriveRatio + 2.0f * value174[j];
        drivetrain->xBC[j] = k;
    }
    drivetrain->xC4 = 1.0f / (drivetrain->xBC[0] + drivetrain->xBC[1]);
    drivetrain->x2C = carParams->x160 * 10;
    drivetrain->rpm[0] = carParams->xBE * 100;
    drivetrain->xB0 = carParams->x162 * 9.8f;
    for (i = 0; i <= drivetrain->n; i++)
        drivetrain->x68[i] = drivetrain->ratio[i] / drivetrain->x90[drivetrain->f3];

    if (func_003F1F98(drivetrain)) {
        drivetrain->x2C = engine->xCE;
    } else if (drivetrain->x2C - 100 < engine->xCE) {
        drivetrain->x2C = engine->xCE + 100;
    }
    for (i = 1; i < drivetrain->n; i++) {
        int x = (int)(drivetrain->rpm[0] * 0x1.acee9cp-4f * drivetrain->ratio[i + 1] / drivetrain->ratio[i] * 60.0f / 0x1.921fb4p+2f);
        if (D_00620CD8.x112 && i == 1)
            x = (drivetrain->x2C + x) / 2;
        x -= (int)(drivetrain->x68[i + 1] * 0x1.638e36p+1f * 60.0f / 0x1.921fb4p+2f);
        if (x < drivetrain->x2C + 500)
            x = drivetrain->x2C + 500;
        drivetrain->rpm[i] = x;
    }
    if (func_003F1F98(drivetrain)) {
        for (i = 2; i <= drivetrain->n; i++)
            drivetrain->ratio[i] /= drivetrain->ratio[1];
    }
    func_00367D90(drivetrain);
    if (carParams->x1 == 5)
        drivetrain->x13 = 4;
}
