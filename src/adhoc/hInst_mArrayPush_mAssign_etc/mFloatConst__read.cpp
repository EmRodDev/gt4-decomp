/* Layout backed by config/class_layout.json (mFloatConst size 0x0C):
 *   0x00..0x07: base
 *   0x08: value
 */
typedef int s32;

struct mFloatConstLayout {
    void *ref_count;
    void *vtable;
    float value;
};

extern "C" void HIO__operator_shr_3(s32 arg0, void *arg1);

extern "C" void mFloatConst__read(mFloatConstLayout *self, s32 arg1) {
    HIO__operator_shr_3(arg1, &self->value);
}
