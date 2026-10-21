/* Reads one record from a GT4Model BinStreamReader into record: a byte, three bytes turned into angles (byte * pi / 128, i.e. 0..2 pi in
 * 256 steps, inferred from the constant), three floats, then zero-fills the rest and sets the float at +0x38 to 1.0 before calling 003E29C8 on
 * the finished record. What kind of model element this is, and what each field means, is purpose unknown. The two do-while loops are the
 * compiler's form of the two 3-word clears at +0x1C and +0x28. */
#include "types.h"

struct func_003E56E8_arg0 {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x34 - 0x1C];
    s32 unk34;
    f32 unk38;
    s32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    char pad46[6];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
};

extern "C" u8 GT4Model__BinStreamReader__read8u(s32);
extern "C" f32 GT4Model__BinStreamReader__readFloat(s32);
extern "C" void func_003E29C8(char *);

extern "C" void func_003E56E8(struct func_003E56E8_arg0 *record, s32 stream) {
    char *clearA;
    char *clearB;
    s32 count;

    record->unk44 = GT4Model__BinStreamReader__read8u(stream);
    record->unk4 = (f32)(s32)GT4Model__BinStreamReader__read8u(stream) * 0x1.921FB4p1f * 0x1.0p-7f;
    record->unk8 = (f32)(s32)GT4Model__BinStreamReader__read8u(stream) * 0x1.921FB4p1f * 0x1.0p-7f;
    record->unkC = (f32)(s32)GT4Model__BinStreamReader__read8u(stream) * 0x1.921FB4p1f * 0x1.0p-7f;
    record->unk10 = GT4Model__BinStreamReader__readFloat(stream);
    record->unk14 = GT4Model__BinStreamReader__readFloat(stream);
    record->unk18 = GT4Model__BinStreamReader__readFloat(stream);
    clearB = (char *)record + 0x28;
    clearA = (char *)record + 0x1C;
    count = 2;
    do {
        count = count - 1;
        *(s32 *)clearA = 0;
        *(s32 *)clearB = 0;
        clearB += 4;
        clearA += 4;
    } while (count >= 0);
    record->unk34 = 0;
    record->unk38 = 0x1.0p0f;
    record->unk3C = 0;
    record->unk40 = 0;
    record->unk45 = 0;
    record->unk4C = 0;
    record->unk50 = 0;
    record->unk54 = 0;
    func_003E29C8((char *)record);
}
