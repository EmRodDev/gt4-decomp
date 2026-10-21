/* Reads the word stored just before the array that arg1's field at +8 points to and writes it to *arg0 (array-count-cookie-shaped, inferred from p[-1]); returns arg0. */
#include "types.h"

struct Arg1 {
    char pad[0x8];
    s32 *unk8;
};

extern "C" s32 *func_0030F670(s32 *out, Arg1 *container) {
    s32 *elements = container->unk8;
    *out = elements[-1];
    return out;
}
