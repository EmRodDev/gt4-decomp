typedef int s32;
typedef signed char s8;

struct Obj {
    char pad0[0x4];
    s32 unk4;
    char pad0x8[0x2E - 0x8];
    s8 unk2E;
    char pad2F[0x1108 - 0x2F];
    char unk1108[1];
};

extern "C" void func_003BEE78(void *arg0, s32 arg1, s8 arg2);

extern "C" void func_0039FC88(Obj *arg0) {
    func_003BEE78(arg0->unk1108, arg0->unk4, arg0->unk2E);
}
