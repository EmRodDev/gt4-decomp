#include "gt4/hThreadGroup.h"
typedef int s32;

extern void *hThreadGroup__vtable;
extern "C" void func_005F1AE0(void *);
extern "C" void *func_005F1BC0(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_00318538(void *, s32);
extern "C" void hObject__structor_2(void *, s32);
/* Layout backed by config/class_layout.json (size 0x1C) and hThreadGroup__structor_0.cpp:
 *   0x00: ref_count
 *   0x04: vtable (hThreadGroup)
 *   0x08..0x0F: base words
 *   0x10: alloc
 *   0x14: list
 */
struct hThreadGroupNodeHolder {
    void *pad0;
    void *node;
};

struct hThreadGroupDestruct {
    void *ref_count;
    void *vtable;
    s32 base_words[2];
    s32 alloc;
    hThreadGroupNodeHolder list;
};

static inline void member_0(hThreadGroupNodeHolder *m) {
    func_005F1AE0(m);
    void *p0 = m->node;
    void *r1 = func_005F1BC0();
    func_00326798(p0, 0xc, 0x4, *(void **)(r1));
}

extern "C" void hThreadGroup__structor_1(hThreadGroupDestruct *self, s32 arg1) {
    self->vtable = &hThreadGroup__vtable;
    member_0(&self->list);
    func_00318538(&self->alloc, 0x2);
    hObject__structor_2(self, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(self, 0x1c, 0x4, "RefCounter");
    }
}
