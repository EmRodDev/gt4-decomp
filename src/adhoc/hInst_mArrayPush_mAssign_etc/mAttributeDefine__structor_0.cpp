/* Layout backed by config/class_layout.json and include/gt4/mAttributeDefine.h (size 0x10):
 *   0x00..0x07: base (ref_count, vtable)
 *   0x08: sym_id
 *   0x0C: target
 */
struct mAttributeDefineLayout {
    void *ref_count;
    void *vtable;
    int sym_id;
    void *target;
};

extern "C" void *mDefine__structor_0(void *arg0);
extern "C" void *func_00323D08(void *arg0);
extern "C" char mAttributeDefine__vtable[];

extern "C" void *mAttributeDefine__structor_0(void *arg0) {
    mAttributeDefineLayout *self = (mAttributeDefineLayout *)arg0;
    mDefine__structor_0(self);
    self->vtable = mAttributeDefine__vtable;
    return func_00323D08(&self->target);
}
