/* Script native for MGarage.cancelRidingCar (inferred from the symbol name): needs argc >= 2, otherwise it only builds and drops the context handle.
 * The garage object is the pointer at +0x10 of the context handle (func_0016D848). args[0] is an int through vtable slot 0x58, args[1] is wrapped by
 * func_0013BDC0 and its target converted with func_00147D80; both go to func_00435418(garage, int, converted). No value is written to ret. */
#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}

extern "C" s32 func_0016D848(void *unusedRet, void *ctx);
extern "C" void func_0016D7F0(void *unusedRet, s32 ctx);
extern "C" void func_0013BDC0(void *unusedRet, void *ctx);
extern "C" s32 func_00147D80(s32 unusedRet);
extern "C" void func_00435418(void *o, s32 a, s32 b);
extern "C" void func_0013BD68(void *unusedRet, s32 ctx);

extern "C" void MGarage__cancelRidingCar(s32 *unusedRet, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    char *garage;
    s32 firstInt;

    func_0016D848(handle, ctx);
    garage = *(char **)((char *)handle[0] + 0x10);
    func_0016D7F0(handle, 2);
    if (argc >= 0x2) {
        firstInt = vcall_58((char *)(*(s32 *)(char *)args));
        func_0013BDC0(handle, (char *)args + 4);
        func_00435418(garage, firstInt, func_00147D80(handle[0]));
        func_0013BD68(handle, 0x2);
    }
}
