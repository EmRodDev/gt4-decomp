/* Calls func_001CBDC8 with the address of the member at +0xD and the constant 7. The unused volatile 16-byte buffer gives the function the stack frame the original has (inferred: it has no other effect). */
#include "types.h"

extern "C" void func_001CBDC8(void *self, s32 arg1);

extern "C" void func_001CBEB0(void *self) {
    volatile char pad[16];
    (void)pad;
    func_001CBDC8((char *)self + 0xD, 7);
}
