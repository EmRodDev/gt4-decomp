/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialiser for behaviour state 0xB (written to +0x148 after the base set-up func_00378CB8) that links the object
 * to a target record arg3: copies the target's float at +0x44 into +8 and +0x74, fetches two vectors with
 * func_003FC618/func_003FC658 (stored at +0x188 and +0x194), rotates them relative to the target's frame
 * (func_005F5040/func_005F5268 pairs) and keeps two angle-like results (func_0036EA98 / func_0036EA50 compared with
 * func_0036EB98) at +0x1A0 and +0x1A4. When byte +0x6E of the target is clear it also derives a value at the target's
 * +0x68 (at least 2.0) and rewrites flag bytes in its +0x6C word. The last lines clear the counters at +0x1B0..+0x1E8.
 * Meaning of the fields is purpose unknown. The init/init2 helpers differ only in store order, which the compiler
 * kept. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_0036EA50(void *) throw();                       /* extern */
extern "C" f32 func_0036EA98(void *) throw();                       /* extern */
extern "C" f32 func_0036EB98(f32, f32) throw();                        /* extern */
extern "C" void func_00378CB8(void *) throw();                            /* extern */
extern "C" void func_003FC618(s32, void *);                 /* extern */
extern "C" void func_003FC658(s32, void *);                 /* extern */
extern "C" f32 func_0057D008(f32);                             /* extern */
extern "C" void func_005F5040(void *, void *);           /* extern */
extern "C" void func_005F5268(void *, void *);        /* extern */

struct Pair { unsigned char value, limit; };
static inline void init(Pair *p, int limit) { p->limit = limit; p->value = 0; }
static inline void init2(Pair *p, int limit) { p->value = 0; p->limit = limit; }
extern "C" void func_0037FBE0(char *self, s32 param1, s32 param2, char *target, f32 floatParam) {
    struct StackFrame_0037FBE0 { s8 pad0[0x10]; s32 sp10; s8 pad1[0xC]; s32 sp20; s8 pad2[0xC]; } sp_;
    f32 angleResult;
    f32 derivedValue;
    f32 angleB;
    f32 angleC;
    s32 *clearPtr;
    s32 clearCount;
    void *vecA;
    void *vecB;

    func_00378CB8(self);
    M2C_FIELD(self, s32 *, 0x148) = 0xB;
    vecA = self + 0x188;
    float f44 = M2C_FIELD(target, f32 *, 0x44);
    M2C_FIELD(target, s32 *, 0x6C) = (s32) (M2C_FIELD(target, s32 *, 0x6C) & 0xFFFFFF);
    M2C_FIELD(self, f32 *, 8) = f44;
    M2C_FIELD(self, f32 *, 0x74) = (f32) M2C_FIELD(target, f32 *, 0x44);
    M2C_FIELD(self, s32 *, 0x180) = param2;
    func_003FC618(param1, vecA);
    vecB = self + 0x194;
    func_003FC658(param1, vecB);
    M2C_FIELD(self, void **, 0x184) = target;
    M2C_FIELD(self, f32 *, 0x1AC) = floatParam;
    void *vecAScratch = &sp_.sp10;
    void *vecBScratch = &sp_.sp20;
    func_005F5040(target + 4, ((s8 *)&sp_));
    func_005F5040(vecA, vecAScratch);
    func_005F5268(vecAScratch, ((s8 *)&sp_));
    func_005F5040(vecB, vecBScratch);
    func_005F5268(vecBScratch, ((s8 *)&sp_));
    angleB = func_0036EA98(vecBScratch);
    M2C_FIELD(self, f32 *, 0x1A0) = func_0036EB98(angleB, func_0036EA98(&sp_.sp10));
    angleC = func_0036EA50(vecBScratch);
    angleResult = func_0036EB98(angleC, func_0036EA50(&sp_.sp10));
    M2C_FIELD(self, s32 *, 0x1A8) = 0;
    M2C_FIELD(self, f32 *, 0x1A4) = angleResult;
    if (M2C_FIELD(target, u8 *, 0x6E) == 0) {
        derivedValue = (0x1.0000000000000p+1f * func_0057D008(0x1.0000000000000p+0f / ((0x1.0000000000000p+1f * M2C_FIELD(target, f32 *, 0x20)) / 0x1.6666660000000p-1f))) / 0x1.1df4680000000p-6f;
        M2C_FIELD(target, f32 *, 0x68) = derivedValue;
        if (derivedValue < 0x1.0000000000000p+1f) {
            M2C_FIELD(target, f32 *, 0x68) = 0x1.0000000000000p+1f;
        }
        M2C_FIELD(target, s32 *, 0x6C) = (s32) (M2C_FIELD(target, s32 *, 0x6C) & ~0xFF);
        M2C_FIELD(target, s8 *, 0x6D) = 0;
        M2C_FIELD(target, s32 *, 0x6C) = (s32) ((M2C_FIELD(target, s32 *, 0x6C) & 0xFF00FFFF) | 0x10000);
    }
    init2((Pair *)(self + 0x1B0), 0x12);
    init2((Pair *)(self + 0x1B2), 0x12);
    clearPtr = (s32 *)(self + 0x1CC);
    init((Pair *)(self + 0x1B4), 0x12);
    clearCount = 3;
    init((Pair *)(self + 0x1B6), 0x1E);
    M2C_FIELD(self, s8 *, 0x1B8) = 0;
    s64 flags = M2C_FIELD(self, s64 *, 0x1B8) & (s64)(s32)0xFFFF00FF;
    flags &= (s64)(s32)0xFF00FFFF;
    flags &= ((((-1LL << 16) | 0xFF) << 16) | 0xFFFF);
    flags &= ((((-0x100LL << 16) | 0xFFFF) << 16) | 0xFFFF);
    flags &= ((((0xFFFF00FFLL << 16) | 0xFFFF) << 16) | 0xFFFF);
    M2C_FIELD(self, s64 *, 0x1B8) = flags;
    do {
        clearCount -= 1;
        *clearPtr = 0;
        clearPtr--;
    } while (clearCount >= 0);
    M2C_FIELD(self, s64 *, 0x168) = (M2C_FIELD(self, s64 *, 0x168) & (s64)(s32)0xFF00FFFF) | 0x10000;
    M2C_FIELD(self, s32 *, 0xEC) = 0x4000;
    M2C_FIELD(self, s32 *, 0x1E0) = 0;
    M2C_FIELD(self, s32 *, 0x1E4) = 0;
    M2C_FIELD(self, s32 *, 0x1E8) = 0;
    M2C_FIELD(self, s32 *, 0x1DC) = 1;
    M2C_FIELD(self, s32 *, 0xE8) = 1;
}
