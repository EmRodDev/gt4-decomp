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

extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);

extern "C" void hFloat__virtual_36(hFloatLayout *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_002F9360(buf0, -arg0->unk10);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_002F7B68(buf0, 0x2);
}
