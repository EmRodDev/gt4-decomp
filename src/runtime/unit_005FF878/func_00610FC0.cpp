/* Deleting destructor shape: stores the class's vtable pointer (D_00689970) at +0x60, runs the base-class destructor func_00556450, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void func_00556450(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689970;

struct func_00610FC0_arg0 {
    char pad0[0x60];
    void *unk60;
};

extern "C" void func_00610FC0(struct func_00610FC0_arg0 *self, int deleteFlag) {
    self->unk60 = &D_00689970;
    func_00556450(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
