#include "types.h"

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[12];
    return e->fn(o + e->delta);
}

extern "C" void * func_002F9360(void *, f32);
extern "C" void * func_002434C8(void *, void *);
extern "C" void func_00243470(void *, s32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct TextFaceData {
    char pad0[0x2C];
    f32 unk2C;
    char pad1[4];
    f32 unk34;
};

struct TextFaceObj {
    char pad0[0xA0];
    TextFaceData data;
};

extern "C" void MTextFace__get_scale_x(s32 *arg0, void *arg1, s32 arg2, VObj_60 **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    TextFaceObj *v_s0;
    TextFaceData *s0;
    f32 t1;
    if (arg2 <= 0) {
        p_s1 = buf1;
        func_002434C8(p_s1, arg1);
        func_002F9360(buf0, ((TextFaceObj *)(*p_s1))->data.unk2C);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(buf0, 0x2);
        func_00243470(p_s1, 0x2);
    } else {
        func_002434C8(buf0, arg1);
        v_s0 = (TextFaceObj *)buf0[0];
        s0 = &v_s0->data;
        t1 = vcall_60((char *)*arg3);
        s0->unk2C = t1;
        s0->unk34 = t1;
        func_00243470(buf0, 0x2);
    }
}
