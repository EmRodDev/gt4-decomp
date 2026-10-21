/* Copies the value at +0xBC of the object into a one-element buffer and passes it to func_002106E0 together with the first argument, which is returned unchanged. */
#include "types.h"

struct Obj002A37B8 {
    char pad0[0xBC];
    s32 unkBC;
};

extern "C" void func_002106E0(s32 target, s32 *obj);

extern "C" s32 func_002A37B8(s32 target, struct Obj002A37B8 *obj) {
    s32 valueBuf[1];

    valueBuf[0] = obj->unkBC;
    func_002106E0(target, valueBuf);
    return target;
}
