/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame update of an object whose record keeps a short history of matrices/vectors (stride 0x6C, copied
 * one slot back at the loop at the top, so slot 0 holds the previous frame, inferred from the copy direction).
 * Virtual calls go through the object's vtable (+0x50 returns a flag, +0x60 is a plain update, +0x90 returns a
 * float for the given argument); they are written as small {delta, index, fn} entries because that is how the
 * compiler lays out a multiple-inheritance thunk call. The rest builds a rotation (angle from +0xC) and tests
 * the entries listed in other+0x60 against it with func_003FDD60, writing a hit byte per entry at +0x160+index.
 * Purpose unknown in game terms (inferred from the structure only). */
typedef int s32; typedef short s16; typedef signed char s8; typedef unsigned char u8; typedef long long s64; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
struct V50 { s16 delta, index; s32 (*fn)(void *,void *,s32,s32,s32,s32); };
struct V60 { s16 delta, index; void (*fn)(void *); };
struct V90 { s16 delta, index; f32 (*fn)(void *,s32); };
extern "C" s32 func_0036EC60(s32);
extern "C" s32 func_003FDD60(void *, void *, void *);
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A74B4(void *);
extern "C" void func_004A7A54();
extern "C" void func_004A7AA8(void *, void *);
extern "C" f32 func_0057D380(f32);
extern "C" void func_005F5040(void *, void *);
static inline s64 set24(s64 word, s64 value) { return (word & 0xFFFFFFFF00FFFFFFLL) | (value << 24); }
static inline void init(f32 *p, f32 *y, f32 *z, f32 a, f32 b, f32 c, f32 d) { *z=c; *y=b; p[0]=a; p[3]=d; }
extern "C"
void func_00378F28(char *self, char *other, s32 param2, s32 param3, s32 param4) {
    struct StackFrame_00378F28 { f32 sp0; f32 sp4; f32 sp8; f32 spC; s32 sp10; s8 pad0[0xC]; s32 sp20; s8 pad1[0xC]; } sp_;
    void *oldPtrB;
    f32 baseValue;
    f32 adjustedValue;
    s32 oldField140;
    s32 entryCount;
    s32 wasZero;
    s32 entryOffset;
    s32 historyIndex;
    s32 entryIndex;
    char *hitByte;
    void *oldPtrA;
    char *entry;
    char *vtable;
    char *entryList;
    char *currentSlot;
    void *baseMatrix;
    char *vtable2;
    char *historySlot;

    wasZero = M2C_FIELD(self, s32 *, 0x140) == 0;
    for (historyIndex = 1; historyIndex > 0; historyIndex--) {
        historySlot = self + historyIndex * 0x6C;
        M2C_FIELD(historySlot, f32 *, 4) = (f32) M2C_FIELD(historySlot, f32 *, -0x68);
        M2C_FIELD(historySlot, f32 *, 8) = (f32) M2C_FIELD(historySlot, f32 *, -0x64);
        M2C_FIELD(historySlot, f32 *, 0xC) = (f32) M2C_FIELD(historySlot, f32 *, -0x60);
        func_005F5040(historySlot - 0x5C, historySlot + 0x10);
        M2C_FIELD(historySlot, f32 *, 0x1C) = (f32) M2C_FIELD(historySlot, f32 *, -0x50);
        M2C_FIELD(historySlot, f32 *, 0x20) = (f32) M2C_FIELD(historySlot, f32 *, -0x4C);
        M2C_FIELD(historySlot, f32 *, 0x24) = (f32) M2C_FIELD(historySlot, f32 *, -0x48);
        func_005F5040(historySlot - 0x44, historySlot + 0x28);
        func_005F5040(historySlot - 0x38, historySlot + 0x34);
        func_005F5040(historySlot - 0x2C, historySlot + 0x40);
        func_005F5040(historySlot - 0x20, historySlot + 0x4C);
        func_005F5040(historySlot - 0x14, historySlot + 0x58);
        oldPtrA = historySlot - 8;
        oldPtrB = historySlot + 0x64;
        func_005F5040(oldPtrA, oldPtrB);
    }
    oldField140 = M2C_FIELD(self, s32 *, 0x140);
    if (oldField140 != 0) {
        M2C_FIELD(self, s64 *, 0x168) = set24(M2C_FIELD(self, s64 *, 0x168), 1);
    }
    baseMatrix = self + 0x10;
    M2C_FIELD(self, s32 *, 0x140) = func_0036EC60(oldField140);
    M2C_FIELD(self, s32 *, 0x144) = func_0036EC60(M2C_FIELD(self, s32 *, 0x144));
    M2C_FIELD(self, s64 *, 0x168) = (s64) (M2C_FIELD(self, s64 *, 0x168) & ((((-0x100LL << 0x10) | 0xFFFF) << 0x10) | 0xFFFF));
    vtable = M2C_FIELD(self, char **, 0);
    V50 *e50 = (V50 *)(vtable + 0x50);
    sp_.sp20 = e50->fn(self + e50->delta, other, param2, param3, param4, 1);
    if (wasZero) sp_.sp20 = 0;
    func_004A0690();
    func_004A53F8();
    func_004A74B4(self + 0x100);
    func_004A7A54();
    f32 *p4 = &sp_.sp4;
    f32 *p8 = &sp_.sp8;
    init(&sp_.sp0, p4, p8, 0.0f, 0.0f, 0.0f, 1.0f);
    func_004A7AA8(((s8 *)&sp_), ((s8 *)&sp_));
    M2C_FIELD(baseMatrix, f32 *, 0) = sp_.sp0;
    M2C_FIELD(self, f32 *, 0x14) = *p4;
    M2C_FIELD(self, f32 *, 0x18) = *p8;
    func_004A5400();
    func_004A06F0();
    V60 *e60 = (V60 *)(M2C_FIELD(self, char **, 0) + 0x60);
    e60->fn(self + e60->delta);
    if (M2C_FIELD(self, u8 *, 0x16A) != 0) {
        vtable2 = M2C_FIELD(self, char **, 0);
        entryList = M2C_FIELD(other, char **, 0x60);
        void *p10 = &sp_.sp10;
        entryIndex = 0;
        entryCount = M2C_FIELD(entryList, s32 *, 0);
        V90 *e90 = (V90 *)(vtable2 + 0x90);
        baseValue = e90->fn(self + e90->delta, param4);
        adjustedValue = baseValue + (baseValue * func_0057D380((M2C_FIELD(self, f32 *, 0xC) * 0x1.0000000000000p-1f * 0x1.921fb40000000p+1f) / 0x1.6800000000000p+7f));
        sp_.sp0 = adjustedValue;
        *p4 = adjustedValue + 0x1.9999980000000p-3f;
        *p8 = adjustedValue;
        func_005F5040(baseMatrix, p10);
        if (entryCount > 0) {
            param4 = (s32)(self + 4);
            do {
                entryOffset = entryIndex * 4;
                entryIndex += 1;
                entry = *(char * *)(entryOffset + M2C_FIELD(M2C_FIELD(other, char **, 0x60), s32 *, 8));
                s32 idx = M2C_FIELD(entry, s32 *, 0x14) + 0x160;
                hitByte = (char *)param4 + idx;
                *hitByte = 0;
                if (func_003FDD60(entry, p10, ((s8 *)&sp_)) != 0) {
                    *hitByte = 1;
                }
            } while (entryIndex < entryCount);
        }
    }
    if (sp_.sp20 == 0) {
        param4 = (s32)(self + 4);
        currentSlot = self + 0x6C;
        char *p28=self+0x28, *p34=self+0x34, *p40=self+0x40, *p4c=self+0x4c, *p58=self+0x58, *p64=self+0x64;
        M2C_FIELD(currentSlot, f32 *, 4) = (f32) M2C_FIELD((char *)param4, f32 *, 0);
        M2C_FIELD(currentSlot, f32 *, 8) = (f32) M2C_FIELD((char *)param4, f32 *, 4);
        M2C_FIELD(currentSlot, f32 *, 0xC) = (f32) M2C_FIELD((char *)param4, f32 *, 8);
        func_005F5040(baseMatrix, self + 0x7C);
        M2C_FIELD(currentSlot, f32 *, 0x1C) = (f32) M2C_FIELD((char *)param4, f32 *, 0x18);
        M2C_FIELD(currentSlot, f32 *, 0x20) = (f32) M2C_FIELD((char *)param4, f32 *, 0x1C);
        M2C_FIELD(currentSlot, f32 *, 0x24) = (f32) M2C_FIELD((char *)param4, f32 *, 0x20);
        func_005F5040(p28, self + 0x94);
        func_005F5040(p34, self + 0xA0);
        func_005F5040(p40, self + 0xAC);
        func_005F5040(p4c, self + 0xB8);
        func_005F5040(p58, self + 0xC4);
        func_005F5040(p64, self + 0xD0);
    }
}
