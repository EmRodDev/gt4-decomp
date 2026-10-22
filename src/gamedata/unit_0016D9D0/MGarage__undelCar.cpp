/* Script native for MGarage.undelCar (inferred from the symbol name): restores a deleted car; takes an int and an optional flag.
 * With argc > 0 the garage pointer is read from +0x10 of the context handle (func_0016D848) and the handle is destroyed at once. args[0] (vtable slot 0x58)
 * is the int; the flag is args[1] != 0 when argc >= 2, else 0. All three go to func_004358C8(garage, int, flag). ret is not written. */
#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}

extern "C" void func_0016D7F0(void *unusedRet, int ctx);
extern "C" void func_0016D848(void *unusedRet, void *ctx);
extern "C" void func_004358C8(void *unusedRet, s32 ctx, s32 argc);

extern "C" void MGarage__undelCar(s32 *unusedRet, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    s32 garage;
    s32 firstInt;
    s32 flag;
    if (argc > 0) {
        func_0016D848(handle, ctx);
        garage = ((s32 *)handle[0])[4];
        func_0016D7F0(handle, 2);
        firstInt = vcall_58((char *)(*(s32 *)(char *)args));
        flag = 0;
        if (!((argc < 0x2))) {
            flag = vcall_58((char *)(*(s32 *)((char *)args + 4))) != 0;
        }
        func_004358C8((void *)garage, firstInt, flag);
    }
}
