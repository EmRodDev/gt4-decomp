#include "gt4/mColorChipFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mColorChipFace__vtable;
extern "C" void func_00210710(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


struct mColorChipFaceLayout {
    void *ref_count;          /* 0x00 */
    void *vtable;             /* 0x04: mColorChipFace vtable */
    char widget_body[0x98];   /* 0x08..0x9F: mWidget base fields */
    Str strings[2];           /* 0xA0, 0xA4: color/face string references */
    void *subobjects[2];      /* 0xA8, 0xAC */
    short flags;              /* 0xB0 */
};

extern "C" void mColorChipFace__structor_1(mColorChipFaceLayout *self, s32 arg1) {
    self->vtable = &mColorChipFace__vtable;
    if (self->subobjects != 0) {
        void **p0 = (void **)&self->flags;
        while (self->subobjects != p0) {
            p0--;
            func_00210710(p0, 0x2);
        }
    }
    if (self->strings != 0) {
        Str *p1 = (Str *)self->subobjects;
        while (self->strings != p1) {
            p1--;
            str_release(p1);
        }
    }
    mWidget__structor_1(self, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(self, 0xdc, 0x4, "RefCounter");
    }
}
