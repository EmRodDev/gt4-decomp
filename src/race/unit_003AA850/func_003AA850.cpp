/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Preset setter: mode 1 writes 3.0 at +0x2C, clears the low byte of the word at +0x28 and stores (0.99, 0.39, 0.01) at +0x34; any other mode
 * stores (0, 0, 0) at the same place. Three values below 1.0 look like an RGB colour (orange for mode 1, black otherwise), which is an
 * inference from the magnitudes only; the object and the meaning of 3.0 are purpose unknown. Twin of 003AA9B8 (offsets +0x70/+0x7C). */
typedef int s32;
typedef float f32;

struct Ha3AA850 { s32 w; f32 f; };
struct Hb3AA850 { f32 f0; f32 f4; f32 f8; };

extern "C" void func_003AA850(void *self, s32 mode) {
    struct Hb3AA850 *base = (struct Hb3AA850 *)self;
    struct Ha3AA850 *params = (struct Ha3AA850 *)((char *)base + 0x28);
    struct Hb3AA850 *blackColour;
    f32 zero;
    if (mode != 0) {
        if (mode == 1) {
            base = (struct Hb3AA850 *)((char *)base + 0x34);
            params->f = 3.0f;
            params->w = params->w & ~0xFF;
            base->f0 = 0.99f;
            base->f4 = 0.39f;
            base->f8 = 0.01f;
            return;
        }
    }
    zero = 0.0f;
    blackColour = (struct Hb3AA850 *)((char *)params + 0xC);
    blackColour->f0 = zero;
    blackColour->f4 = zero;
    blackColour->f8 = zero;
}
