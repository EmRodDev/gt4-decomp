/* Calls func_004CF580 with the handle at +0x42C of the object and three values, turning the last one into a 0/1 flag, and returns whether it reported nonzero.
 * What func_004CF580 does is unknown. */
#include "types.h"

struct Obj {
    char pad[0x42C];
    s32 unk42C;
};

extern "C" s32 func_004CF580(s32 obj, s32 a, s32 b, s32 flag);

extern "C" s32 func_0026D320(Obj *obj, s32 a, s32 b, s32 flag) {
    return func_004CF580(obj->unk42C, a, b, flag != 0) != 0;
}
