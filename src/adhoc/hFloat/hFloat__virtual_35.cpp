#include "types.h"

struct RefCounter;

/* Layout backed by include/gt4/hFloat.h and config/class_layout.json:
 *   0x00: ref_count
 *   0x04: vtable (hFloat)
 *   0x08..0x0F: base fields
 *   0x10: unk10 (float value)
 */
struct hFloatLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    f32 unk10;
};

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(VObj_60 *o) {
    VEntry_60 *e = o->vtbl + 12;  /* slot 12: offset 0x60 */
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hFloat__virtual_35(hFloatLayout *arg0, s32 *arg1, void *arg2, void *arg3, VObj_60 **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 flag = 0;
    s32 *dst = arg1;

    if (arg0->unk10 != 0.0f) {
        if (vcall_60(*arg4) != 0.0f) {
            flag = 1;
        }
    }
    func_002FE278(buf0, (void *)flag);
    if (dst != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *dst = newVal;
    }
    func_002FC870(buf0, 0x2);
}
