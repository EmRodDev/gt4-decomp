/* Initialises a small container header (inferred from the self-referencing pointer): the count at +0xC becomes 1 and the pointer
 * at +8 is set to the address 0x18 bytes into the same object, as if the first element were stored inline right after the header. */
#include "types.h"
struct Obj {
    char pad[0x8];
    s32 elements;
    s32 count;
};
extern "C" void func_00107DF8(char *self) {
    ((Obj *)self)->count = 1;
    ((Obj *)self)->elements = (s32)(self + 0x18);
}
