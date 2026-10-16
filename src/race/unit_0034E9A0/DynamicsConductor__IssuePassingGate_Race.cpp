/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;

struct DC {
    char pad0[0xCDEC];
    u32 H[16][6];
    char padCF6C[0xD3EC - 0xCF6C];
    s16 E[16];
    s8 F[16];
    char padD41C[0xD44C - 0xD41C];
    s8 G[16];
    char padD45C[0xD48C - 0xD45C];
    s8 I[16][6];
    char padD4EC[0xD60C - 0xD4EC];
    u32 A[6];
    u32 B[6][16];
    u32 C[6][16];
    s16 D[6][16];
};

extern "C" void RaceDisplayLapDiffEvent__structor_0(DC *, int, int);

extern "C" void DynamicsConductor__IssuePassingGate_Race(DC *o, int idx, int lap, int k, u32 t) {
    u32 d = t - o->A[idx];
    o->B[idx][k] = d;
    o->A[idx] = t;
    if (d < o->C[idx][k]) {
        o->C[idx][k] = d;
        o->D[idx][k] = lap;
    }
    s16 e = o->E[k];
    if (e < lap) {
        o->E[k] = lap;
        o->F[k] = 1;
        o->G[k] = 0;
        o->H[k][0] = t;
        o->I[k][0] = idx;
        return;
    }
    if (lap == e) {
        int f = o->F[k];
        int pos;
        if (f == o->G[k]) {
            pos = f;
        } else {
            pos = f;
            int start = o->G[k];
            while (start < pos && t < o->H[k][pos - 1])
                pos--;
            int n = o->F[k];
            while (pos < n) {
                o->H[k][n] = o->H[k][n - 1];
                n--;
            }
        }
        f = pos;
        o->H[k][f] = t;
        o->I[k][pos] = idx;
        o->F[k]++;
        return;
    }
    RaceDisplayLapDiffEvent__structor_0(o, idx, e - lap);
}
