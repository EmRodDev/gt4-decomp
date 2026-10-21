/* When `arg1` matches the literal "keep" (func_0057F238 looks like a string comparison, inferred), computes 0xFFC0 * 2^46 / func_0057FB50(seconds * 60) in double precision (soft-float helper dpdiv), narrows it to float and hands it to func_002C3C30 with the handle at +0x10.
 * The constant factor and the callees are not understood; the 60 suggests seconds to frames (inferred). */
#include "types.h"
struct S { char pad[0x10]; void *f10; };
extern "C" s32 func_0057F238(s32, const char *);
extern "C" s32 dpdiv(s64, s32);
extern "C" f32 dptofp(s32);
extern "C" s32 func_0057FB50(f32);
extern "C" void func_002C3C30(void *, s32, f32);
extern "C" void func_0023F938(S *obj, s32 name, f32 seconds) {
    if (func_0057F238(name, "keep") != 0) {
        s64 scale = 0xFFC0;
        func_002C3C30(obj->f10, name, dptofp(dpdiv(scale << 46, func_0057FB50(seconds * 60.0f))));
    }
}
