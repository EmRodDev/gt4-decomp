/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Blends two curve objects (self and other) into one value stored at self+8. Each object holds a table of nodes
 * (count plus floats); func_0042D9F0 picks the node for time timeA / timeB, and func_00486218 evaluates that node
 * at the time and returns two numbers. These fill a six-float table: [0] = 0, [1]+[2] summed, [3] = second curve
 * value minus its partner, [4] = 1.0, [5] = second curve value (what each slot means is unknown). The blend factor
 * blendInput is clamped to 0..1 with the min.s/max.s instructions (inline asm kept as matched) and func_004860E8
 * evaluates the six-float table at that factor (inferred from the argument order: table, 6, factor).  The six-float table and the factor live in one local struct, as in the matched source. */
struct Node { int n; int pad; float data[1]; };
struct Obj { char pad0[8]; float f8; Node *tab[1]; };
extern "C" int func_0042D9F0(void *, float);
extern "C" float func_004860E8(float *, int, float);
extern "C" void func_00486218(void *, int, float, float *, float *);

static inline float fmax_s(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fmin_s(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline float sum_pair(float a, float b) { return a + b; }

struct Loc { float blend; float pad[3]; float a[6]; };
extern "C" void func_0042DAE0(Obj *self, Obj *other, float timeA, float timeB, float blendInput) {
    Loc v;
    v.blend = blendInput;
    int indexA = func_0042D9F0(self, timeA);
    int indexB = func_0042D9F0(other, timeB);
    v.a[0] = 0;
    Node *segA = self->tab[indexA];
    Node *segB = other->tab[indexB];
    float *knotsPtr = v.a;
    func_00486218(segA->data, segA->n, timeA, &v.a[1], &v.a[2]);
    v.a[2] = sum_pair(v.a[1], v.a[2]);
    func_00486218(segB->data, segB->n, timeB, &v.a[5], &v.a[3]);
    v.a[4] = 1.0f;
    v.blend = fmin_s(fmax_s(v.blend, 0.0f), v.a[4]);
    v.a[3] = v.a[5] - v.a[3];
    self->f8 = func_004860E8(knotsPtr, 6, v.blend);
}
