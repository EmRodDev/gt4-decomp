/* compiler: ee-gcc2.96-nogcse */
typedef unsigned short u16;
typedef signed char s8;
extern s8 D_006CB170[];
extern s8 D_006CB3F0[];
extern s8 D_006CB530[];
extern s8 D_006CB670[];
extern s8 D_006CB7B0[];
extern "C" unsigned func_00567B38(int, int);

extern "C" void func_0056D738(u16 *out, int n, int rng) {
    u16 *p = out;
    /* One row index for all five tables (retail keeps it in one variable). */
    unsigned row;
    for (int i = 0; i < n; i++)
        *p++ = (i + 1) << 11;
    {
        row = func_00567B38(rng, 6) * 5;
        const s8 *t = D_006CB170 + row * 2;
        u16 *q = out;
        for (int i = 0; i < 10; i++)
            *q++ += *t++ << 5;
    }
    {
        row = func_00567B38(rng, 6) * 5;
        const s8 *t = D_006CB3F0 + row;
        u16 *q = out;
        for (int i = 0; i < 5; i++)
            *q++ += *t++ << 4;
    }
    {
        row = func_00567B38(rng, 6) * 5;
        const s8 *t = D_006CB530 + row;
        u16 *q = out;
        for (int i = 0; i < 5; i++)
            *q++ += *t++ << 3;
    }
    {
        row = func_00567B38(rng, 6) * 5;
        const s8 *t = D_006CB670 + row;
        u16 *q = out + 5;
        for (int i = 0; i < 5; i++)
            *q++ += *t++ << 4;
    }
    {
        row = func_00567B38(rng, 6) * 5;
        const s8 *t = D_006CB7B0 + row;
        u16 *q = out + 5;
        for (int i = 0; i < 5; i++)
            *q++ += *t++ << 3;
    }
}
