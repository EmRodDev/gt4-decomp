typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x4];
    char *vtbl;
};

extern "C" void func_00105728(s32 *arg0);

extern "C" void func_00217FC0(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x1D0);
    e->fn((char *)self + e->delta);
    func_00105728((s32 *)((char *)self + 0x1D5C));
}
