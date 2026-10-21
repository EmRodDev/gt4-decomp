/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Draws an accumulated effect into the area 'area': n passes (halved once when the strength self->f58 is below 0.5 and again below 0.25, at least 1) are rendered one after another between two surfaces, each pass running the func_004A.... state set-up, and, when the two weights at +0x18C/+0x190 are not both zero, splitting the passes between them (splitIndex = n * w1/(w1+w2)) and calling func_001D6968 per pass. After the loop the result is scaled onto the area with func_004A6788. Interpretation (a motion-blur or fade style effect) is a guess from the weights and the pass loop; the exact visual is not determined. */
struct Rect { char p[0x10]; int x; int y; int w; int h; };
struct Obj { char p[8]; int f8; char q[0x34]; };
struct Self { char p[0x58]; float f58; char q[0x18C - 0x5C]; float f18c; float f190; };
extern "C" void func_00105280(Obj *, int);
extern "C" Obj *func_00105378(Obj *, void *);
extern "C" void func_001054A0(Obj *, int);
extern "C" void func_00105670(void *);
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(void *);
extern "C" int func_00105818(Obj *);
extern "C" void *func_00105AD8(void *, void *, int, int);
extern "C" void func_001D6968(Self *, void *, void *, int, float, float);
extern "C" void func_001D6DC8(Self *);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A2C58(int, int, float);
extern "C" void func_004A3078(int);
extern "C" void func_004A3088(float);
extern "C" void func_004A3230(int);
extern "C" void func_004A3998(int, float);
extern "C" void func_004A4550(int, int);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);
extern "C" void func_001D6378(Self *self, void *source, void *target, Rect *area, int passes) {
    Obj scratchSurface;
    func_00105670(area);
    float a = self->f58;
    float threshold = 0.5f;
    if (a < threshold) passes = passes / 2;
    threshold = 0.25f;
    if (a < threshold) passes = passes / 2;
    a = self->f18c;
    float sum = a + self->f190;
    if (passes <= 0) passes = 1;
    int noWeights = 1;
    if (sum != 0.0f) noWeights = 0;
    float weightRatio = 0.0f;
    if (noWeights == 0) weightRatio = a / sum;
    float passesF = (float)passes;
    int splitIndex = (int)(passesF * weightRatio + 0.5f);
    int i = 0;
    while (i < passes) {
        func_001056A0(target);
        func_00105AD8(target, source, 0, 0);
        func_004A3078(0x80000000);
        func_004A29A8(1);
        func_004A2980(0xFF000000);
        func_004A3088(1.0f);
        func_004A3230(3);
        func_004A2980(-1);
        if (noWeights == 0) {
            int inSecondGroup = i >= splitIndex;
            func_004A2C58(passes, i, 0x1.333332p-1f);
            float divisor = (float)i + 0.125f;
            float position = divisor / passesF;
            if (inSecondGroup == 0) divisor = (float)splitIndex; else divisor = (float)(passes - splitIndex);
            func_001D6968(self, source, target, inSecondGroup, position, passesF / divisor);
        }
        int nextIndex = i + 1;
        for (int k = 0; k < nextIndex; k++)
            func_004A2C58(passes, i, 0x1.999998p-2f);
        func_001D6DC8(self);
        func_004A3998(6, 1.0f / ((float)i + 1.0f));
        i = nextIndex;
    }
    func_00105378(&scratchSurface, source);
    func_001054A0(&scratchSurface, 0);
    func_001056A0(&scratchSurface);
    func_00105728(area);
    func_004A4550(3, 0);
    func_004A4550(2, 0);
    func_004A29A8(0);
    func_004AB040(5);
    func_004AB040(4);
    func_004A1638(6);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    func_004A2808(0x64, self->f58);
    float surfaceW = (float)scratchSurface.f8;
    int surfaceH = func_00105818(&scratchSurface);
    float areaX = area->x;
    float areaY = area->y;
    float areaRight = area->x + area->w;
    float areaBottom = area->y + area->h;
    func_004A6788(0.0f, 0.0f, surfaceW, (float)surfaceH, areaX, areaY, areaRight, areaBottom);
    func_00105280(&scratchSurface, 2);
}
