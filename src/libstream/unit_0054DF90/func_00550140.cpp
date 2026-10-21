/* Adds delta to the counter at +0x34 between a func_005ADCE0 call and a func_005ADCC0 call on the handle at +0x38
 * (inferred: lock / unlock bracket around the update). */
extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADCC0(...) throw();
s32 func_005ADCE0(...) throw();

struct func_00550140_arg0 {
    char pad0[0x34];
    s32 unk34;
    s32 unk38;
};

void func_00550140(char *self, s32 delta) {
    func_005ADCE0(((struct func_00550140_arg0 *)self)->unk38);
    ((struct func_00550140_arg0 *)self)->unk34 = (s32) (((struct func_00550140_arg0 *)self)->unk34 + delta);
    func_005ADCC0(((struct func_00550140_arg0 *)self)->unk38);
}

}
