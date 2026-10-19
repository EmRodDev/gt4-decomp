/* Layout backed by config/class_layout.json (mStringPush size 0x0C):
 *   0x00..0x07: base
 *   0x08: value
 */
typedef int s32;

struct mStringPushLayout {
    void *ref_count;
    void *vtable;
    s32 value;
};

extern "C" void HIO__operator_shr(s32 arg0, void *arg1);

extern "C" void mStringPush__read(mStringPushLayout *self, s32 arg1) {
    HIO__operator_shr(arg1, &self->value);
}
