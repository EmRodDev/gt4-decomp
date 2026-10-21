/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sets an indicator state by kind (inferred from the colour constants): kind 1 stores 3.0 and the kind byte with the colour
 * (0.2, 0.93, 0.11), a green; kind 2 stores 3.0 with (0.98, 0.89, 0), a yellow; anything else clears the colour vector.
 * The meaning of the 3.0 (possibly a display time) is unknown. */
typedef int s32;
typedef float f32;

struct Ha3AA8D0 { s32 w; f32 f; };
struct Hb3AA8D0 { f32 f0; f32 f4; f32 f8; };
struct Hc3AA8D0 { f32 f0; f32 f4; s32 i8; };

static inline void setv(Hb3AA8D0 *v,float x,float y,float z) { v->f0=x; v->f4=y; v->f8=z; }
static inline void setc(Hc3AA8D0 *v,float x,float y,int z) { v->f0=x; v->f4=y; v->i8=z; }
extern "C" void func_003AA8D0(void *self, s32 kind) {
    struct Ha3AA8D0 *header = (struct Ha3AA8D0 *)((char *)self + 0x4C);
    struct Hb3AA8D0 *clearColor;
    f32 zeroValue;
    switch (kind) {
    case 1: {
        struct Hb3AA8D0 *greenColor = (struct Hb3AA8D0 *)((char *)self + 0x58);
        header->f = 3.0f;
        header->w = (header->w & ~0xFF) | kind;
        setv(greenColor,0.2f,0.93f,0.11f);
        return;
    }
    case 2: {
        struct Hc3AA8D0 *yellowColor = (struct Hc3AA8D0 *)((char *)self + 0x58);
        header->f = 3.0f;
        header->w = header->w & ~0xFF;
        setc(yellowColor,0.98f,0.89f,0);
        return;
    }
    case 0:
    default:
        zeroValue = 0.0f;
        clearColor = (struct Hb3AA8D0 *)((char *)header + 0xC);
        clearColor->f0 = zeroValue;
        clearColor->f4 = zeroValue;
        clearColor->f8 = zeroValue;
        return;
    }
}
