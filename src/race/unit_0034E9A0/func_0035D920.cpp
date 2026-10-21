/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Computes two scalars as dot products of the 3-vector at +0x648 with the vectors at +0x140 and +0x14C, stores them at +0x104+0x53C
 * and +0x540, then calls func_0035D6B0, which reads exactly those two fields. */
typedef float f32;

extern "C" int func_0035D6B0(void *arg0) throw();

static inline bool more(int i) { if (i < 3) return true; return false; }
extern "C" int func_0035D920(char *arg0) {
    f32 *state = (f32 *)(arg0 + 0x104);
    int i = 0;
    f32 dotB = 0.0f;
    f32 dotC = 0.0f;
    f32 *vecC = (f32 *)(arg0 + 0x14C);
    f32 *vecA = (f32 *)(arg0 + 0x648);
    f32 *vecB = (f32 *)(arg0 + 0x140);
    do {
        f32 x = *vecA++;
        f32 y = *vecB++;
        f32 z = *vecC++;
        i++;
        dotB += y * x;
        dotC += z * x;
    } while (more(i));
    state[0x53C / 4] = dotB;
    state[0x540 / 4] = dotC;
    return func_0035D6B0(arg0);
}
