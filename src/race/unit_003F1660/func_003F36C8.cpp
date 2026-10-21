/* Getter: returns the float at +4 of the block that the object's pointer at +0x10 refers to. Sibling of 003F36B8 (+0) and 003F3748 (+0xC);
 * the only caller found (engine 0045B978) passes several of these as float parameters to one setup call, so they are a table of float
 * parameters (inferred from that caller); the meaning of each is purpose unknown. */
#include "types.h"

extern "C" f32 func_003F36C8(void *self) {
    return *(f32 *)((char *)*(void **)((char *)self + 0x10) + 0x4);
}
