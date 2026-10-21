/* Sets the field at +0x90 to the field at +0x84 plus one (for example 'next index = current index + 1'; meaning inferred only from
 * the arithmetic, purpose unknown). */
#include "types.h"
struct Obj { char pad[0x84]; s32 unk84; char pad2[0x90-0x84-4]; s32 unk90; };
extern "C" void func_00490F90(Obj *self) {
    self->unk90 = self->unk84 + 1;
}
