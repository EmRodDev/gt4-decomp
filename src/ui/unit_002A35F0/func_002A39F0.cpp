/* Stores two signed bytes at +0xEC and +0xED of the object and then calls func_002A38A0 on it (an update/refresh step, inferred from the call after the stores).
 * Sibling func_002A3A30 does the same for +0xEE and +0xEF. */
#include "types.h"

struct Struct_002A39F0 {
    char pad[0xEC];
    s8 unkEC;
    s8 unkED;
};

extern "C" void func_002A38A0(Struct_002A39F0 *obj);

extern "C" void func_002A39F0(Struct_002A39F0 *obj, s8 first, s8 second) {
    obj->unkEC = first;
    obj->unkED = second;
    func_002A38A0(obj);
}
