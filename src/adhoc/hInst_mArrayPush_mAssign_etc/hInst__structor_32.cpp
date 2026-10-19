typedef int s32;

/* Layout backed by config/class_layout.json (mVariablePush size 0x1C):
 *   0x00: ref_count
 *   0x04: vtable (mVariablePush)
 *   0x08: path (HScopePath at 0x08)
 */
struct mVariablePushLayout {
    void *ref_count;
    void *vtable;
    char path[0x14];
};

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0030F808(void *arg0, s32 arg1);

extern void *hInst__vtable;
extern void *mVariablePush__vtable;

extern "C" void hInst__structor_32(void *arg0, s32 arg1) {
    mVariablePushLayout *self = (mVariablePushLayout *)arg0;
    self->vtable = &mVariablePush__vtable;
    func_0030F808(self->path, 2);
    self->vtable = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
