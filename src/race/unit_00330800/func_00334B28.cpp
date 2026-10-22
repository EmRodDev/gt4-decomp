/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds a parameter block for the object whose id is at +0 and registers it with func_0033DE30. func_003EFC10
 * fills the block from the floats at +0x134, +0x13C, +0x130 and +0x138 and the constant 5500.0 (what they stand
 * for is unknown). The mode at +0x128 then picks a tweak: mode 2 clears the word at block+0x14, mode 1 applies a
 * white tint built with func_003EFCE8 (1, 1, 1, 0, 1, 0.6) and mode 4 applies a warm tint (1.5, 0.95, 0.6, 0, 1,
 * 0.3), both through func_003EFD80; the colour reading is inferred from the values. Other modes leave the block as
 * it was. The tint struct has a constructor that sets its defaults; func_003EFCE8 overwrites all six. */
typedef int s32;
typedef float f32;

struct Obj {
    s32 u0;
    char pad4[0x124];
    s32 u128;
    char pad12C[4];
    f32 f130, f134, f138, f13C;
};

struct S0 {
    char pad0[0x14];
    s32 u14;
    char pad18[8];
};

struct S1 {
    f32 a, b, tint, d, e, f;
    S1() { a = 1.0f; b = 1.0f; tint = 1.0f; d = 0.0f; e = 1.0f; f = 1.0f; }
};

extern "C" void func_0033DE30(s32, void *);
extern "C" void func_003EFC10(void *, f32, f32, f32, f32, f32);
extern "C" void func_003EFCE8(void *, f32, f32, f32, f32, f32, f32);
extern "C" void func_003EFD80(void *, void *);

extern "C" void func_00334B28(Obj *self) {
    S0 block;
    func_003EFC10(&block, self->f134, self->f13C, self->f130, self->f138, 5500.0f);
    switch (self->u128) {
    case 2:
        block.u14 = 0;
        break;
    case 1: {
        S1 tint;
        func_003EFCE8(&tint, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.6f);
        func_003EFD80(&block, &tint);
        break;
    }
    case 4: {
        S1 tint;
        func_003EFCE8(&tint, 1.5f, 0.95f, 0.6f, 0.0f, 1.0f, 0.3f);
        func_003EFD80(&block, &tint);
        break;
    }
    }
    func_0033DE30(self->u0, &block);
}
