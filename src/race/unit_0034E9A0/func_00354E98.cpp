/* Getter: follows the pointer at +0x10 of the object and returns the float at +0x10D8 of what it points to. What that block is and what the
 * float means is purpose unknown (no caller or name evidence found). */
#include "types.h"

extern "C" f32 func_00354E98(void *self) {
    return *(f32 *)((char *)*(void **)((char *)self + 0x10) + 0x10D8);
}
