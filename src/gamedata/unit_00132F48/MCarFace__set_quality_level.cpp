/* Script setter MCarFace.set_quality_level (inferred from the symbol name): stores args[0], read through vtable slot 0x58, into the int at +0xA4 of the face object.
 * The face object is the target of the handle func_00137DB8 builds from the context; the handle is destroyed afterwards (func_00137D60, 2).
 * Unlike most setters here it does not test argc first, so a call without arguments would read a missing slot. ret is untouched. */
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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}
extern "C" void func_00137DB8(void *, void *);
extern "C" void func_00137D60(void *, s32);

extern "C" void MCarFace__set_quality_level(s32 *unusedRet, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    s32 face;
    s32 level;
    func_00137DB8(handle, ctx);
    face = handle[0];
    level = vcall_58((char *)(*(s32 *)(char *)args));
    *(s32 *)((char *)face + 0xa4) = level;
    func_00137D60(handle, 0x2);
}
