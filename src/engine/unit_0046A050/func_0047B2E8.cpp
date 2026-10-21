/* Script-native shaped function (inferred): it takes its arguments from the script value stack. With argCount arguments it pops one
 * integer (func_004774A8 on the top element) when there is at least one, then four floats (func_00477460, truncated to int) when
 * four more remain, drops any extra arguments with func_00480FA0, calls func_004807A0(arg1, intValue, four values) and returns
 * the result slot set to 1. Unset values stay -1. What func_004807A0 does with them is unknown. */
#include "types.h"

struct E8 {
    s32 a;
    s32 b;
};

struct S00480F78 {
    s32 f0;
    s32 f4;
    E8 *top;
};

extern "C" f32 func_00477460(E8 *);
extern "C" s32 func_004774A8(E8 *);
extern "C" void func_004807A0(s32, s32, s32, s32, s32, s32);
extern "C" void func_00480F78(S00480F78 *);
extern "C" void func_00480FA0(S00480F78 *, s32);

extern "C" s32 *func_0047B2E8(s32 *result, s32 target, u32 argCount, S00480F78 *stack) {
    u32 remaining = argCount;
    s32 intValue = 0;
    s32 value1 = -1;
    s32 value2 = -1;
    s32 value3 = -1;
    s32 value4 = -1;

    if (remaining != 0) {
        remaining -= 1;
        intValue = func_004774A8(stack->top - 1);
        func_00480F78(stack);
    }
    if (remaining >= 4U) {
        remaining -= 4;
        value1 = (s32)func_00477460(stack->top - 1);
        func_00480F78(stack);
        value2 = (s32)func_00477460(stack->top - 1);
        func_00480F78(stack);
        value3 = (s32)func_00477460(stack->top - 1);
        func_00480F78(stack);
        value4 = (s32)func_00477460(stack->top - 1);
        func_00480F78(stack);
    }
    func_00480FA0(stack, (s32)remaining);
    func_004807A0(target, intValue, value1, value2, value3, value4);
    *result = 1;
    return result;
}
