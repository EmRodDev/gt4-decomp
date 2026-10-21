/* Frees the heap block pointed to by +0xD8 of the object (when non-null) and clears the pointer first so it cannot be freed twice. */
#include "types.h"

struct Obj001FD5E8 {
    char pad[0xD8];
    s32 unkD8;
};

extern "C" void free(s32 obj);

extern "C" void func_001FD5E8(struct Obj001FD5E8 *obj) {
    s32 block = obj->unkD8;

    if (block != 0) {
        obj->unkD8 = 0;
        free(block);
    }
}
