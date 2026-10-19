#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32);
};

struct Obj2 {
    char pad0[4];
    VEntry *vtbl;
};

/* Layout backed by include/gt4/hArrayElement.h and config/class_layout.json (size 0x18):
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: target array / object (Obj2 *)
 *   0x14: index (s32)
 */
struct hArrayElementLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    struct Obj2 *array;
    s32 index;
};

extern "C" void hArrayElement__assign(hArrayElementLayout *arg0, s32 arg1) {
    struct Obj2 *self2 = arg0->array;
    s32 val = arg0->index;
    VEntry *e = &self2->vtbl[15];

    e->fn((char *)self2 + e->delta, val, arg1);
}

