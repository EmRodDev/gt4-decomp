/* Decodes a packed record of byte-sized tuning values at +0x1E0 of the object into 32 floats in the global D_00843630 (read by the other
 * functions of this unit, e.g. 0034FA90 and 0034FBC0). Each byte is scaled by its own divisor (/10, /100) or factor: 2.7778 (=10/3.6, a
 * value in tens of km/h converted to m/s) and 9.8 (gravity) are recognisable from the constants (inferred); 1047.2 (about 1000 pi / 3) is
 * unexplained. What each of the 32 parameters physically is stays purpose unknown. The odd hex-float literals are what matched. */
#include "types.h"

extern "C" f32 D_00843630[];

extern "C" void func_0034F6A0(char *object) {
    u8 *rawBytes = (u8 *)(object + 0x1E0);
    f32 *params = D_00843630;
    f32 smallRatio;
    f32 baseValue;
    f32 byte4Tenths;
    f32 byte3Tenths;

    baseValue = (f32)rawBytes[0xE] / 10.0f;
    smallRatio = ((f32)rawBytes[0xF] / 10.0f) / 100.0f;
    params[0] = baseValue * smallRatio * smallRatio;
    params[1] = (f32)rawBytes[0x10] * 0x1.638E36p+1f;
    params[2] = (f32)rawBytes[0x11] * 0x1.638E36p+1f;
    params[3] = (f32)(rawBytes[0x12] * 100);
    params[4] = (f32)(rawBytes[0x13] * 100);
    params[5] = (f32)rawBytes[0x14] / 10.0f;
    smallRatio = ((f32)rawBytes[0x16] / 10.0f) / 100.0f;
    params[6] = baseValue * smallRatio * smallRatio;
    params[7] = (f32)rawBytes[0x17] * 0x1.638E36p+1f;
    params[8] = (f32)rawBytes[0x18] * 0x1.638E36p+1f;
    params[9] = (f32)rawBytes[0x19] / 100.0f;
    params[10] = (f32)rawBytes[0x1A] / 100.0f;
    params[11] = (f32)rawBytes[0x1B] / 10.0f;
    params[12] = (f32)rawBytes[0x6] / 100.0f;
    params[13] = (f32)rawBytes[0x7] / 100.0f;
    params[14] = (f32)rawBytes[0x8] / 100.0f;
    params[15] = (f32)rawBytes[0x9] * 0x1.638E36p+1f;
    params[16] = (f32)rawBytes[0xA] * 0x1.638E36p+1f;
    params[17] = (f32)rawBytes[0xB] / 100.0f;
    params[18] = (f32)rawBytes[0xC] / 100.0f;
    params[19] = (f32)rawBytes[0xD] / 10.0f;
    params[20] = (f32)rawBytes[0x0] / 100.0f;
    params[21] = (f32)rawBytes[0x1] / 100.0f;
    params[22] = (f32)rawBytes[0x2] * 0x1.399998p+3f;
    byte4Tenths = (f32)rawBytes[0x4] / 10.0f;
    byte3Tenths = (f32)rawBytes[0x3] / 10.0f;
    params[24] = byte4Tenths;
    params[23] = (byte3Tenths - byte4Tenths) / 0x1.05CCA2p+10f;
    params[25] = (f32)rawBytes[0x1C] / 100.0f;
    params[26] = (f32)rawBytes[0x1D] / 100.0f;
    params[27] = (f32)rawBytes[0x1E] / 100.0f;
    params[28] = (f32)rawBytes[0x1F] / 10.0f;
    params[29] = (f32)rawBytes[0x26] / 100.0f;
    params[30] = (f32)rawBytes[0x28] / 100.0f;
    params[31] = (f32)rawBytes[0x29] / 100.0f;
}
