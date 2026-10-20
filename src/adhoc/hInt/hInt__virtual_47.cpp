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

/* Layout backed by include/gt4/hInt.h and config/class_layout.json:
 *   0x00: ref_count
 *   0x04: vtable (hInt)
 *   0x08..0x0F: base fields
 *   0x10: unk10 (integer value)
 */
struct hIntLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    s32 unk10;
};

extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void hInt__virtual_47(hIntLayout *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_002FE278(buf0, ~arg0->unk10);
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
    func_002FC870(buf0, 0x2);
}
