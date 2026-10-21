/* Stores two signed bytes at +0xEE and +0xEF of the object and then calls func_002A38A0 on it (an update/refresh step, inferred from the call after the stores).
 * Sibling of func_002A39F0, which writes +0xEC and +0xED. */
#include "types.h"

struct Struct_002A3A30 {
    char pad[0xEE];
    s8 unkEE;
    s8 unkEF;
};

extern "C" void func_002A38A0(Struct_002A3A30 *obj);

extern "C" void func_002A3A30(Struct_002A3A30 *obj, s8 first, s8 second) {
    obj->unkEE = first;
    obj->unkEF = second;
    func_002A38A0(obj);
}
