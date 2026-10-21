/* Returns, through arg0, a counted copy of the string that func_0021B788(arg1 + 0xA0) points at: it copies the character pointer and bumps the reference count of the string rep
 * that sits 0x10 bytes before it (or clones it through func_005C2560 when the rep is marked unshareable). This is the inlined basic_string copy constructor. */
#include "types.h"
#define NULL 0

extern "C" s32 *func_0021B788(s32 result);
extern "C" char *func_005C2560(void *);

struct func_0013A370_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 *func_0013A370(s32 *result, s32 owner) {
    s8 *chars;
    s8 *copy;
    struct func_0013A370_temp_a1 *rep;

    chars = (s8 *) *func_0021B788(owner + 0xA0);
    rep = (struct func_0013A370_temp_a1 *) (chars - 0x10);
    copy = chars;
    if (rep->unkC != 0) {
        copy = (s8 *) func_005C2560(rep);
    } else {
        rep->unk8 = (s32) (rep->unk8 + 1);
    }
    *result = (s32) copy;
    return result;
}
