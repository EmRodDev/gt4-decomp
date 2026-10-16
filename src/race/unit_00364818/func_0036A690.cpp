/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info {char pad0[0x10]; unsigned char kind[16]; unsigned char sel[16];};
struct Obj {char pad[0x28]; float a[1013]; float b[1];};
extern "C" char *func_00359510(Obj *);
extern "C" float func_0057D118(float, float);
extern "C" float func_0057D1F0(float);
static inline int locate(Info *base, int offset) { return (int)base + offset; }
extern "C" float func_0036A690(Obj *self, int idx, float unused, float t){
    Info *info = (Info *)(func_00359510(self) + 0xC);
    float r = 0.0f;
    Info *indexed = (Info *)(idx + (int)info);
    idx += 0x10;
    idx = locate(info, idx);
    int active = (*(unsigned char *)idx ^ 2) != 0;
    if (active) {
        int j = indexed->sel[0];
        float f21 = self->b[j];
        float f20 = self->a[j];
        if (f21 != 0.0f)
            f20 -= (1.0f - func_0057D1F0(func_0057D118(t, f21))) * f21;
        if (*(unsigned char *)idx == 0) f20 = -f20;
        r = f20;
    }
    return r;
}
