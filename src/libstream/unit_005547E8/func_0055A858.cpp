/* compiler: ee-gcc2.96-no-strict-aliasing */
extern float D_00654730;

struct Obj {
    char pad[0x3C];
    float unk3C;
    float unk40;
    char pad44[4];
    float unk48;
};

extern "C" void func_0055A858(Obj *arg0, float f12) {
    float f0 = 60000000.0f / f12;
    arg0->unk3C = f12;
    f0 = 1000000.0f / f0;
    f0 = f0 * arg0->unk40;
    f0 = f0 / D_00654730;
    arg0->unk48 = f0;
}
