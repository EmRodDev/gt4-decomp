/* Returns GetADPsource of the 32-bit field at +0xE4; GetADPsource is the library routine that looks up an ADPCM (audio) source,
 * so the field is probably an audio source id (inferred from the callee name). */
#include "types.h"
struct Obj {
    char pad0[0xE4];
    s32 sourceId;
};
extern "C" s32 GetADPsource(s32 id);
extern "C" s32 func_00466C08(Obj *self)
{
    return GetADPsource(self->sourceId);
}
