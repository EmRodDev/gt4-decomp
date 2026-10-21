/* Deleting destructor shape: stores the class's vtable pointer (D_006611F0) at +0x4C, runs the base-class destructor func_001CC060, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
extern "C" void free(int arg0);
extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006611F0;
extern void *D_006614F8;

struct func_005D2250_arg0 {
    char pad0[0x4C];
    void *unk4C;
    char pad50[0x4];
    int unk54;
};

extern "C" void func_005D2250(struct func_005D2250_arg0 *self, int deleteFlag) {
    int temp_v1;

    self->unk4C = &D_006611F0;
    temp_v1 = self->unk54;
    if (temp_v1 != 0) {
        free(temp_v1);
    }
    self->unk4C = &D_006614F8;
    func_001CC060(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
