#include "types.h"
#include "gt4/hFunctionObject.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

/* Layout backed by include/gt4/hFunctionObject.h (size 0x14):
 *   0x00..0x0F: base fields (0x04 vtable)
 *   0x10: unk10 (function pointer reference)
 */
struct hFunctionObjectLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *unk10;
};

extern char hFunctionObject__vtable[];
void func_002FA8A0(void *, s32 *);
s32 hObject__structor_0(void *);

void hFunctionObject__structor_0(void *arg0, s32 arg1) {
    struct hFunctionObjectLayout *self = (struct hFunctionObjectLayout *)arg0;
    s32 sp[4];
    hObject__structor_0(arg0);
    self->vtable = hFunctionObject__vtable;
    sp[0] = arg1;
    func_002FA8A0(&self->unk10, sp);
}
