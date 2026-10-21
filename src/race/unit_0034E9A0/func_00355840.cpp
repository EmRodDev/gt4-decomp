/* When the type byte reached through the pointer at +0x10 (offset 0x32) equals 3, clears the two words at +0x788.
 * Meaning of type 3 and of the words unknown. */
#include "types.h"

struct Inner00355840 {
    char pad[0x32];
    u8 unk32;
};

struct Obj00355840 {
    char pad0[0x10];
    struct Inner00355840 *unk10;
};

struct Tail00355840 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00355840(struct Obj00355840 *self) {
    if (self->unk10->unk32 == 3) {
        struct Tail00355840 *tail = (struct Tail00355840 *)((char *)self + 0x788);
        tail->unk0 = 0;
        tail->unk4 = 0;
    }
}
