/* Passes the bit pattern of the float argument (through a union, no conversion) to func_002FFB58 together with the first argument, and returns the first argument unchanged (a 'set value, return this' shape, inferred). */
#include "types.h"

extern "C" void func_002FFB58(s32 self, s32 value);

extern "C" s32 func_002FFCA8(s32 self, f32 value) {
    s32 result = self;
    union { f32 f; s32 i; } bits;
    bits.f = value;
    func_002FFB58(result, bits.i);
    return result;
}
