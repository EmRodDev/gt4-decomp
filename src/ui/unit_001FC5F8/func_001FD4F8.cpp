/* Releases the resource whose handle is stored at +0xB4 (by calling func_0054E1D0, purpose unknown) and clears the field at +0xDC. */
#include "types.h"

struct Obj_001FD4F8 {
    char pad[0xB4];
    s32 unkB4;
    char pad2[0xDC - 0xB8];
    s32 unkDC;
};

extern "C" void func_0054E1D0(s32 obj);

extern "C" void func_001FD4F8(Obj_001FD4F8 *obj) {
    func_0054E1D0(obj->unkB4);
    obj->unkDC = 0;
}
