#include "types.h"

/* Layout backed by include/gt4/hFloat.h and config/class_layout.json (size 0x14):
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

extern "C" s32 hFloat__toInt(hFloatLayout *arg0) {
    return (s32)arg0->unk10;
}

