/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Twin of 003AA850 for the second instance: mode 1 writes 3.0 at +0x74, clears the low byte of the word at +0x70 and stores (0.99, 0.39, 0.01)
 * at +0x7C; any other mode stores (0, 0, 0) there. Probably an RGB colour (inferred from the magnitudes); the rest is purpose unknown. */
typedef int s32;
typedef float f32;

struct Ha3AA850 { s32 w; f32 f; };
struct Hb3AA850 { f32 f0; f32 f4; f32 f8; };

extern "C" void func_003AA9B8(void *self, s32 mode) {
    struct Hb3AA850 *base = (struct Hb3AA850 *)self;
    struct Ha3AA850 *params = (struct Ha3AA850 *)((char *)base + 0x70);
    struct Hb3AA850 *blackColour;
    f32 zero;
    if (mode != 0) {
        if (mode == 1) {
            base = (struct Hb3AA850 *)((char *)base + 0x7C);
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
