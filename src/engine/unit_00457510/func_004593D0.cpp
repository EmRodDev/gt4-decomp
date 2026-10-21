static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00459338(float) throw() __attribute__((const));
static inline void adjust(float *a, float *b, float va, float vb) {
    float d = vb - va;
    if (absf(d) > 180.0f) {
        if (d > 0.0f) { *a = va + 360.0f; return; }
        *b = vb + 360.0f;
    }
}
extern "C" void func_004593D0(float *a, float *b) {
    *a = func_00459338(*a);
    *b = func_00459338(*b);
    adjust(a,b,*a,*b);
}
