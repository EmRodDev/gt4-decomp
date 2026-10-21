/* Builds a printf format string of the form "%0Nd" (N = digitCount) into the text buffer at +0x20 by running sprintf
 * (func_0057DA20) on the literal "%%0%dd", then clears the field at +0x1C (purpose unknown).
 * GT HD's candidate name for this address is RaceOdometer::setDigits (low confidence, from config/gthd_names.txt): inferred. */
#include "types.h"

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" void func_0057DA20(char *buffer, const char *format, ...);

extern "C" void func_003A4248(Obj *self, s32 digitCount) {
    func_0057DA20((char *)self + 0x20, "%%0%dd", digitCount);
    self->unk1C = 0;
}
