/* Tests bit 2 of the byte at +0x1C of the entry numbered 'index' (0..0x7F) in a table at 'table'; entries outside that range
 * report 0. The entries are addressed by byte offset (index + table), not by stride, so this looks like a per-slot flag byte
 * (inferred from the addressing). func_0047D050 calls it with index 1. Meaning of the flag unknown. */
#include "types.h"

struct Obj0047D108 {
    char pad0[0x1C];
    u8 flags;
};

extern "C" s32 func_0047D108(s32 table, u32 index) {
    s32 result = 0;
    if (index < 0x80U) {
        u32 flagsByte = ((struct Obj0047D108 *)(index + table))->flags;
        result = (flagsByte >> 2) & 1;
    }
    return result;
}
