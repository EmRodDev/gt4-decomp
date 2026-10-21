/* Script setter set_view_angle: reads the float argument (vtable slot 12, +0x60, a float getter, inferred from its return type) and stores it at +0xF4
 * of the object behind the handle (func_00192A58 fills the handle, func_00192A00 with 2 releases it). The first and third parameters are unused. */
#include "types.h"
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[12];
    return e->fn(o + e->delta);
}
extern "C" void func_00192A58(void *, void *);
extern "C" void func_00192A00(void *, s32);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void MPhotoMapWindow__set_view_angle(void *arg0, void *arg1, s32 arg2, char **args) {
    A handle;
    float angle = vcall_60(*args);
    func_00192A58(&handle, arg1);
    *(float *)((char *)handle.p + 0xF4) = angle;
    func_00192A00(&handle, 2);
}
