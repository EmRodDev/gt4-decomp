/* Moves the value at +0x68 into +0x64 and sets +0x68 to -1, where -1 reads as 'none' (like 'current = pending; pending = none';
 * inferred from the sentinel). */
#include "types.h"
struct Obj {
    char pad[0x64];
    s32 current;
    s32 pending;
};
extern "C" void func_0047FCE0(Obj *self) {
    s32 old = self->pending;
    self->pending = -1;
    self->current = old;
}
