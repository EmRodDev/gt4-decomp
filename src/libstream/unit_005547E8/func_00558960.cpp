typedef int s32;
extern s32 D_0064D260;
extern s32 D_0064D25C;
extern void *D_00873560;
extern "C" void func_00578500(s32);
extern "C" void func_005584B0(void *, float);
extern "C" void func_00578480(s32);

extern "C" void func_00558960(float value) {
    if (D_0064D260 && D_00873560) {
        func_00578500(D_0064D25C);
        func_005584B0(D_00873560, value);
        func_00578480(D_0064D25C);
    }
}
