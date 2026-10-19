/* Layout backed by config/class_layout.json (mLogicalOr size 0x0C):
 *   0x00..0x07: base
 *   0x08: target_offset
 */
typedef int s32;

struct mLogicalOrLayout {
    void *ref_count;
    void *vtable;
    s32 target_offset;
};

extern "C" void HIO__operator_shr_2(s32 arg0, void *arg1);

extern "C" void mLogicalOr__read(mLogicalOrLayout *self, s32 arg1) {
    HIO__operator_shr_2(arg1, &self->target_offset);
}
