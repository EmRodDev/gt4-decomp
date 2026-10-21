/* Returns whether the object referenced by the pointer at +0x1D58 resolves (via func_002C5920, purpose unknown) back to this object itself, i.e. a self-ownership check (inferred from the comparison with `arg0`). */
#include "types.h"

struct S_002320F0;

struct Obj_002320F0 {
    char pad[0x1D58];
    struct S_002320F0 *unk1D58;
};

extern "C" s32 func_002C5920(struct S_002320F0 *obj);

extern "C" s32 func_002320F0(struct Obj_002320F0 *obj) {
    return func_002C5920(obj->unk1D58) == (s32)obj;
}
