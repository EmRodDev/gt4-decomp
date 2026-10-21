/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern s32 D_0064A330;
extern s32 D_0064A334;
extern s32 D_0064A338;
extern s32 D_006D6228;
extern "C" s32 func_0050ABA8(void) throw();
extern "C" s32 func_0052F7B0(s32 *);
extern "C" s32 func_0052FA88(void);
extern "C" s32 func_0052FBD8(s32);
extern "C" s32 func_0050B6E0(void) {
    s32 sp0 = 0;
    s32 st;
    s32 e;
    func_0052F7B0(&sp0);
    st = D_0064A308;
    if (st != 1) return -0xF;
    s32 r1 = func_0050ABA8();
    if (r1 != 0) return r1;
    e = func_0052FA88();
    s32 ret = 0;
    if (D_0064A334 == st && D_006D6228 == D_0064A330) {
        D_0064A334 = 0;
        D_006D6228 = 0;
        D_0064A330 = 0;
        s32 r = func_0052FBD8(D_0064A30C);
        D_0064A30C = 0;
        return r == 0 ? 0 : -3;
    }
    if (e == 0) return ret;
    D_0064A338 = e;
    ret = -0xA;
    return ret;
}
