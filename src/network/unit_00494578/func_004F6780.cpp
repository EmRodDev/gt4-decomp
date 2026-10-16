/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x5A8];
    s32 unk5A8;
    char pad5AC[0x5E8 - 0x5AC];
    s32 unk5E8;
    s32 unk5EC;
    char pad5F0[0xA34 - 0x5F0];
    s32 unkA34;
    char padA38[0xFB8 - 0xA38];
    s32 unkFB8;
    char padFBC[0x2228 - 0xFBC];
    s32 unk2228;
    char pad222C[0x3F20 - 0x222C];
    s32 unk3F20;
};
extern "C" s32 func_004F68C8(Obj *);
extern "C" void func_004F8820(Obj *, s32);
extern "C" s32 func_004FA1F0(Obj *, s32);
extern "C" s32 func_00515D68(s32 *, s32);
extern "C" s32 func_0052F6F0(s32 *, s32);
extern "C" s32 func_0052FFB0(s32, s32);
extern "C" void func_004F6780(Obj *arg0) {
    s32 sp0;
    s32 sp4;
    s32 v;
    v = func_0052FFB0(arg0->unk5A8, arg0->unk5A8 + 0x1D8);
    if (v != 0) { func_004F8820(arg0, v); return; }
    sp0 = -0x3E7;
    sp4 = -0x270F;
    v = func_00515D68(&sp4, arg0->unk2228);
    if (v != 0) { func_004F8820(arg0, v); return; }
    v = func_0052F6F0(&sp0, arg0->unk2228);
    if (v != 0) {
        func_004F8820(arg0, v);
    } else {
        s32 t = sp4 == sp0;
        if (arg0->unk3F20 == 0) arg0->unk5E8 = t;
        else arg0->unk5EC = t;
        arg0->unkA34 = 0;
        arg0->unkFB8 = 1;
        s32 result = func_004F68C8(arg0);
        func_004FA1F0(arg0, result);
    }
}
