extern "C" {
typedef float f32;
typedef int s32;

struct RaceDisplay {
    char pad0[0x58];
    s32 flags58;
};

void func_003A9850(char *o, f32 t);
void func_003A98E8(char *self, f32 a0, f32 a1, f32 a2, f32 a3);

void func_003A0D10(struct RaceDisplay *self, f32 fparg0) {
    if ((self->flags58 >> 10) & 1) {
        return func_003A98E8((char *)self + 0x13BC, 0.0f, fparg0, 0x1.333332p-3f, 0x1.333332p-3f);
    }
    func_003A9850((char *)self + 0x13BC, 0x1.333332p-3f);
}

}
