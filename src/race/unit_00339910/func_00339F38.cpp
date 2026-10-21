/* Writes an entry to a stream (same begin/end pair, func_0045B4D8 and func_0045B548, as func_0033A2A0): two blocks from the entry
 * (+0x2890 and func_00339C08) and, when withExtra is set, a third block from raceData+0x31D0. Argument meanings inferred from
 * the offsets only. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00339C08(s32, void *, f32);            /* extern */
s32 func_003E91E0(s32, s32, s32);               /* extern */
s32 func_00459E30(s32, s32, f32);               /* extern */
s32 func_0045B4D8(void *, s32, s32);        /* extern */
s32 func_0045B548(void *, s32);                 /* extern */

extern char D_0069F2F0[];
struct func_00339F38_arg1 {
    char pad0[0x14];
    s32 unk14;
};

void func_00339F38(s32 stream, char *entry, s32 raceData, s32 withExtra, f32 value) {
    s8 scope[0x10];
    func_0045B4D8(scope, stream, (s32)D_0069F2F0);
    func_00459E30(stream, (s32)(entry + 0x2890), value);
    func_00339C08(stream, entry, value);
    if (withExtra != 0) {
        func_003E91E0(raceData + 0x31D0, stream, ((struct func_00339F38_arg1 *)entry)->unk14);
    }
    func_0045B548(scope, stream);
}

}
