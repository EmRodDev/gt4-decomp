/* Frees the heap block pointed to by +0x38 of the mBlockTransition (when non-null) and clears the pointer first so it cannot be freed twice. */
#include "types.h"

struct Obj0027AEB0 {
    char pad[0x38];
    s32 unk38;
};

extern "C" void free(s32 obj);

extern "C" void func_0027AEB0(struct Obj0027AEB0 *obj) {
    s32 block = obj->unk38;

    if (block != 0) {
        obj->unk38 = 0;
        free(block);
    }
}
