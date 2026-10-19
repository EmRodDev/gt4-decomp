typedef int s32;

/* Layout backed by config/class_layout.json (mUndef size 0x18):
 *   0x00..0x07: base
 *   0x08: sym_id / scope path at 0x08
 */
struct mUndefLayout {
    void *ref_count;
    void *vtable;
    char path[0x10];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_00323D08(Handle *h);
extern "C" void func_00321E38(void *arg0, Handle *h, void *arg2);
extern "C" void func_00323BD0(void *p);
extern "C" void func_00323B60(Handle *h, s32 flags);

extern "C" void mUndef__read(void *self, void *arg1) {
    mUndefLayout *node = (mUndefLayout *)self;
    Handle h;
    func_00323D08(&h);
    func_00321E38(arg1, &h, node->path);
    if (h.p != 0) {
        func_00323BD0(h.p);
    }
    func_00323B60(&h, 2);
}
