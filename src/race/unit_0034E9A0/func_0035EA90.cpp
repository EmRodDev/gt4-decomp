/* compiler: ee-gcc2.96-no-strict-aliasing */
struct DynamicsConductor;
struct Config { char pad[12]; unsigned char data[512]; };
extern Config D_00622110;
extern float D_00843928[12];
extern float D_00843958[12];
extern float D_006208D0[6];
extern "C" unsigned char DynamicsConductor__getCourseType(DynamicsConductor *self);
extern "C" void func_0035EA08() throw();
extern "C" void func_0035E968() throw();

extern "C" void func_0035EA90(DynamicsConductor *self) {
    func_0035EA08();
    int idx = 0;
    int type = DynamicsConductor__getCourseType(self);
    if (type < 4) {
        if (type < 2) idx = 0;
        else idx = 1;
    }
    Config *c = &D_00622110;
    float *a = D_00843928;
    float *b = D_00843958;
    a[0] = c->data[idx * 32 + 0xE0];
    a[1] = c->data[idx * 32 + 0xE1];
    a[2] = c->data[idx * 32 + 0xE2];
    b[0] = c->data[idx * 32 + 0xE6];
    b[1] = c->data[idx * 32 + 0xE7];
    b[2] = c->data[idx * 32 + 0xE8];
    a[3] = c->data[idx * 32 + 0xE3];
    a[4] = c->data[idx * 32 + 0xE4];
    a[5] = c->data[idx * 32 + 0xE5];
    b[3] = c->data[idx * 32 + 0xE9];
    b[4] = c->data[idx * 32 + 0xEA];
    b[5] = c->data[idx * 32 + 0xEB];
    a[6] = c->data[idx * 32 + 0xEC];
    a[7] = c->data[idx * 32 + 0xED];
    float &a8 = a[8];
    unsigned char special = c->data[idx * 32 + 0xEE];
    a8 = special;
    b[6] = c->data[idx * 32 + 0xF2];
    b[7] = c->data[idx * 32 + 0xF3];
    float &b8 = b[8];
    b8 = c->data[idx * 32 + 0xF4];
    a[9] = c->data[idx * 32 + 0xEF];
    a[10] = c->data[idx * 32 + 0xF0];
    a[11] = c->data[idx * 32 + 0xF1];
    b[9] = c->data[idx * 32 + 0xF5];
    b[10] = c->data[idx * 32 + 0xF6];
    b[11] = c->data[idx * 32 + 0xF7];
    if (special == 0) {
        a8 += 30.0f;
        b8 += 10.0f;
    }
    D_006208D0[0] = c->data[idx * 32 + 0xF8] * 10.0f;
    D_006208D0[1] = c->data[idx * 32 + 0xF9] * 10.0f;
    D_006208D0[2] = c->data[idx * 32 + 0xFA] * 10.0f;
    D_006208D0[3] = c->data[idx * 32 + 0xFB] * 0x1.1df468p-6f;
    D_006208D0[4] = c->data[idx * 32 + 0xFC] * 0x1.1df468p-6f;
    D_006208D0[5] = c->data[idx * 32 + 0xFD] * 0x1.47ae14p-7f;
    return func_0035E968();
}
