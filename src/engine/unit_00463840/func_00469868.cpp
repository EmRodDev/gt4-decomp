/* If the byte at +0x51 of the sub-object at +0x14 equals the byte at +0x544 of the other object, sets it to -1
 * ('none', inferred from the sentinel value). Meaning of the two bytes unknown. */
#include "types.h"

struct SubStruct {
    char pad[0x51];
    s8 unk51;
};

struct Struct544 {
    char pad[0x544];
    u8 unk544;
};

extern "C" void func_00469868(void *self, struct Struct544 *other) {
    struct SubStruct *sub = (struct SubStruct *)((char *)self + 0x14);

    if (sub->unk51 == other->unk544) {
        sub->unk51 = -1;
    }
}
