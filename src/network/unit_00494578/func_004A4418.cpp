#include "spr.h"
/* Round texture dimensions up to GS power-of-two exponents in the range 1..10.
 * TEX0's remaining fields belong to the texture binding and are preserved. */
struct TextureRegister {
    unsigned long long binding : 26;
    unsigned long long widthExponent : 4;
    unsigned long long heightExponent : 4;
    unsigned long long remaining : 30;
};
struct Scratch {
    char unknown0[0x1C0];
    TextureRegister texture;
    char unknown1C8[0x1D8-0x1C8];
    unsigned long long dirty;
};
extern "C" void func_004A4418(int width, int height) {
    Scratch *state = (Scratch *)spr_base();
    int w = 1;
    while (w < 10 && (1 << w) < width) ++w;
    int h = 1;
    while (h < 10 && (1 << h) < height) ++h;
    state->dirty |= 0x04000400;
    state->texture.widthExponent = w;
    state->texture.heightExponent = h;
}
