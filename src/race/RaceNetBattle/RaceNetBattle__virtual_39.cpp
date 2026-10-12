#include "types.h"

extern char D_00645570[];

extern "C" void func_00388880(void *self);
extern "C" void func_00394A98(void *owner, s32 src);
extern "C" void func_004FAF50(void *g);

extern "C" void func_00338EB8(char *arg0) {
    char *g;

    func_00388880(arg0);
    func_00394A98(arg0 + 0x1E7A8, *(s32 *)(arg0 + 0x6C));
    g = D_00645570;
    *(s32 *)(arg0 + 0x1ED24) = 0;
    func_004FAF50(g);
    *(s32 *)(arg0 + 0x22C4C) = *(s32 *)(g + 0xFD8);
}
