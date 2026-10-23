struct Tex {
    char pad0[8];
    int width;
    int height;
    char pad10[0x30];
    Tex(int format, int width, int height) __asm__("func_001052E0");
    ~Tex() __asm__("func_00105280");
};

extern "C" float func_00340470(void *self, float t) throw();
extern "C" void func_00105728(Tex *tex);
extern "C" void func_001056A0(Tex *tex);
extern "C" void func_004A7CE0(int *x, int *y, int *w, int *h);
extern "C" void func_004AB040(int mode);
extern "C" void func_004A29A8(int on);
extern "C" void func_004AA1D8(float r, float g, float b, float a);
extern "C" void func_004A4550(int k, int v);
extern "C" void func_004A6668(float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1);
extern "C" void func_004A2D20(int x, int y, int w, int h);
extern "C" void func_004A1638(int mode);
extern "C" void func_004A2858(int mode, float value);

extern "C" void func_00342EE8(void *self, Tex *target, float t) {
    float scale = func_00340470(self, t);
    if (scale == 0.0f)
        return;

    int r[4];
    func_004A7CE0(&r[0], &r[1], &r[2], &r[3]);
    int h = (int)(r[3] * 27.0f / scale);
    int lo = r[3] / 20;
    if (h > 128)
        h = 128;
    if (h < lo)
        h = lo;
    int w = h * r[2] / r[3];
    if (w > 128)
        w = 128;
    Tex tex(2, 128, 128);

    func_00105728(target);
    func_001056A0(&tex);
    func_004AB040(6);
    func_004AB040(5);
    func_004A29A8(0);
    func_004AB040(4);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    func_004A4550(2, 0);
    func_004A4550(3, 0);
    func_004A6668(-0.5f, -0.5f, w - 0.5f, h - 0.5f, r[0], r[1], r[0] + r[2], r[1] + r[3]);
    func_001056A0(target);
    func_00105728(&tex);
    func_004A2D20(0, 0, target->width, target->height);
    func_004A1638(3);
    func_004A2858(5, 0.5f);
    func_004A6668(r[0], r[1], r[0] + r[2], r[1] + r[3], -0.5f, -0.5f, w - 0.5f, h - 0.5f);
    func_004AB040(3);
    func_004A29A8(1);
    func_001056A0(target);
}
