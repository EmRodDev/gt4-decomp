#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char data[1];
};

extern Rep D_00659FA8;
extern void *mColorChipFace__vtable;
extern "C" void *mWidget__structor_0(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_00210810(void *);
extern "C" void *func_005A48D8(void *, s32, s32);

struct mColorChipFaceLayout {
    void *ref_count;          /* 0x00 */
    void *vtable;             /* 0x04: mColorChipFace vtable */
    char widget_body[0x98];   /* 0x08..0x9F: mWidget base fields */
    char *strings[2];         /* 0xA0, 0xA4: color/face string references */
    void *subobject1;         /* 0xA8 */
    void *subobject2;         /* 0xAC */
    s16 flags;                /* 0xB0 */
    char padB2[0x22];         /* 0xB2..0xD3 */
    char tail[8];             /* 0xD4..0xDB: cleared at construction */
};

extern "C" void *mColorChipFace__structor_0(struct mColorChipFaceLayout *self) {
    void *base = mWidget__structor_0(self);
    (void)base;
    Rep *rep = &D_00659FA8;
    self->vtable = &mColorChipFace__vtable;
    char **slot = &self->strings[0];
    for (s32 count = 1; count != -1; --count) {
        char *value;
        if (rep->sel != 0) {
            value = func_005C2560(rep);
        } else {
            value = rep->data;
            ++rep->ref;
        }
        *slot = value;
        slot++;
    }
    func_00210810(&self->subobject1);
    func_00210810(&self->subobject2);
    self->flags = 0;
    return func_005A48D8(self->tail, 0, 8);
}
