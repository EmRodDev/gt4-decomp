/* Deleting destructor shape: stores the class's vtable pointer (D_00659E80) at +0x64, runs the base-class destructor func_00101078, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void func_00101078(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659E80;

struct func_00108FE0_arg0 {
    char pad0[0x64];
    void *unk64;
};

extern "C" void func_00108FE0(struct func_00108FE0_arg0 *self, int deleteFlag) {
    self->unk64 = &D_00659E80;
    func_00101078(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
