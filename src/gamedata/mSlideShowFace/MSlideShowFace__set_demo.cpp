/* Script setter MSlideShowFace.set_demo (inferred from the symbol name): stores args[0] != 0 into the word at +0x1DD8 of the block at +0xBC of the face (so face+0x1E94).
 * The face comes from the handle func_001AA0F8 builds from the context and is released with func_001AA0A0(handle, 2). It does not test argc, and ret is not written. */
#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}

extern "C" void func_001AA0F8(void *unusedRet, void *ctx);
extern "C" void func_001AA0A0(void *unusedRet, s32 ctx);

extern "C" void MSlideShowFace__set_demo(s32 *unusedRet, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    s32 face;
    char *block;
    func_001AA0F8(handle, ctx);
    face = handle[0];
    block = (char *)face + 0xBC;
    *(s32 *)(block + 0x1DD8) = vcall_58((char *)(*(s32 *)(char *)args)) != 0;
    func_001AA0A0(handle, 0x2);
}
