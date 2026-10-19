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
extern "C" void func_0030BB18(void *);
extern "C" void func_00311B90(void *, void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00311790(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_003065F0(s32, void *);

/* Layout backed by config/class_layout.json (size 0x10, 16 bytes), mDefine base, and class hierarchy:
 *   0x00: ref_count
 *   0x04: vtable (mStaticDefine)
 *   0x08: sym_id (from mDefine base)
 *   0x0C: static_value / cached static slot (HValue at 0x0C)
 */
struct mStaticDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    s32 static_value;
};

extern "C" void mStaticDefine__execute(mStaticDefineLayout *self, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *v_s1 = &self->static_value;
    s32 *v_s3 = &self->sym_id;
    s32 *p_s2;
    s32 t1;
    s32 v_s4;
    s32 v_s0;
    if (HValue__isValid(v_s1) == 0) {
        t1 = func_00322060(arg1);
        p_s2 = buf2;
        v_s4 = t1;
        func_0030BB18(p_s2);
        func_00311B90(buf0, v_s3, p_s2);
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
        func_00311790(buf0, 0x2);
        func_00309378(p_s2, 0x2);
        func_003065F0(v_s4, v_s1);
    }
}
