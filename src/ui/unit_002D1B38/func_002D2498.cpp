/* If the field at +0x20 is nonzero, calls func_002D2288 with no arguments. The declared s32 return value is never set (the original falls off the end), which is why there is no return statement. */
extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D2288(...) throw();

struct func_002D2498_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_002D2498(char *obj) {
    if (((struct func_002D2498_arg0 *)obj)->unk20 != 0) {
        func_002D2288();
    }
}

}
