#include "gt4/hFileIO.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *hFileIO__vtable;
extern "C" void hFileIO__virtual_53(void *);
extern "C" void func_005C1648(void *);
extern "C" void func_004AFE60(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void hIO__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


/* Layout backed by config/class_layout.json (size 0xFC) and config/class_fields.json:
 *   0x00..0x13: hIO base fields (0x04 vtable, 0x10 unk10)
 *   0x14: path Str (file path string)
 *   0x18: stream / file handle (dtor func_004AFE60)
 *   0xEC: buffer pointer (func_005C1648)
 *   0xF8: buffer length / flag
 */
struct hFileIODestructLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[3];
    Str path;
    char stream_handle[0xD0];
    s32 unkE8;
    void *unkEC;
    char padF0[0x8];
    void *unkF8;
};

extern "C" void hFileIO__structor_1(hFileIODestructLayout *self, s32 arg1) {
    self->vtable = &hFileIO__vtable;
    hFileIO__virtual_53(self);
    if (self->unkF8 != 0) {
        if (self->unkEC != 0) {
            func_005C1648(self->unkEC);
        }
    }
    func_004AFE60(self->stream_handle, 0x2);
    str_release(&self->path);
    hIO__structor_1(self, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(self, 0xfc, 0x4, "RefCounter");
    }
}
