/* Copy-on-write style detach (inferred from the shape): if the owner pointer at +0x10 does not already point at the inline 0x16B8-byte block at +0x18,
 * the block is overwritten with the owner's contents (keeping its own first word) and the owner pointer is redirected to it. */
#include "types.h"

struct CopyBlock_0018FEE8 {
    u32 first;
    u8 bytes[0x16B4];
} __attribute__((aligned(8)));

struct Owner_0018FEE8 {
    u8 pad0[0x10];
    struct CopyBlock_0018FEE8 *owner;
    u32 pad14;
    struct CopyBlock_0018FEE8 inlined;
};

void func_0018FEE8(void *object) {
    struct Owner_0018FEE8 *self = (struct Owner_0018FEE8 *)object;
    struct CopyBlock_0018FEE8 *source = self->owner;
    struct CopyBlock_0018FEE8 *target = &self->inlined;

    if (source != target) {
        u32 first[1];
        __builtin_memcpy(first, &self->inlined.first, sizeof(first));
        self->inlined = *source;
        self->inlined.first = first[0];
        self->owner = &self->inlined;
    }
}
