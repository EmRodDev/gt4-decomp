#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

/* Really void; declared s32 because the compiler schedules the caller's tail
   differently (and the caller keeps v0 = -1) only with a value-returning callee. */
s32 func_004EF4D8(char *arg0);

extern char D_006895D8[];
struct func_004EEA00_arg0 {
    char pad0[0x90];
    s32 unk90;
    s32 unk94;
    s32 unk98;
};

s32 func_004EEA00(struct func_004EEA00_arg0 *arg0) {
    func_004EF4D8((char *)arg0);
    arg0->unk94 = -1;
    arg0->unk90 = (s32)D_006895D8;
    arg0->unk98 = 0;
}
