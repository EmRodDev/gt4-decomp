/* Changes the option menu selection: func_002C9740 resolves the key (arg2) to an index; when it is valid (>= 0) it is stored in the index field at +0xD8 through func_0057CE40,
 * then, if arg1 is nonzero, func_002C8198 is notified with it. Roles of arg1 and the callees are inferred from the call order only. */
#include "types.h"
struct S {
    char pad0[0xD8];
    void *unkD8;
};
extern "C" void func_002C8198(S *menu, s32 notifyArg);
extern "C" s32 func_002C9740(S *menu, s32 notifyArg);
extern "C" void func_0057CE40(void *menu, s32 notifyArg);

extern "C" void func_002C9898(S *menu, s32 notifyArg, s32 lookupKey) {
    s32 resolvedIndex = func_002C9740(menu, lookupKey);
    if (resolvedIndex >= 0) {
        func_0057CE40(&menu->unkD8, resolvedIndex);
    }
    if (notifyArg != 0) {
        func_002C8198(menu, notifyArg);
    }
}
