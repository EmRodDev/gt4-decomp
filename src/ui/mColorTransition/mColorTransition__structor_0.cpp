typedef int s32;
typedef float f32;

struct mTransition;

struct mColorTransition {
    s32 m0;
    s32 m4;
    char pad8[0x18];
    union { s32 i; f32 f; } m20;
    f32 f24;
};

extern "C" void *func_0024D3C8(struct mTransition *arg0);
extern "C" void func_00203148(void *arg0, float fparg0, float fparg1, float fparg2, float fparg3);
extern char D_0066A150[];

extern "C" void func_00286EA0(struct mColorTransition *arg0) {
    func_0024D3C8((struct mTransition *)arg0);
    arg0->m20.i = 0;
    arg0->m4 = (s32)D_0066A150;
    f32 z = arg0->m20.f;
    func_00203148((void *)((char *)arg0 + 0x28), z, z, z, 1.0f);
    arg0->f24 = 0x1.111110p-4f;
}
