#include "types.h"

extern "C" void func_00493428(void);
extern "C" void func_00493C70(s32 arg0, void (*arg1)(void), s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_00491690(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00493C70(arg0, func_00493428, arg1, arg2, arg3);
}
