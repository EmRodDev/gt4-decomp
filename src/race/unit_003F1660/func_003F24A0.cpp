/* Looks up a 32-byte entry (table D_00622268, selected by the byte at owner+0x1076) and returns a value for one wheel. Kind 2: a ramp
 * of the value at +0x640 (zero below f18, f14 at and above f1C, linear between). Kind 3: f14 when the per-wheel flag table
 * D_00620288 has a zero for the wheel's index. Anything else returns 0. What the entry describes is unknown. */
#include "types.h"

struct Ent {
    u8 kind;
    char pad1[0x13];
    f32 f14;
    f32 f18;
    f32 f1C;
};

extern char D_00622268[];
extern u8 D_00620288[];

extern "C" f32 func_003F24A0(char *self, s32 wheelIndex) {
    f32 result = 0.0f;
    char *config = *(char **)(self + 0x10);
    Ent *entry = (Ent *)(D_00622268 + ((*(u8 *)(config + 0x1076)) << 5));
    if (entry->kind == 2) {
        f32 input = *(f32 *)(self + 0x640);
        if (entry->f1C <= input) {
            result = entry->f14;
        } else {
            f32 rampStart = entry->f18;
            if (rampStart < input) {
                result = (entry->f14 * (input - rampStart)) / (entry->f1C - rampStart);
            }
        }
    } else if (entry->kind == 3) {
        char *wheel = self + 0xEC * wheelIndex;
        u8 flagIndex = *(u8 *)(wheel + 0x1ED);
        if (D_00620288[flagIndex] == 0) {
            result = entry->f14;
        }
    }
    return result;
}
