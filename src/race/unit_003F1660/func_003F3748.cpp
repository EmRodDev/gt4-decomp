/* Getter: returns the float at +0xC of the block that the object's pointer at +0x10 refers to. Sibling of 003F36B8 (+0) and 003F36C8 (+4);
 * what the float means is purpose unknown. */
#include "types.h"

extern "C" f32 func_003F3748(void *self) {
    return *(f32 *)((char *)*(void **)((char *)self + 0x10) + 0xC);
}
