/* Getter: returns the first float (+0) of the block that the object's pointer at +0x10 refers to. Sibling of 003F36C8 (+4) and 003F3748 (+0xC);
 * what the float means is purpose unknown. */
#include "types.h"

extern "C" f32 func_003F36B8(void *self) {
    return *(f32 *)*(void **)((char *)self + 0x10);
}
