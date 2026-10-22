/* Script setter MMusic.set_repeat (inferred from the symbol name): sets the repeat flag of the music object.
 * With argc > 0 it takes the object from the context handle (func_002C28D0), addresses the sub-block at +0x18 and writes (args[0] via vtable slot 0x58) != 0
 * to the word at +4 of that block (object+0x1C), then destroys the handle with func_002C2878(handle, 2). Nothing is returned. */
#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}

extern "C" void func_002C28D0(void *unusedRet, void *ctx);
extern "C" void func_002C2878(void *unusedRet, s32 ctx);

extern "C" void MMusic__set_repeat(s32 *unusedRet, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    s32 music;
    char *block;
    if (argc > 0) {
        func_002C28D0(handle, ctx);
        music = handle[0];
        block = (char *)music + 0x18;
        *(s32 *)(block + 0x4) = vcall_58((char *)(*(s32 *)(char *)args)) != 0;
        func_002C2878(handle, 2);
    }
}
