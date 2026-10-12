typedef int s32;
typedef float f32;

struct Self {
    char pad[0x4384];
    s32 m4384;
};

struct Src {
    char pad[0x88];
    s32 m88;
};

extern "C" void func_003A98A0(void *self, f32 t);

extern "C" void func_003BCFF0(struct Self *self, struct Src *arg1) {
    s32 t;

    if (self->m4384 <= 0) {
        t = arg1->m88;
        if (t > 0) {
            self->m4384 = t;
            func_003A98A0((char *)self + 0xBC, 0x1.0p-2f);
        }
    }
}
