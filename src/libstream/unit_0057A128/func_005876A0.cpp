/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

struct Req { u8 type; char pad[3]; s32 m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern "C" s32 func_005878F8(Req *, s32);
extern "C" s32 func_0058B200(s32);
extern "C" s32 func_005ADB90(void);
extern "C" s32 func_005AE770(void);
extern "C" void func_005B0750(const char *, ...);
extern s32 D_0087E180;

/* _sceErxSelfStopUnloadLoadStartModuleFile */
extern "C" s32 func_005876A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    Req r;
    s32 x, tid;
    if (func_005AE770() != 0)
        return 0x81058007;
    x = func_0058B200((s32)__builtin_return_address(0));
    if (x < 0) {
        func_005B0750("sceErxSelfStopUnloadLoadStartModuleFile(): panic !!! call from unknown Module !!!\n");
        while (1)
            ;
    }
    tid = func_005ADB90();
    if (tid == D_0087E180) {
        func_005B0750("sceErxSelfStopUnloadLoadStartModuleFile(): panic !!! Unexpected case !!!\n");
        while (1)
            ;
    }
    r.type = 9;
    r.m4 = x;
    r.m8 = tid;
    r.mC = d;
    r.m18 = e;
    r.m1C = f;
    r.m20 = a;
    r.m24 = b;
    r.m38 = g;
    r.m3C = h;
    r.m28 = c;
    return func_005878F8(&r, 0);
}
