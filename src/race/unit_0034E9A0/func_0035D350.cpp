struct Info { unsigned char b0, b1; };
struct Eng { char p0[0x18]; float f18, f1C, f20; char p1[4]; float f28, f2C; };
struct Wheel { char p0[0x1C]; float f1C, f20, f24; char p1[0x34 - 0x28]; };
struct St {
    float f0, f4;
    char p0[0x30 - 8];
    float f30, f34, f38;
    float f3C[3], f48[3], f54[3];
    char p1[0x568 - 0x60];
    float f568, f56C, f570, f574, f578;
};
struct Self {
    char p0[0x10];
    Eng *eng;
    char p1[0x104 - 0x14];
    St st;
};
extern "C" Info *func_00359510(Eng *);
extern "C" void func_0036C9F8(float *, float *, float *, float, float, float);
extern "C" float func_0057D118(float, float);
extern "C" float func_0057D1F0(float);

extern "C" void func_0035D350(Self *self) {
    float sp0[8];
    float sp20[4], sp30[4], sp40[4], sp50[4], sp60[4];
    St *st = &self->st;
    Eng *eng = self->eng;
    Info *info = func_00359510(eng);
    for (int i = 0; i < info->b1; i++)
        sp0[i] = *(float *)((char *)self + 0x1F0 + i * 0xEC);
    st->f30 = st->f0;
    st->f34 = st->f4;
    switch (info->b0) {
    case 0: {
        float a = sp0[0], b = sp0[1], c = sp0[2], d = sp0[3];
        float ac = c - a;
        float cd = c + d;
        float h = (a + b) - cd;
        float f3 = eng->f20;
        float f21 = eng->f18;
        float f24 = eng->f1C;
        float f20 = a + ac * f3;
        float f23 = b + (d - b) * f3;
        f21 = f21 * func_0057D1F0(st->f568);
        f24 = f24 * func_0057D1F0(st->f56C);
        st->f574 = func_0057D118(((a + b) - (c + d)) * 0.5f, f21);
        st->f578 = func_0057D118(f20 - f23, f24);
        st->f38 = (f20 + f23) * 0.5f;
        break;
    }
    case 1: {
        float a = sp0[0], b = sp0[1];
        Wheel *w = (Wheel *)((char *)self + 0x7B8);
        int n = 1;
        float f0 = func_0057D118(a - b, eng->f18);
        st->f574 = f0;
        func_0036C9F8(sp20, sp30, sp40, f0, 0.0f, st->f570);
        float *out = sp60;
        do {
            n -= 1;
            float f6 = w->f1C;
            float f1 = -w->f24;
            float f4 = w->f20;
            float d = f6 * sp20[0] + f1 * sp20[1] + f4 * sp20[2];
            w++;
            float x = f6 - d * sp20[0];
            float y = f1 - d * sp20[1];
            float z = f4 - d * sp20[2];
            sp50[0] = x;
            sp50[1] = y;
            sp50[2] = z;
            *out = func_0057D118(x * sp30[0] + y * sp30[1] + z * sp30[2], 1.0f);
            out++;
        } while (n >= 0);
        st->f578 = sp60[0] + (sp60[1] - sp60[0]) * eng->f20;
        st->f38 = a + (b - a) * eng->f20;
        break;
    }
    case 2: {
        float b = sp0[1], c = sp0[2];
        float f12 = (b + c) * 0.5f;
        float a = sp0[0];
        float f20 = a + (f12 - a) * eng->f20;
        st->f574 = func_0057D118(a - f12, eng->f18);
        float r = func_0057D118(b - c, 2.0f * eng->f2C);
        st->f38 = f20;
        st->f578 = r;
        break;
    }
    case 3: {
        float a = sp0[0], b = sp0[1];
        float f20 = (a + b) * 0.5f;
        float c = sp0[2];
        float f20b = f20 + (c - f20) * eng->f20;
        st->f574 = func_0057D118(f20 - c, eng->f18);
        float r = func_0057D118(a - b, 2.0f * eng->f28);
        st->f38 = f20b;
        st->f578 = r;
        break;
    }
    }
    func_0036C9F8(st->f3C, st->f48, st->f54, st->f574, st->f578, st->f570);
}
