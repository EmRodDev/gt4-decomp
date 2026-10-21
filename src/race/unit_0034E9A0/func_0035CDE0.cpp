/* Outputs a pair of values that start at 0.5 each. If func_0035C7C8 says so, the first is moved down by byte5/60 and the second
 * up by func_0035C9B0(byte4)/24, both bytes read from the sub-state at +0x788. Meaning of the pair unknown. */
#include "types.h"

struct Obj;

struct Sub {
    char pad[4];
    u8 unk4;
    s8 unk5;
};

extern "C" s32 func_0035C7C8(Obj *arg0);
extern "C" s32 func_0035C9B0(s32 arg0);

extern "C" void func_0035CDE0(Obj *self, f32 *outFirst, f32 *outSecond) {
    *outFirst = 0.5f;
    *outSecond = 0.5f;
    if (func_0035C7C8(self) != 0) {
        Sub *state = (Sub *)((char *)self + 0x788);
        *outFirst -= (f32)state->unk5 / 60.0f;
        *outSecond += (f32)func_0035C9B0(state->unk4) / 24.0f;
    }
}
