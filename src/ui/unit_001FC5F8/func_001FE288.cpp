/* Increments the counter at +0xE0 and calls func_001FE2B8 with the caller's value and a flag that is true only when the counter was 0 before the increment, i.e. on the first use.
 * (Reading inferred from the `v0 < 1` test on the old value.) */
#include "types.h"

struct Obj001FE288 {
    char pad[0xE0];
    s32 unkE0;
};

extern "C" void func_001FE2B8(struct Obj001FE288 *obj, s32 value, s32 arg2);

extern "C" void func_001FE288(struct Obj001FE288 *obj, s32 value) {
    s32 oldCount = obj->unkE0;

    obj->unkE0 = oldCount + 1;
    func_001FE2B8(obj, value, oldCount < 1);
}
