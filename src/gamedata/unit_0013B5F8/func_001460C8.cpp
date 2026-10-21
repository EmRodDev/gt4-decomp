/* Looks up the object at +0x14 (func_00441248), converts it with func_00445EE8 and forwards it as the last argument of func_00145FE8 with the two given values.
 * Same shape as func_00146278 (func_00445F70 and func_00146198). */
#include "types.h"

struct Struct_001460C8 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" s32 func_00441248(s32 self);
extern "C" s32 func_00445EE8(s32 self);
extern "C" void func_00145FE8(void *self, s32 first, s32 second, s32 arg3);

extern "C" void func_001460C8(Struct_001460C8 *self, s32 first, s32 second) {
    s32 resolved = func_00441248(self->unk14);
    resolved = func_00445EE8(resolved);
    func_00145FE8(self, first, second, resolved);
}
