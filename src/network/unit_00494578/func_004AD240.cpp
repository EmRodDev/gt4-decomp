/* Deleting destructor: stores the class's pointer D_00688D48 at +0xA4, runs the base destructor func_004ACE08, destroys the sub-objects at +0x64 and +0x10 (func_00574DA8 with 2) and resets the three list heads at +0x58, +0x4C and +0x40 (each gets the shared pointer D_00688C40 and func_0057CA38). When bit 0 of the flags is set the object is freed too (func_005C1628), which is the usual g++ deleting-destructor shape (inferred). */
#include "types.h"
#define NULL 0

void func_004ACE08(void *item);                 /* extern */
void func_00574DA8(void *, s32);                /* extern */
void func_0057CA38(void *, s32);                /* extern */
void func_005C1628(void *);                     /* extern */

extern char D_00688D48[];
extern char D_00688C40[];

struct func_004AD240_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

struct func_004AD240_sub {
    char pad0[8];
    s32 unk8;
};

void func_004AD240(void *self, s32 deleteFlags) {
    struct func_004AD240_sub *list58;
    struct func_004AD240_sub *list4C;
    struct func_004AD240_sub *list40;

    ((struct func_004AD240_arg0 *)self)->unkA4 = (s32)D_00688D48;
    func_004ACE08(self);
    func_00574DA8((char *)self + 0x64, 2);
    list58 = (struct func_004AD240_sub *)((char *)self + 0x58);
    list58->unk8 = (s32)D_00688C40;
    func_0057CA38(list58, 0);
    list4C = (struct func_004AD240_sub *)((char *)self + 0x4C);
    list4C->unk8 = (s32)D_00688C40;
    func_0057CA38(list4C, 0);
    list40 = (struct func_004AD240_sub *)((char *)self + 0x40);
    list40->unk8 = (s32)D_00688C40;
    func_0057CA38(list40, 0);
    func_00574DA8((char *)self + 0x10, 2);
    if (deleteFlags & 1) {
        return func_005C1628(self);
    }
}
