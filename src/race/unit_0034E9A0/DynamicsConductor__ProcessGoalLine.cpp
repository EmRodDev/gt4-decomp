/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Slot { char pad[0x5B7]; u8 b5B7; };
struct DC {
    void *f0;
    char pad4[0xCBDE - 4];
    u8 fCBDE;
    char padCBDF[0xF81A - 0xCBDF];
    u8 fF81A;
};

extern "C" Slot *func_0034C190(void *arg0, s32 arg1);
extern "C" void func_00343D78(void *p, s32 n);
extern "C" void func_0034C0A0(void *p, s32 n);
extern "C" void func_00363528(void *p);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(void *self, s32 v, s32 w, s32 x, s32 t, s32 f);
extern "C" void func_0035DF80(void *p, s32 a, s32 b, s32 c);

extern "C" s32 DynamicsConductor__ProcessGoalLine(DC *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    if (arg0->fCBDE != 1 && arg0->fF81A != 2) {
        return 0;
    }
    Slot *s0 = func_0034C190(arg0, arg1);
    char *q = (char *)s0 + 0x104;
    RaceDisplayGeneralTimeEvent__structor_1(arg0, arg1, arg2, arg4, arg5, s0->b5B7);
    func_0035DF80(arg0->f0, 5, arg1, 2);
    func_00343D78(s0, 3);
    if (arg1 == 0) {
        func_0034C0A0(arg0, 3);
    }
    func_00363528(s0);
    *(s32 *)(q + 0x614) = arg4;
    return 1;
}
