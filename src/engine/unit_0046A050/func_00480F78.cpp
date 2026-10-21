/* Pops 8 bytes off a downward-growing stack: the pointer at +8 is lowered by 8 and the new value is passed to func_004768C0.
 * The caller func_00476D40 runs it once per element of a script-value array, so this is probably the script context's value stack
 * (inferred from that caller). */
#include "types.h"

struct S00480F78 {
    char pad0[8];
    s32 stackTop;
};

extern "C" void func_004768C0(s32 newTop);

extern "C" void func_00480F78(struct S00480F78 *self) {
    s32 newTop;

    newTop = self->stackTop - 8;
    self->stackTop = newTop;
    func_004768C0(newTop);
}
