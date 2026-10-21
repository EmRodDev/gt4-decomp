/* Converts a duration in seconds to a frame count at 60 frames per second (inferred from the constant 60.0), halving the duration first when the flag at +0x110 is nonzero.
 * The meaning of that flag is unknown. */
#include "types.h"

struct func_0024A250_arg0 {
    char pad0[0x110];
    s32 unk110;
};

extern "C" s32 func_0024A250(struct func_0024A250_arg0 *face, f32 seconds) {
    if (face->unk110 != 0) {
        return (s32)((seconds * 0.5f) * 60.0f);
    }
    return (s32)(seconds * 60.0f);
}
