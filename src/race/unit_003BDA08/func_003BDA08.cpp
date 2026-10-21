/* Constructor-shaped (inferred from call order): runs func_005720B8 on the object, clears the field at +0x90, then
 * memset (func_005A48D8, named in config/stl_symbols.txt) zeroes the 0x10 bytes at +0x80 and its result is returned. */
#include "types.h"

struct Obj_003BDA08 {
    char pad[0x90];
    s32 unk90;
};

extern "C" void *func_005720B8(void *dest);
extern "C" void *func_005A48D8(void *dest, s32 value, s32 size);

extern "C" void *func_003BDA08(struct Obj_003BDA08 *self) {
    struct Obj_003BDA08 *obj = self;

    func_005720B8(obj);
    obj->unk90 = 0;
    return func_005A48D8((char *)obj + 0x80, 0, 0x10);
}
