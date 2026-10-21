/* Deleting destructor shape: stores the class's vtable pointer (D_00689E30) at +0x4, runs the base-class destructor func_00577910, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void func_00577910(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689E30;

struct func_00577E38_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_00577E38(struct func_00577E38_arg0 *self, int deleteFlag) {
    self->unk4 = &D_00689E30;
    func_00577910(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
