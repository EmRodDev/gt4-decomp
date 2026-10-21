/* Pops 'count' entries off the downward-growing stack by calling func_00480F78 (which lowers the stack pointer at +8 by 8) that
 * many times; does nothing for count <= 0. The do/while form is what the compiler emits for the guarded loop. */
#include "types.h"

struct S00480F78 {
    char pad0[8];
    s32 stackTop;
};

extern "C" void func_00480F78(struct S00480F78 *stack);

extern "C" void func_00480FA0(struct S00480F78 *stack, s32 popCount) {
    s32 count = popCount;
    if (count > 0) {
        s32 remaining = count;
        do {
            remaining--;
            func_00480F78(stack);
        } while (remaining != 0);
    }
}
