/* Destructor-shaped function (inferred from the flag in the second argument): installs the vtable at D_00659BA0 into the object at
 * +0x64, runs the base destructor func_0010AAA0, and when bit 0 of the flags is set also frees the object with func_005C1628. */
extern "C" void func_0010AAA0(void *self, void *flags);
extern "C" void func_005C1628(void *self);

extern void *D_00659BA0;

struct func_00102888_arg0 {
    char pad0[0x64];
    void *vtable;
};

extern "C" void func_00102888(struct func_00102888_arg0 *self, int deleteFlags) {
    self->vtable = &D_00659BA0;
    func_0010AAA0(self, 0);
    if (deleteFlags & 1) {
        return func_005C1628(self);
    }
}
