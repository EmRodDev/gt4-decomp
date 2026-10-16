/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;

struct Self {
    char pad0[0xBD];
    u8 unkBD;
    char padBE[0x150 - 0xBE];
    s16 unk150;
    char pad152[3];
    u8 gearCount;   /* 0x155 */
    u8 unk156;
};

extern const u8 D_00620448[][6];

extern "C" u8 func_0034BC98(Self *self, u8 *kind, u8 *flag, float *value, float *weight);
extern "C" void func_0034BA30(Self *self, u8 flag, float *a, float *b, float *c);

extern "C" void func_00354FF8(Self *self, int speed, s16 *out, int reset) {
    float a;
    float b;
    float c;
    u8 kind;
    u8 flag;
    float value;
    float weight;

    if (reset != 0) self->unk156 = 0;
    func_0034BC98(self, &kind, &flag, &value, &weight);
    func_0034BA30(self, flag, &a, &b, &c);

    s16 gears = self->gearCount;
    int i = gears;
    if (i < 5) i = 5; else if (i > 7) i = 7;
    const u8 *row = D_00620448[i - 5];

    float t = (float)(speed - 150) / 250.0f;
    float low = 200.0f / row[1];
    float high = 200.0f / row[0];
    float step = low + t * (high - low);
    low = 200.0f / row[3];
    high = 200.0f / row[2];
    float stepScale = low + t * (high - low);
    low = 200.0f / row[5];
    high = 200.0f / row[4];
    float first = low + t * (high - low);

    float v = (float)speed * 0x1.1c71c6p-2f;
    float ratio = ((float)(self->unkBD * 100) * 0x1.acee9cp-4f * a) / v;
    ratio /= (float)self->unk150 * 0x1.0624dcp-10f;

    for (i = gears; i > 0; i--) {
        if (i == 1) {
            ratio *= first;
        }
        out[i] = (s16)(ratio * 1000.0f);
        ratio *= step;
        step *= stepScale;
    }
    out[0] = (out[1] * 3 + out[2]) / 4;
}
