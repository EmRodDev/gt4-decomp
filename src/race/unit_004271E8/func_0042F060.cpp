/* Finds a record in a ring buffer (layout inferred from the arithmetic): the ring header is at +8 (start index at +0xC, fill count at
 * +0x10), the records are 16 bytes each from +0x10 of the header, and the ring has 0xB6A slots. remaining = total (at +0xB6C0) minus
 * func_005797A8(arg1, arg2, arg3). If remaining is positive and not larger than the fill count, returns the record at
 * start + (count - remaining), wrapped at 0xB6A; otherwise returns 0. */
#include "types.h"

struct S42F060 {
    char pad0[0xB6C0];
    s32 total;
};

struct B42F060 {
    s32 p0;
    s32 start;
    s32 fillCount;
};

extern "C" s32 func_005797A8(s32 a, s32 b, s32 c);

extern "C" void *func_0042F060(struct S42F060 *self, s32 arg1, s32 arg2, s32 arg3) {
    s32 consumed;
    s32 remaining;
    struct B42F060 *ring;
    consumed = func_005797A8(arg1, arg2, arg3);
    ring = (struct B42F060 *)((char *)self + 8);
    remaining = self->total - consumed;
    if (remaining > 0) {
        s32 count = ring->fillCount;
        if (count >= remaining) {
            u32 slot = (u32)ring->start + (u32)(count - remaining);
            u32 inRange = (slot < 0xB6A);
            u32 wrapped = slot - 0xB6A;
            slot = inRange ? slot : wrapped;
            return (char *)ring + (slot << 4) + 0x10;
        }
    }
    return 0;
}
