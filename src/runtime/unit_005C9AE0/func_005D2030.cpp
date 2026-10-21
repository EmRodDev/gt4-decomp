/* Deleting destructor shape: stores the class's vtable pointer (D_006614F8) at +0x4C, runs the base-class destructor func_001CC060, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006614F8;

struct func_005D2030_arg0 {
    char pad0[0x4C];
    void *unk4C;
};

extern "C" void func_005D2030(struct func_005D2030_arg0 *self, int deleteFlag) {
    self->unk4C = &D_006614F8;
    func_001CC060(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
