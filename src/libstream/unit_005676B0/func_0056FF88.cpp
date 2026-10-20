/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;

extern "C" s32 func_0056FD90(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4);
extern "C" s32 func_0056FE28(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4);

extern "C" s32 func_0056FF88(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg5 & 2) {
        return func_0056FD90(arg0, arg1, arg2, arg3, arg4);
    } else {
        return func_0056FE28(arg0, arg1, arg2, arg3, arg4);
    }
}
