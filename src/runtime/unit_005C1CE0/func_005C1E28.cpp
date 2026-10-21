/* Deleting destructor shape: stores the class's vtable pointer (D_00659B88) at +0x8, runs the base-class destructor func_00578F48, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
typedef int s32;

extern "C" void func_00578F48(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659B88;

struct func_005C1E28_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_005C1E28(struct func_005C1E28_arg0 *self, s32 deleteFlag) {
    self->unk8 = &D_00659B88;
    func_00578F48(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
