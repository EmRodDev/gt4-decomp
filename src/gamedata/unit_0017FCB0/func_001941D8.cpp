/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Keeps a point (arg0, arg1) inside a width x height area centred on its middle, with a 16-unit margin: the point is expressed relative to the centre,
 * its angle is stored through arg2 (func_0036ECD0 takes (x, y); presumably atan2, inferred from its arguments), and if it exceeds the margin on either axis it is
 * scaled back toward the centre. Returns 1 when it had to be clamped. Looks like a map/radar marker clamp (inferred from the photo-map directory). */
typedef float f32;
typedef int s32;

extern "C" f32 func_0036ECD0(f32, f32);

static inline f32 absf(f32 x) { f32 clamped; __asm__("abs.s %0, %1" : "=f"(clamped) : "f"(x)); return clamped; }

extern "C" s32 func_001941D8(f32 *px, f32 *py, f32 *angleOut, f32 width, f32 height) {
    f32 halfW = width * 0.5f;
    f32 halfH = height * 0.5f;
    f32 y = *py - halfH;
    f32 x = *px - halfW;
    s32 clamped = 0;
    f32 ratio = func_0036ECD0(x, y);
    *angleOut = ratio;
    ratio = absf(x / (halfW - 16.0f));
    if (ratio > 1.0f) {
        x /= ratio;
        clamped = 1;
        y /= ratio;
    }
    ratio = absf(y / (halfH - 16.0f));
    if (ratio > 1.0f) {
        x /= ratio;
        clamped = 1;
        y /= ratio;
    }
    *px = x + halfW;
    *py = y + halfH;
    return clamped;
}
