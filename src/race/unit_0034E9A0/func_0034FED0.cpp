/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns one scaled value and writes a second through `out`; what they drive is unknown. Does nothing (returns 0) unless the
 * draw mode is 3. Two special conditions (func_00355D48, func_00368398 on the config at +0x234) hand over to func_00356D88 and
 * func_00369510. Otherwise, with the byte at config+0x10D1 or block+0x522 equal to 0, out is 1 and the result 0. In the normal case the
 * magnitude of the value at block+0x51C is limited to g->f58, scaled by a per-index table entry over (limit * entry 0x44), and
 * blended between g->f50 and g->f54; out is g->f60 plus |func_00350DA0(self)| * g->f5C. The two unused float locals were kept
 * because the original declared them. */
typedef unsigned char u8;
struct G {
    char pad[0x50];
    float f50, f54, f58, f5C, f60;
};
extern G D_00843630;
extern "C" float func_00350DA0(void *);
extern "C" int func_00355D48(void *);
extern "C" float func_00356D88(void *, float *);
extern "C" int Automobile__getDrawMode(void *);
extern "C" int func_00368398(void *);
extern "C" float func_00369510(void *, float *);

struct Sub { char pad[0x40]; float f40[1]; char pad2[0x44 - 0x44]; };
struct Z { char pad[0x10D1]; u8 b10D1; };
struct S104 {
    char pad[0x51C - 0x104 + 0x104 - 0x104 + 0x104 - 0x104];
};

extern "C" float func_0034FED0(char *self, float *out) {
    char *block = self + 0x104;
    G *tuning = &D_00843630;
    float unusedF0;
    float unusedVal;
    if (Automobile__getDrawMode(self) != 3) return 0.0f;
    {
        if (func_00355D48(self) != 0) {
            return func_00356D88(self, out);
        }
        if (func_00368398(*(char **)(self + 0x10) + 0x234) != 0) {
            return func_00369510(self, out);
        }
        char *config = *(char **)(self + 0x10);
        if (*(u8 *)(config + 0x10D1) == 0 || *(u8 *)(block + 0x522) == 0) {
            *out = 1.0f;
            return 0.0f;
        } else {
            float magnitude = *(float *)(block + 0x51C);
            float limit = tuning->f58;
            if (magnitude < 0.0f) magnitude = -magnitude;
            if (limit < magnitude) magnitude = limit;
            char *params = config + 0x234;
            magnitude = (magnitude * *(float *)(params + *(u8 *)(block + 0x520) * 4 + 0x40)) / (limit * *(float *)(params + 0x44));
            if (magnitude < 0.0f) magnitude = -magnitude;
            float lowValue = tuning->f50;
            magnitude = lowValue + ((tuning->f54 - lowValue) * magnitude);
            float otherValue = func_00350DA0(self);
            if (otherValue < 0.0f) otherValue = -otherValue;
            *out = tuning->f60 + (otherValue * tuning->f5C);
            return magnitude;
        }
    }
}
