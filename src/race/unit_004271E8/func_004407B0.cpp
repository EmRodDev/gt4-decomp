/* Fills the entry selected by the index at +0x490 in the table of 0x178-byte entries that starts at +8: stores the 64-bit
 * value at +0xE8, calls func_00440080 for the object, then stores into the signed byte at +0x156 the result of
 * func_004452A8 on the entry and bytes 0x119 and 0x116 of the source. Sibling of func_004403C0. */
#include "types.h"

struct Self { char pad0[0x490]; s32 n; };

extern "C" void func_00440080(char *arg0, s32 arg1);
extern "C" s32 func_004452A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_004407B0(char *self, s64 value64, char *source) {
    char *entry = self + ((Self *)self)->n * 0x178;
    entry += 8;
    *(s64 *)(entry + 0xE8) = value64;
    func_00440080(self, (s32)source);
    *(s8 *)(entry + 0x156) = (s8)func_004452A8((s32)entry, 1, ((u8 *)source)[0x119], ((u8 *)source)[0x116]);
}
