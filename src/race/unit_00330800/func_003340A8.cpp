/* Converts an RGB image (3 bytes per pixel, w*h pixels) to 8-bit grey with the usual luma weights 0.299, 0.587, 0.114 (the hex floats),
 * clamping at 255. */
#include "types.h"

struct func_003340A8_arg1 {
    char pad0[4];
    u8 *out;
    char pad8[8];
    s32 w;
    s32 h;
};

struct func_003340A8_arg2 {
    char pad0[4];
    u8 *in;
};

extern "C" void func_003340A8(void *arg0, struct func_003340A8_arg1 *dst, struct func_003340A8_arg2 *src) {
    u32 pixelCount;
    u32 i;
    u8 *rgb;
    u8 *grey;
    s32 level;
    f32 luma;

    i = 0;
    rgb = src->in;
    pixelCount = (u32)(dst->w * dst->h);
    grey = dst->out;
    if (pixelCount != 0) {
        do {
            i += 1;
            luma = (f32)rgb[0] * 0x1.322D0Ep-2f;
            luma = luma + (f32)rgb[1] * 0x1.2C8B42p-1f;
            luma = luma + (f32)rgb[2] * 0x1.D2F1A8p-4f;
            rgb += 3;
            level = (s32)luma;
            if (level >= 0x100) {
                level = 0xFF;
            }
            *grey = (u8)level;
            grey += 1;
        } while (i < pixelCount);
    }
}
