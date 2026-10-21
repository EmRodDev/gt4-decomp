/* Looks up one signed byte setting of the car (at +0x96 plus an index taken from the car's table; 0 when the object is disabled) and
 * reports the allowed range -100..100 through outMin/outMax (inferred from the constants). What the setting is is unknown. */
#include "types.h"
#define NULL 0
#include "m2c_macros.h"

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
extern "C" V *func_00359510(s32);
struct func_00365100_arg0 {
    s32 unk0;
    u8 unk4;
};

extern "C" s8 func_00365100(struct func_00365100_arg0 *self, s32 slot, s8 *outMin, s8 *outMax) {
    V *info;
    u8 entryIndex;
    if (self->unk4 != 0) {
        return 0;
    }
    info = func_00359510(self->unk0 + 0x600);
    entryIndex = 0;
    if (slot < info->n) {
        entryIndex = info->b[slot];
    }
    *outMin = -0x64;
    *outMax = 0x64;
    return M2C_FIELD((entryIndex + self->unk0), s8 *, 0x96);
}
