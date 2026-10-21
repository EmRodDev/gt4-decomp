/* Deleting destructor shape: stores the class's vtable pointer (D_00688C40) at +0x8, runs the base-class destructor func_0057CA38, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
typedef int s32;

extern "C" void func_0057CA38(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688C40;

struct func_0060A4B0_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0060A4B0(struct func_0060A4B0_arg0 *self, s32 deleteFlag) {
    self->unk8 = &D_00688C40;
    func_0057CA38(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
