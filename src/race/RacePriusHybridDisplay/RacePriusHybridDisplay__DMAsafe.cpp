/* Applies five fixed patches (apply_patch on the sub-blocks at +0x28, +0x4C, +0x70, +0x94, +0xB8 with codes 0xD, 0xC, 0xB, 0xA, 0xA and two
 * small flag pairs) and one level patch (apply_level_patch, code 9, two ARGB-looking colour words 0x8000E3FA and 0x80202020 and the float
 * at +0x20). The name suggests it makes the display's packets safe to DMA; what the patches change is purpose unknown. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void RacePriusHybridDisplay__apply_patch(void *, void *, s32, s32, s32);
extern "C" void RacePriusHybridDisplay__apply_level_patch(void *, s32, s32, s32, s32, s32, f32);

struct RacePriusHybridDisplay__virtual_10_arg0 {
    char pad0[0x20];
    f32 unk20;
};

extern "C" void RacePriusHybridDisplay__DMAsafe(s32 *display) {
    RacePriusHybridDisplay__apply_patch(display, (char *)display + 0x28, 0xd, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(display, (char *)display + 0x4c, 0xc, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(display, (char *)display + 0x70, 0xb, 0, 0x8);
    RacePriusHybridDisplay__apply_patch(display, (char *)display + 0x94, 0xa, 0x1, 0x1);
    RacePriusHybridDisplay__apply_patch(display, (char *)display + 0xb8, 0xa, 0, 0x1);
    RacePriusHybridDisplay__apply_level_patch(display, 0x9, 0, 0x8, 0x8000e3fa, 0x80202020, ((struct RacePriusHybridDisplay__virtual_10_arg0 *)display)->unk20);
}
