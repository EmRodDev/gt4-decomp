typedef int s32;

extern "C" void func_003286B8(s32 arg0);
extern "C" void func_0030F808(void *arg0, s32 arg1);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mClassDefine__vtable;

/* Layout backed by config/class_layout.json (size 0x20) and config/class_fields.json:
 *   0x04: vptr
 *   0x0C: class name / symbol handle object (dtor func_0030F808)
 *   0x1C: unk1C (released via func_003286B8)
 */
struct mClassDefineLayout {
    void *ref_count;
    void *vtable;
    s32 unk8;
    char class_handle[0x10];   /* 0x0C..0x1B */
    s32 unk1C;                 /* 0x1C */
};

extern "C" void hInst__structor_7(mClassDefineLayout *self, s32 arg1) {
    self->vtable = &mClassDefine__vtable;
    s32 p = self->unk1C;
    if (p != 0) {
        func_003286B8(p);
    }
    func_0030F808(self->class_handle, 2);
    self->vtable = &hInst__vtable;
    RefCounter__structor_2(self, 0);
    if (arg1 & 1) {
        return func_00326798(self, 0x20, 4, "RefCounter");
    }
}
