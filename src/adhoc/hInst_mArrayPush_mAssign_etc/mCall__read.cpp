/* Layout backed by config/class_layout.json (mCall size 0x0C):
 *   0x00..0x07: base
 *   0x08: arg_count
 */
typedef int s32;

struct mCallLayout {
    void *ref_count;
    void *vtable;
    s32 arg_count;
};

extern "C" void HIO__operator_shr(s32 arg0, void *arg1);

extern "C" void mCall__read(mCallLayout *self, s32 arg1) {
    HIO__operator_shr(arg1, &self->arg_count);
}
