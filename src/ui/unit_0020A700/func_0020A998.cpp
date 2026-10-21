/* Returns the element count of a vector-like member at +0x10 of the object: (end - begin) in 4-byte elements.
 * The member is a begin/end pointer pair (inferred from the subtraction); the element type is unknown. */
#include "types.h"

struct S_Vec
{
    char pad0[4];
    s32 *unk4;
    s32 *unk8;
};

s32 func_0020A998(void *obj)
{
    struct S_Vec *vec = (struct S_Vec *)((char *)obj + 0x10);
    return vec->unk8 - vec->unk4;
}
