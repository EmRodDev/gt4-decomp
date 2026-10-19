#include "types.h"

extern s32 D_00654D90;
extern s32 D_00654D94;
extern s32 func_00563158(s32 count);
extern void func_00563258(u32 count);
extern void func_0054D248(void);
extern void func_0054D2F8(void);
extern s32 func_00563A88(void);

s32 func_005638B0(void) {
    /* The sequence header begins with 12-bit horizontal and vertical sizes. */
    s32 *horizontalSize = &D_00654D90;
    s32 *verticalSize = &D_00654D94;

    *horizontalSize = func_00563158(12);
    *verticalSize = func_00563158(12);
    /* Aspect ratio, frame rate, bitrate, marker, VBV size, and constrained flag. */
    func_00563158(4);
    func_00563158(4);
    func_00563158(18);
    func_00563258(1);
    func_00563158(10);
    func_00563158(1);
    /* Optional intra and non-intra quantizer matrices. */
    if (func_00563158(1) != 0)
        func_0054D248();
    if (func_00563158(1) != 0)
        func_0054D2F8();
    return func_00563A88();
}
