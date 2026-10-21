/* Calls func_00146198 with the three given values and a fourth computed as (int)(func_00472A08(PDISTD__UNIT_MANAGER, func_00146600()) * 100.0 + 0.5),
 * i.e. a rounded hundredths value; func_00146600 returns the +0x184 field in hundredths, so this converts it through the unit manager (inferred from the global's name)
 * and back to an integer. The arguments are passed through untouched, which is why no local names exist. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" M2C_UNK func_00146198(s32, s32, s32, s32);          /* extern */
extern "C" f32 func_00146600();                                /* extern */
extern "C" f32 func_00472A08(M2C_UNK, f32);                    /* extern */

extern char PDISTD__UNIT_MANAGER[];
extern "C" void func_001462D8(s32 first, s32 second, s32 third) {
    func_00146198((s32)(first), (s32)(second), (s32)(third), (s32)((s32) ((func_00472A08((M2C_UNK)((s32)PDISTD__UNIT_MANAGER), (f32)(func_00146600())) * 0x1.9000000000000p+6f) + 0x1.0000000000000p-1f)));
}
