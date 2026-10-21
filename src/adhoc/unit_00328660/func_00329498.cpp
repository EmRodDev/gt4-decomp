/* Reads the pointer stored in the word just before the object, loads its first word and passes it with the object to func_00329108 (shape of a sized free of an array-with-header block, inferred; purpose unknown). */
#include "types.h"

extern "C" void func_00329108(s32 self, void *arg1);

extern "C" void func_00329498(void *self) {
    s32 *vtbl = *(s32 **)((char *)self - 4);
    func_00329108(*vtbl, self);
}
