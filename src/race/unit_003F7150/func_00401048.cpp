/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Shapes a steering-like value from func_00345108(self, 0): x = 1 - 2f; small |x| is scaled by
 * 1.8, otherwise |x| is mapped through 0.2|x| + 0.8 (the line from 0.8 to 1) and clamped to
 * [-1, 1], keeping the sign. max.s/min.s are single-instruction helpers. */
extern "C" float func_00345108(void *self, float t);

static inline float max_s(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float min_s(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Pair { float a, b; };

static inline float clamp_s(float x, const float *lo, const float *hi) {
    float l = *lo;
    float h = *hi;
    return min_s(max_s(x, l), h);
}

static inline float line_s(float x, const Pair *l) { float k = l->a; float c = l->b; return x * k + c; }

extern "C" float func_00401048(void *self) {
    float v = -func_00345108(self, 0.0f);
    float x = v + v + 1.0f;
    float k = 1.0f - 0.8f;
    float c = 0.8f;
    if (x < 0.5f && x > -0.5f) {
        x *= 1.8f;
    } else {
        float top = 1.0f;
        Pair line = { k, c };
        if (x > 0.0f) {
            Pair range;
            range.a = -1.0f;
            range.b = top;
            x = clamp_s(line_s(x, &line), &range.a, &range.b);
        } else {
            Pair range;
            range.a = top;
            range.b = -1.0f;
            x = -clamp_s(line_s(-x, &line), &range.b, &range.a);
        }
    }
    return x;
}
