typedef int s32;
typedef float f32;

extern "C" s32 func_00462868(void);
extern "C" f32 func_00462DB0(s32 i, s32 j);
extern "C" void func_0055C458(s32 arg0, s32 arg1);
extern "C" char *D_00622F4C;

extern "C" void func_00461620(f32 fparg0) {
    func_0055C458((s32)(fparg0 * func_00462DB0(func_00462868(), 1) * ((f32)*(s32 *)(D_00622F4C + 0x38D10) * 0.0078125f) * 16383.0f), 1);
}
