/* Script setter set_stand: reads the integer argument (vtable slot 11, +0x58) and stores whether it is non-zero at +0xF8 of the object behind the
 * handle (func_00192A58 fills it, func_00192A00 with 2 releases it). */
#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}

extern "C" void func_00192A58(void *arg0, void *selfRef);
extern "C" void func_00192A00(void *arg0, s32 selfRef);

extern "C" void MPhotoMapWindow__set_stand(s32 *arg0, void *selfRef, s32 arg2, char **args) {
    s32 handle[4];
    s32 window;
    func_00192A58(handle, selfRef);
    window = handle[0];
    *(s32 *)((char *)window + 0xF8) = vcall_58((char *)(*(s32 *)(char *)args)) != 0;
    func_00192A00(handle, 2);
}
