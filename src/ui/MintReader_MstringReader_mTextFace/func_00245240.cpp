/* Forwards to func_002B71D0 with the text face's field at +0x104 (purpose unknown) and returns the first argument unchanged.
 * The shape (destination in, destination out) suggests a constructor-like helper (inferred). */
#include "types.h"

struct Obj00245240 {
    char pad[0x104];
    s32 unk104;
};

extern "C" void func_002B71D0(void *dest, s32 face);

extern "C" void *func_00245240(void *dest, struct Obj00245240 *face) {
    void *result = dest;

    func_002B71D0(dest, face->unk104);
    return result;
}
