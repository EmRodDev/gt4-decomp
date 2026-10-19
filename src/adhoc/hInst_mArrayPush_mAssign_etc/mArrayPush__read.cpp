/* Layout backed by config/class_layout.json (mArrayPush size 0x0C):
 *   0x00..0x07: base
 *   0x08: sym_id
 */
typedef int s32;

struct mArrayPushLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
};

extern "C" void HIO__operator_shr(s32 arg0, void *arg1);

extern "C" void mArrayPush__read(mArrayPushLayout *self, s32 arg1) {
    HIO__operator_shr(arg1, &self->sym_id);
}
