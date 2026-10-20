#include "types.h"

struct DynamicsConductorLayout {
    char pad0[0xF85E];
    u8 pylons_to_touch;
};

extern "C" u8 DynamicsConductor__GetNumberOfPylonsToBeTouched(DynamicsConductorLayout *arg0) {
    return arg0->pylons_to_touch;
}
