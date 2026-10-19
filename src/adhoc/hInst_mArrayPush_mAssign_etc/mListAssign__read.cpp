/* Layout backed by config/class_layout.json (mListAssign size 0x0C):
 *   0x00..0x07: base
 *   0x08: count
 */
typedef int s32;

struct mListAssignLayout {
    void *ref_count;
    void *vtable;
    s32 count;
};

extern "C" void HIO__operator_shr(s32 arg0, void *arg1);

extern "C" void mListAssign__read(mListAssignLayout *self, s32 arg1) {
    HIO__operator_shr(arg1, &self->count);
}
