/* Frees the heap block pointed to by +0xD4 (when non-null, clearing the pointer first) and then calls func_001FD5E8, which frees the one at +0xD8.
 * A two-buffer release routine. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FD5E8(void *);                      /* extern */
s32 free(s32);                         /* extern */

struct func_001FD5A8_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_001FD5A8(void *obj) {
    s32 block;

    block = ((struct func_001FD5A8_arg0 *)obj)->unkD4;
    if (block != 0) {
        ((struct func_001FD5A8_arg0 *)obj)->unkD4 = 0;
        free(block);
    }
    func_001FD5E8(obj);
}
