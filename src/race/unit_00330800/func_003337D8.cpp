/* Constructor-shaped (inferred from call order): initialises the member at +0x1C with func_005CD968, then zeroes its
 * fields at +0x10 and +0x14 (purpose unknown). */
#include "types.h"

struct Inner003337D8 {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
};

extern "C" void func_005CD968(struct Inner003337D8 *arg0);

extern "C" void func_003337D8(void *self) {
    struct Inner003337D8 *member = (struct Inner003337D8 *)((char *)self + 0x1C);

    func_005CD968(member);
    member->unk10 = 0;
    member->unk14 = 0;
}
