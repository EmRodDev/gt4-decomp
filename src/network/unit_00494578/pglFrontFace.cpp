#include "spr.h"
/* A one-word settings record is passed by value, as in the matched mode setter
 * at 004A19B0. Its aggregate ABI preserves the original call frame. */
struct AlternateSetting { int value; };
struct ScratchSettings { char unknown[0x2CC]; int alternate; };
extern "C" void func_004ABB00(ScratchSettings *);
extern "C" void pglFrontFace(AlternateSetting setting)
{
    ScratchSettings *scratch = (ScratchSettings *)spr_base();
    scratch->alternate = setting.value;
    return func_004ABB00(scratch);
}
