/* Constructor-shaped (inferred from call order, no RTTI name here): runs func_00419068 on the whole object first, then
 * initialises the member at +0x680 (func_003B04D0), then clears the field at +0x690 (purpose unknown). */
#include "types.h"

struct Obj {
    u8 pad[0x690];
    s32 unk690;
};

extern "C" void func_003B04D0(char *arg0);
extern "C" int func_00419068(Obj *arg0);

extern "C" void func_003B08C8(Obj *self) {
    func_00419068(self);
    func_003B04D0((char *)self + 0x680);
    self->unk690 = 0;
}
