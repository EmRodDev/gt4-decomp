/* Script accessor MGame.get_assist_asm (inferred from the symbol name): first player's ASM driving-aid flag, the one-player counterpart of get_assist_asm_2p.
 * The flag is the word at +0x54 of the assist block at game state+0xD8, so state+0x12C (state = object at +0x10 of the handle that func_0015F3E0 returns).
 * argc > 0 sets it from args[0] (vtable slot 0x58, compared with 0); argc == 0 reads it, boxes it with func_002FE278 and stores the handle into ret. */
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
extern "C" void func_0015F3E0(void *);
extern "C" void func_0015F388(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MGame__get_assist_asm(s32 *ret, void *ctx, s32 argc, char **args) {
    s32 handle[4];
    s32 assistBlock;
    s32 newVal;
    s32 oldVal;
    func_0015F3E0(handle);
    assistBlock = *(s32 *)((char *)handle[0] + 0x10) + 0xd8;
    func_0015F388(handle, 0x2);
    if (argc > 0) {
        *(s32 *)((char *)assistBlock + 0x54) = vcall_58((char *)(*(s32 *)(char *)args)) != 0;
    } else {
        func_002FE278(handle, *(s32 *)((char *)assistBlock + 0x54) != 0);
        if (ret != handle) {
            newVal = handle[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *ret;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *ret = newVal;
        }
        func_002FC870(handle, 0x2);
    }
}
