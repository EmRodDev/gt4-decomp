/* Take-once accessor: if the flag at +0x1E0 is nonzero, clears it and returns the address of the block at +0x1E4, otherwise returns NULL
 * (inferred from the clear-and-return shape; the block is a pending request or result of a kind that is purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x1E0];
    s32 unk1E0;
};

extern "C" void *func_00335E68(struct Obj *self) {
    if (self->unk1E0 != 0) {
        self->unk1E0 = 0;
        return (char *)self + 0x1E4;
    }
    return 0;
}
