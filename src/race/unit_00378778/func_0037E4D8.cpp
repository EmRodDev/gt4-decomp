/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialiser for behaviour state 9 of an animated object (the state number is written to +0x148, after the common base
 * set-up func_00378CB8). Stores the five caller parameters at +0x188..+0x198, zeroes three 12-byte vectors, then fills
 * a block of tuning values (+0x1C0..+0x254) with fixed numbers and with randomised ones drawn from the float rng at
 * +0x184 (thresholds 0x1.666666p-1 = 0.7, 0x1.333332p-1 = 0.6, 0x1.333332p-3 = 0.15). The ranges
 * are the literals in the code; what each field controls is purpose unknown (inferred only that this is a
 * randomised animation/effect set-up, from the rng use and the stored duration at +0x150). */
typedef int s32; typedef long s64; typedef signed char s8; typedef float f32;
#define M2C_FIELD(o,T,n) (*(T)((char *)(o)+(n)))
extern "C" {
void func_0036F710(void *,float,float,float,float) throw();
float func_0036F778(void *,float) throw();
void func_0036F948(void *,float,float,float,float) throw();
void func_0036F968(void *,float) throw(); void func_0036F970(void *,float) throw(); void func_0036F978(void *,float) throw();
void func_00378CB8(void *,void *) throw(); float func_00578598(void *);
void *func_005A48D8(void *,int,unsigned);
}
static inline void put(float *p,float v){*p=v;}
extern "C" void func_0037E4D8(char *self, void *baseParam, s32 param2, s32 param3, s32 param4, s32 param5, f32 floatParam) {
    struct StackFrame_0037E4D8 { s8 pad0[0x20]; } sp_;
    f32 durationSeconds;
    void *rng;
    void *curveBlock;

    rng = M2C_FIELD(self, void **, 0x184);
    func_00378CB8(self,baseParam);
    M2C_FIELD(self, s32 *, 0x188) = param5;
    M2C_FIELD(self, s32 *, 0x148) = 9;
    M2C_FIELD(self, s32 *, 0x18C) = param2;
    M2C_FIELD(self, s32 *, 0x190) = param3;
    M2C_FIELD(self, s32 *, 0x194) = param4;
    M2C_FIELD(self, f32 *, 0x198) = floatParam;
    M2C_FIELD(self, s32 *, 0x180) = 1;
    func_005A48D8(self + 0x19C, 0, 0xC);
    func_005A48D8(self + 0x1A8, 0, 0xC);
    func_005A48D8(self + 0x1B4, 0, 0xC);
    M2C_FIELD(self, s32 *, 0x1C4) = 0;
    M2C_FIELD(self, s32 *, 0x1C8) = 2;
    put((float *)(self+0x1CC),0.0f);
    put((float *)(self+0x1D0),5.0f);
    put((float *)(self+0x1D4),1.0f);
    put((float *)(self+0x1D8),5.0f);
    put((float *)(self+0x1EC),0.0f);
    put((float *)(self+0x1F0),0.0f);
    put((float *)(self+0x1F4),60.0f);
    M2C_FIELD(self, s32 *, 0x1C0) = 1;
    if (func_00578598(rng) < 0x1.6666660000000p-1f) {
        M2C_FIELD(self, s32 *, 0x1C0) = 0;
    }
    curveBlock = self + 0x1FC;
    func_0036F710(((s8 *)&sp_), 0x1.47ae14p-7f, 0x1.ba5e340000000p-6f, 0x1.47ae14p-7f, 0x1.6872b0p-6f);
    func_0036F710(self + 0x228, 0x1.999998p-4f, func_00578598(rng) * 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
    M2C_FIELD(self, f32 *, 0x244) = (f32) (func_0036F778(((s8 *)&sp_), func_00578598(rng)) * 0x1.9999980000000p-1f);
    M2C_FIELD(self, f32 *, 0x248) = (f32) (func_0036F778(((s8 *)&sp_), func_00578598(rng)) * 0x1.9999980000000p-1f);
    func_0036F948(curveBlock, 0x1.999998p-4f, 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(curveBlock, 0x0.0p+0f);
    func_0036F970(curveBlock, 0x0.0p+0f);
    func_0036F978(curveBlock, 0x1.0000000000000p-1f);
    if (func_00578598(rng) < 0x1.3333320000000p-1f) {
        func_0036F948(curveBlock, 0x1.999998p-4f, func_00578598(rng) * 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
        func_0036F968(curveBlock, (func_00578598(rng) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        func_0036F970(curveBlock, (func_00578598(rng) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        func_0036F978(curveBlock, (func_00578598(rng) * 0x1.0000000000000p-1f) + 0x1.9999980000000p-3f);
    }
    M2C_FIELD(self, f32 *, 0x224) = 0x0.0p+0f;
    if (func_00578598(rng) < 0x1.3333320000000p-3f) {
        M2C_FIELD(self, f32 *, 0x224) = (f32) ((func_00578598(rng) * 0x1.9000000000000p+7f) - 0x1.9000000000000p+6f);
    }
    M2C_FIELD(self, f32 *, 0x24C) = (f32) ((func_00578598(rng) * 0x1.9999980000000p-3f) + 0x1.0000000000000p-1f);
    M2C_FIELD(self, f32 *, 0x250) = (f32) (0x1.0000000000000p+0f - (func_00578598(rng) * 0x1.9999980000000p-3f));
    if (func_00578598(rng) < 0x1.0000000000000p-1f) {
        M2C_FIELD(self, f32 *, 0x24C) = 0x1.0000000000000p+0f;
        M2C_FIELD(self, f32 *, 0x250) = 0x1.0ccccc0000000p+0f;
    }
    M2C_FIELD(self, f32 *, 0x254) = (f32) (func_00578598(rng) - 0x1.0000000000000p-1f);
    if (func_00578598(rng) < 0x1.6666660000000p-1f) {
        M2C_FIELD(self, f32 *, 0x254) = 0x1.0000000000000p+0f;
    }
    durationSeconds = func_00578598(rng) * 0x1.4999980000000p+4f;
    M2C_FIELD(self, s32 *, 0xE8) = 1;
    M2C_FIELD(self, s64 *, 0x168) = (s64) ((M2C_FIELD(self, s64 *, 0x168) & (long)(int)0xFF00FFFF) | 0x10000);
    M2C_FIELD(self, s32 *, 0x150) = (s32) ((durationSeconds + 0x1.6666660000000p+0f) * 0x1.9000000000000p+6f);
}
