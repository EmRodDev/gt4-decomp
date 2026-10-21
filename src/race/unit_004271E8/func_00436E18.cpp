/* Bounds-checked virtual call on one element of the collection at +0x11D0: if index is below the collection size
 * (func_0043DA38) the element reference is fetched with func_0043DA60 and the method at offset 0x48 of the referenced
 * object's table (slot 9 at 8 bytes per entry; inferred) is called with callArg. Returns 0 for an out-of-range index. */
#include "types.h"

struct VEntry_00436E18 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj_00436E18 {
    char pad0[0x48];
    VEntry_00436E18 entry;
};

extern "C" s32 func_0043DA38(void *arg0);
extern "C" void **func_0043DA60(void *arg0, s32 arg1);

extern "C" s32 func_00436E18(void *self, s32 index, s32 callArg) {
    void *collection = (char *)self + 0x11D0;
    if (index < func_0043DA38(collection)) {
        void **elementRef = func_0043DA60(collection, index);
        Obj_00436E18 *vtable = (Obj_00436E18 *)(*(s32 *)elementRef);
        VEntry_00436E18 *entry = &vtable->entry;
        return entry->fn((char *)elementRef + entry->delta, callArg);
    }
    return 0;
}
