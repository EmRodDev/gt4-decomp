/* Deleting destructor shape: stores the class's vtable pointer (D_00689850) at +0x38, runs the base-class destructor func_00578090, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void func_00578090(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689850;

struct func_00550B20_arg0 {
    char pad0[0x38];
    void *unk38;
};

extern "C" void func_00550B20(struct func_00550B20_arg0 *self, int deleteFlag) {
    self->unk38 = &D_00689850;
    func_00578090(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
