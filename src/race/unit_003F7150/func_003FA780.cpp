/* Returns 1 when the mode byte at +0x89 is 0, 7, 8, 9, 11 or 12, otherwise 0 (a jump table over 0..12). */
#include "types.h"

struct Obj003FA780 {
    char pad0[0x89];
    u8 unk89;
};

extern "C" s32 func_003FA780(struct Obj003FA780 *self) {
    switch (self->unk89) {
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
            return 1;
        default:
            return 0;
    }
}
