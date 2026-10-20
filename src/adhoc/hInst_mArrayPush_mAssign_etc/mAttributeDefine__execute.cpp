#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" s32 HValue__isValid(void *);
extern "C" s32 func_00322060(void *);
extern "C" void func_0032BD38(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0032BA00(void *, s32);
extern "C" void func_003065F0(s32, void *);

/* Layout backed by config/class_layout.json (size 0x10, 16 bytes), mDefine base, and mAttributeDefine__structor_0.cpp:
 *   0x00: ref_count
 *   0x04: vtable (mAttributeDefine)
 *   0x08: sym_id (from mDefine base)
 *   0x0C: attr_value / value cache (HValue at 0x0C, initialized by func_00323D08)
 */
struct mAttributeDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    s32 attr_value;
};

extern "C" void mAttributeDefine__execute(mAttributeDefineLayout *self, void *arg1) {
    s32 buf0[4];
    s32 *v_s1 = &self->attr_value;
    s32 v_s3;
    s32 v_s0;
    if (HValue__isValid(v_s1) == 0) {
        v_s3 = func_00322060(arg1);
        func_0032BD38(buf0, &self->sym_id);
        v_s0 = buf0[0];
        if (v_s1 != buf0) {
            if (v_s0 != 0) {
                func_003285A8(v_s0);
            }
            if (*v_s1 != 0) {
                func_003285F8(*v_s1);
            }
            *v_s1 = v_s0;
        }
        func_0032BA00(buf0, 0x2);
        func_003065F0(v_s3, v_s1);
    }
}
