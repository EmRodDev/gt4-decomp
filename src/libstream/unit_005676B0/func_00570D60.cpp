typedef unsigned char u8;
typedef int s32;

extern "C" void func_0057DA20(s32 arg0, const char *fmt, u8 a, u8 b, u8 c, u8 d);

extern "C" s32 func_00570D60(s32 arg0, const u8 *arg1) {
    if (arg1 == 0 || arg0 == 0) {
        return -512;
    }
    func_0057DA20(arg0, "%u.%u.%u.%u", arg1[7], arg1[6], arg1[5], arg1[4]);
    return 0;
}
