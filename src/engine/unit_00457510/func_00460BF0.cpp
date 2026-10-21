/* Calls func_00461E50 with a two-word output record and the constant 0xC, and returns the second word of the record. What the
 * routine computes with 0xC is unknown (purpose unknown); the record is a pair of 32-bit values (output by pointer). */
#include "types.h"
struct Out {
    s32 unk0;
    s32 unk4;
};
extern "C" void func_00461E50(Out *out, s32 arg1);
extern "C" s32 func_00460BF0(void) {
    Out result;
    func_00461E50(&result, 0xC);
    return result.unk4;
}
