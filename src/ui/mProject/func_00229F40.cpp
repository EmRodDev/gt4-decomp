/* Calls func_00485FF0 on the member at +0xB0 of the project with a string-like object read through the indirection arg2:
 * when the header word 16 bytes before the object is zero the shared static D_00698458 is used instead; otherwise a zero byte is stored at object + that word (a terminator, inferred) and the object is used.
 * What the member does with it is unknown. */
#include "types.h"

extern "C" s32 func_00485FF0(void *project, void *key, void *valueRef);
extern "C" char D_00698458[];

extern "C" void func_00229F40(void *project, void *key, void **valueRef) {
    void *value = *valueRef;
    s32 tailOffset = *(s32 *)((char *)value - 0x10);
    void *argument;
    if (tailOffset == 0) {
        argument = D_00698458;
    } else {
        char *tail = (char *)value + tailOffset;
        *tail = 0;
        argument = *valueRef;
    }
    func_00485FF0((char *)project + 0xB0, key, argument);
}
