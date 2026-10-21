/* If the counter at +0x8 is still positive does nothing; otherwise calls func_001062B8 on the global D_006184D0 (purpose unknown). */
#include "types.h"

struct Obj_00220A08 {
    char pad[8];
    s32 unk8;
};

extern "C" void func_001062B8(void *obj);
extern "C" char D_006184D0[];

extern "C" void func_00220A08(Obj_00220A08 *obj) {
    if (obj->unk8 > 0) {
        return;
    }
    return func_001062B8(D_006184D0);
}
