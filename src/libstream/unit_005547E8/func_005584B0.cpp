/* Setter: stores a float at +0x794 and then calls func_00578480 on the sub-object pointer held at +0x798.
 * What the float means is unknown (field names stay unkNN, purpose unknown). */
#include "types.h"

struct S005584B0 {
    char pad0[0x794];
    f32 unk794;
    s32 unk798;
};

extern "C" void func_00578480(s32 arg0);

extern "C" void func_005584B0(S005584B0 *self, f32 value) {
    self->unk794 = value;
    func_00578480(self->unk798);
}
