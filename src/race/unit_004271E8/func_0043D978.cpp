/* Destructor of a class whose own vtable is D_00687F90 (it writes that pointer first): destroys, last to first, the two 0xB8-byte
 * members stored from +4 to +0x174 through their virtual destructor (vtable +8, flag 2), then runs the base destructor 00438B18 and, when bit 0
 * of deleteFlags is set, frees the object with 005C1628. The "+4 != 0" test is the compiler's leftover null check of the array address.
 * (Shape of a g++ 2.96 destructor with an array member, inferred; the class itself is purpose unknown.) */
#include "types.h"

extern void *D_00687F90;
extern "C" void func_00438B18(void *, s32);
extern "C" void func_005C1628(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x0) + 0x8);
    e->fn(o + e->delta, a0);
}

struct func_0043D978_arg0 {
    void *unk0;
};

extern "C" void func_0043D978(void *self, s32 deleteFlags) {
    ((struct func_0043D978_arg0 *)self)->unk0 = &D_00687F90;
    if ((char *)self + 0x4 != 0) {
        char *member = (char *)self + 0x174;
        while ((char *)self + 0x4 != member) {
            member -= 0xB8;
            vcall_0((char *)member, 0x2);
        }
    }
    func_00438B18(self, 0x0);
    if ((deleteFlags & 0x1) != 0) {
        return func_005C1628(self);
    }
}
