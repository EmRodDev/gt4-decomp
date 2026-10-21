/* Starts the 'quick-practice' mode: raises the busy flags (+0xD48 on this object, +0xDC on the object at +0x6C), runs the
 * setup calls and func_0010FE40("quick-practice"), then makes one virtual call through slot +0x2C0 of the vtable at +0x64
 * and lowers both flags again. The flags bracket the whole run (inferred from set-then-clear). What the other callees do is unknown. */
extern "C" void func_00387EF0(void *self, int a, int b);
extern "C" void func_0012BFC0(void *self);
extern "C" void func_0012BFD0(int value);
extern "C" void func_0010FE40(const char *modeName);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

struct func_00119890_arg0 {
    char pad0[0x64];
    void *vtable;
    char pad68[0xCE0];
    int busyFlagD48;
};

extern "C" void func_00119890(void *self) {
    *(int *)((char *)*(void **)((char *)self + 0x6C) + 0xDC) = 1;
    ((struct func_00119890_arg0 *)self)->busyFlagD48 = 1;
    func_00387EF0(self, 4, 1);
    func_0012BFC0(self);
    func_0012BFD0(1);
    func_0010FE40("quick-practice");
    func_0012BFC0(0);

    void *vtbl = ((struct func_00119890_arg0 *)self)->vtable;
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2C0);
    entry->fn((char *)self + entry->delta);

    ((struct func_00119890_arg0 *)self)->busyFlagD48 = 0;
    *(int *)((char *)*(void **)((char *)self + 0x6C) + 0xDC) = 0;
}
