/* Counts how many of the 5 records (0x188 bytes apart, starting at +0x480) have a first word greater than or equal to the
 * value at +0x2F8 (comparison read from the code; what the words and the value are is unknown). */
#include "types.h"

struct Obj003EF2D8 {
    char pad[0x2F8];
    s32 unk2F8;
};

extern "C" s32 func_003EF2D8(struct Obj003EF2D8 *self)
{
    s32 *record = (s32 *)((char *)self + 0x480);
    s32 count = 0;
    s32 i;

    for (i = 0; i < 5; i++) {
        s32 recordValue = *record;
        record = (s32 *)((char *)record + 0x188);
        if (recordValue >= self->unk2F8) {
            count = count + 1;
        }
    }
    return count;
}
