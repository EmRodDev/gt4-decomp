#include "types.h"
#include "gt4/hMethodObject.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

/* Layout backed by include/gt4/hMethodObject.h (size 0x18):
 *   0x00..0x0F: base fields (0x04 vtable)
 *   0x10: target object (size 4)
 *   0x14: method pointer (size 4)
 */
struct hMethodObjectLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *target;
    void *method;
};

extern char hMethodObject__vtable[];
void func_003038B0(void *, s32 *);
void func_00309360(void *, s32);
s32 hObject__structor_0(void *);

void hMethodObject__structor_0(void *arg0, s32 arg1, s32 arg2) {
    struct hMethodObjectLayout *self = (struct hMethodObjectLayout *)arg0;
    s32 sp[4];
    hObject__structor_0(arg0);
    self->vtable = hMethodObject__vtable;
    func_00309360(&self->target, arg1);
    sp[0] = arg2;
    func_003038B0(&self->method, sp);
}
