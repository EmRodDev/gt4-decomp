#include "types.h"

extern "C" void func_002FFAF0(void *arg0, u8 arg1);

extern "C" void *func_002FFB98(void *arg0, u8 arg1) {
    void *s0 = arg0;

    func_002FFAF0(arg0, arg1);
    return s0;
}
