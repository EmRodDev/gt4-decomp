typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(VObj_58 *o) {
    VEntry_58 *e = o->vtbl + 11;  /* slot 11: offset 0x58 */
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hInt__virtual_35(hIntLayout *arg0, s32 *arg1, void *arg2, void *arg3, VObj_58 **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 flag = 0;

    if (arg0->unk10 != 0) {
        flag = vcall_58(*arg4) != 0;
    }
    func_002FE278(buf0, (void *)flag);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_002FC870(buf0, 0x2);
}
