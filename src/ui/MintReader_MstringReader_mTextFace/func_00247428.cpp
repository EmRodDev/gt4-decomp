/* Copies two floats (+0x3C, +0x40) from the global font manager (PDISTD__global_font_manager) into the object at +0x54 and +0x58.
 * The fields are probably default font metrics (inferred from the source being the font manager); their exact meaning is unknown. */
#include "types.h"

struct S_00624980 {
    char pad[0x3C];
    f32 unk3C;
    f32 unk40;
};

struct Obj {
    char pad[0x54];
    f32 unk54;
    char pad2[0x58 - 0x54 - 4];
    f32 unk58;
};

extern S_00624980 *PDISTD__global_font_manager;

extern "C" void func_00247428(Obj *face) {
    S_00624980 *fontManager = PDISTD__global_font_manager;
    face->unk54 = fontManager->unk3C;
    face->unk58 = fontManager->unk40;
}
