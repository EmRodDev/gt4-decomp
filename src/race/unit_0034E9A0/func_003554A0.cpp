/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Engine-output step for the 0..1 input x (probably the throttle; see func_003F79A0 and func_003519B8, which call this
 * with the dynamics value at +0x494). When the engine record's field at +0x230 is zero the input is simply stored.
 * Otherwise it tracks three 16-bit values at +0x4F4/+0x4F6/+0x4FA (the first two move toward a target ratio at a rate
 * from the engine tables times the step factor f54C, the third is the reference), smooths f508, and runs a small
 * two-state switch (b607) that triggers below x = 0.75 and releases above 0.9. The result r (1.0 or f4/f21) goes through
 * func_00355410 and func_00354B78; b606 receives a 1..127 level derived from f500 and the result. The exact physical
 * quantities are purpose unknown; the layout of the engine record at +0x134 is partly known from func_003519B8. */
struct St {
    char p0[0x4F0];
    float f4F0;
    short s4F4;
    short s4F6;
    short s4F8;
    short s4FA;
    char p1[2];
    float f500, f504, f508;
    char p2[0x5F8 - 0x50C];
    short tab[2];
    char p3[0x606 - 0x5FC];
    unsigned char b606, b607;
};
struct Self {
    char p0[0x10];
    char *eng;
    char p1[0x104 - 0x14];
    St st;
};
struct Self2 { char p0[0x54C]; float f54C; };
extern "C" float func_0034ECF0(char *, short, short, float *);
extern "C" void func_00354B78(Self *, float) throw();
extern "C" float func_00355410(Self *, float) throw();

extern "C" float func_003554A0(Self *self, float input) {
    float scratch[4];
    St *st = &self->st;
    char *eng = self->eng;
    char *engineData = eng + 0x134;
    float stepFactor = ((Self2 *)self)->f54C;
    float ratioOut = input;
    float zero = 0.0f;
    float referenceValue;
    float targetValue;
    float bias;
    if (*(float *)(engineData + 0xFC) == zero) {
        st->f4F0 = input;
        st->b606 = 0;
        st->f500 = input;
    } else {
        referenceValue = func_0034ECF0(engineData, st->s4FA, st->s4FA, scratch);
        float previousLevel = st->f4F0;
        float loopzero = 0.0f;
        st->f500 = previousLevel;
        float *rateTableA = (float *)(eng + 0x138);
        float *rateTableB = (float *)(eng + 0x140);
        float targetRatio = (previousLevel * (float)st->s4FA) / referenceValue;
        short *levelPtr = &st->s4F4;
        int offset = 0xe0;
        int count = 1;
        do {
            if (*(float *)((char *)rateTableA + offset) != loopzero) {
                int newLevel = (unsigned short)*levelPtr + (int)(((targetRatio - (float)*levelPtr) * *(float *)((char *)rateTableB + offset)) * stepFactor);
                *levelPtr = newLevel;
                if ((short)newLevel < 0) *levelPtr = 0;
            }
            count--;
            levelPtr++;
            offset += 4;
        } while (count >= 0);
        int one = 1;
        targetValue = input * func_0034ECF0(engineData, st->s4F4, st->s4F6, scratch);
        bias = 0.5f - ((float)st->s4FA * 0x1p-12f * 0.25f);
        if (bias < 0.0625f) bias = 0.0625f;
        unsigned char switchState = st->b607;
        st->f504 = 0.0f;
        st->f508 = (st->f508 + (targetValue + ((1.0f - input) * bias))) * 0.5f;
        switch (switchState) {
        case 0:
            if (input < 0.75f) {
                float f2b = st->f504;
                float temp = st->f4F0 - 0x1.999998p-1f;
                if (temp < f2b) temp = f2b;
                st->b607 = one;
                st->f504 = temp * 0.00390625f;
            }
            break;
        case 1:
            if (input > 0.9f) st->b607 = 0;
            break;
        }
        ratioOut = 1.0f;
        st->f4F0 = targetValue;
        if (!(referenceValue <= targetValue)) ratioOut = targetValue / referenceValue;
        st->s4F8 = st->s4F4;
        if ((unsigned short)st->s4F8 < st->s4F6) st->s4F8 = st->s4F6;
    }
    float result = func_00355410(self, ratioOut);
    float temp = 0.0f;
    if (*(float *)(engineData + 0xFC) > temp) {
        bias = st->f500;
        bias -= 0.75f;
        if (bias <= temp || result <= temp) st->b606 = 1;
        else {
            if (result >= 587.99994f) temp = bias;
            else temp = bias * result * 0.0017006804f;
            int levelByte = (int)(temp * temp * 128.0f);
            if (levelByte > 127) levelByte = 127;
            if (levelByte < 1) levelByte = 1;
            st->b606 = levelByte;
        }
    }
    func_00354B78(self, result);
    return result;
}
