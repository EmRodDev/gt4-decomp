typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, void *, s32, s32);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

/* Layout backed by include/gt4/hMethodObject.h and config/class_layout.json (size 0x18):
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: target object (HObject, size 4)
 *   0x14: method / function object (VObj *, size 4)
 */
struct hMethodObjectLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *target;
    VObj *method;
};

extern "C" void hMethodObject__call_const_2(hMethodObjectLayout *self, s32 a1, s32 a2, s32 a3) {
    VObj *o = self->method;
    VEntry *e = &o->vtbl[16];
    e->fn((char *)o + e->delta, a1, &self->target, a2, a3);
}

