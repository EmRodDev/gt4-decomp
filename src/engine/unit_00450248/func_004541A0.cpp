/* Forwards the float at +0xC of the object to func_004A7988 (purpose unknown). */
#include "types.h"
struct Obj {
    char pad[0xC];
    f32 unkC;
};
extern "C" void func_004A7988(f32 value);
extern "C" void func_004541A0(struct Obj *self) {
    func_004A7988(self->unkC);
}
