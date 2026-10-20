#include "types.h"

struct Obj {
    char pad[0xF866];
    u8 unkF866;
};

extern "C" s32 DynamicsConductorLicense__isDataLoggerStandingStart(Obj *arg0) {
    return arg0->unkF866 == 0;
}
