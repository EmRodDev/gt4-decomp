#include "types.h"

extern "C" void func_002FFB18(void *stream, u16 v);

extern "C" void func_002FFB58(void *stream, u32 v) {
    func_002FFB18(stream, v);
    func_002FFB18(stream, v >> 16);
}
