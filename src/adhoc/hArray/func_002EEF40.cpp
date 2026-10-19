#include "types.h"

/* Layout backed by include/gt4/hArray.h and config/class_layout.json (size 0x24):
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: vector buffer / Holder:
 *         0x10: capacity / allocator (unk0)
 *         0x14: start (unk4)
 *         0x18: finish / top of stack (unk8)
 */
struct VectorHolder {
    s32 allocator;
    s32 start;
    s32 finish;
};

struct hArrayLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    VectorHolder elements;
};

extern "C" void func_00309360(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);

extern "C" void *func_002EEF40(void *arg0, hArrayLayout *arr) {
    s32 buf0[4];
    VectorHolder *h = &arr->elements;
    if (h->start != h->finish) {
        func_00309360(buf0, h->finish - 4);
        s32 p = h->finish - 4;
        h->finish = p;
        func_00309378((void *)p, 2);
        func_00309360(arg0, (s32)buf0);
        func_00309378(buf0, 2);
    } else {
        func_0030BB18(arg0);
    }
    return arg0;
}
