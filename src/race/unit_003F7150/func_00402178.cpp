/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Same family as func_00401048: the limit p is clamped to [0, 0.4] in place; the magnitude of
 * the value func_0040CEA0(self) below 0.5 returns a fresh reading, below
 * p + 0.5 gives 0.5, and above it is mapped linearly from [p + 0.5, 1] onto [0.5, 1] and
 * clamped to [0, 1]; the sign is restored. Map is a two-point line (slope k, offset c). */
extern "C" float func_0040CEA0(void *);
static inline float max_s(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float min_s(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct Pair { float a, b; };
struct Map {
    float k, c;
    Map(float x0, float x1, float y0, float y1) { float r = 1.0f / (x1 - x0); k = r * (y1 - y0); c = r * (x1 * y0 - x0 * y1); }
};
static inline float clamp_s(float x, const float *lo, const float *hi) {
    float l = *lo;
    float h = *hi;
    return min_s(max_s(x, l), h);
}
static inline float map_s(float x, const Map *m) { float k = m->k; float c = m->c; return k * x + c; }
static inline void clamp_in(float *v, float lo, float hi) { *v = min_s(max_s(*v, lo), hi); }

extern "C" float func_00402178(void *self, float p) {
    float zero = 0.0f;
    clamp_in(&p, zero, 0.4f);
    float x = func_0040CEA0(self);
    float sign = 1.0f;
    if (x < zero) { x = -x; sign = -1.0f; }
    if (x < 0.5f) return func_0040CEA0(self);
    float t = p + 0.5f;
    if (x < t) return sign * 0.5f;
    Map line(t, 1.0f, 0.5f, 1.0f);
    Pair range;
    range.a = zero;
    range.b = 1.0f;
    return sign * clamp_s(map_s(x, &line), &range.a, &range.b);
}
