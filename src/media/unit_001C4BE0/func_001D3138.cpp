/* Returns the 64-bit field at +0x10 of the object that *arg0 points to. The unused volatile 16-byte buffer is there to give the function the stack frame the original has (inferred: it has no other effect). */
#include "types.h"

struct Obj { char pad[0x10]; s64 unk10; };

extern "C" s64 func_001D3138(Obj **selfPtr) {
    volatile char buf[0x10];
    (void)buf;
    return (*selfPtr)->unk10;
}
