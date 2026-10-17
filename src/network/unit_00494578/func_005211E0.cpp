/* compiler: ee-gcc2.96-as2004g */
typedef int s32;
struct __attribute__((aligned(8))) S { s32 lo; s32 hi; };
struct Obj { char pad0[8]; s32 unk8; s32 unkC; };
extern "C" s32 func_005224D0(long);
extern "C" s32 func_005220F8(Obj *);
extern "C" void func_005221B0(s32, s32, s32);
extern "C" s32 func_00522DA8(s32, volatile s32 *, S, s32);
extern "C" s32 func_005211E0(Obj *arg0, volatile s32 *out, S id, s32 a3) {
    if (out == 0) return 2;
    *out = 0;
    if (func_005224D0(*(volatile long *)&id) != 0 || func_005220F8(arg0) == 0) return 2;
    if (arg0->unkC != 3) return 0xC355;
    s32 r = func_00522DA8(arg0->unk8, out, id, a3);
    if (r == 0) {
        func_005221B0(0x1C, 0, 0);
        return 0;
    }
    return r;
}
