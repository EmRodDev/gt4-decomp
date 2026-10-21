/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Evaluates a closed-form expression built on a reciprocal square root (rsqrt.s: first argument divided by the root of the second) and
 * never returns less than the floor value from func_003FD260. The inputs are unknown; the 0.001 factor is the hex float constant. */
static inline float frsq(float a, float b) {
    float inverseNorm;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(inverseNorm) : "f"(a), "f"(b));
    return inverseNorm;
}
struct Q { char p[0x14]; float f14; };
extern "C" float func_003FD260(void *, void *) throw();
extern "C" float func_003FD3D8(void *ctxA, Q *q, void *ctxB, float p0, float p1, float p2, float p3)
{
    float inverseNorm = frsq(p1 * 0x1.0624dcp-10f, p2 * p2 + 1.0f);
    float curveB = p3 * (inverseNorm + inverseNorm);
    float curveA = inverseNorm * 0.5f * q->f14;
    float floorValue = func_003FD260(ctxA, ctxB);
    float curveASquared = curveA * curveA;
    float ratio = (floorValue * ((curveB * p0 * curveA) - curveASquared)) / ((floorValue * curveB * p0) - curveASquared);
    return ratio < floorValue ? floorValue : ratio;
}
