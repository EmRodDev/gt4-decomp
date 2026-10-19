/* Layout backed by config/class_layout.json (mStringConst size 0x0C):
 *   0x00..0x07: base
 *   0x08: value
 */
typedef int s32;

struct mStringConstLayout {
    void *ref_count;
    void *vtable;
    s32 value;
};

extern "C" void func_002FFA40(s32 arg0, void *arg1);

extern "C" void mStringConst__read(mStringConstLayout *self, s32 arg1) {
    func_002FFA40(arg1, &self->value);
}
