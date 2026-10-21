/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds a rotation + translation for a view (apparently a camera, inferred from the 180/pi conversions and the
 * func_004A7844/79xx matrix helpers) from a 32-byte table entry selected by the object's kind (virtual call at
 * vtable +0xB8). The entry holds position (+0..+8), three angles (+0xC..+0x14) and a flags word (+0x1C): bit 2
 * clear, or byte +0x265 set, adds offsets from func_00384B28/BC8. When kind==6 and byte +0x26B or +0x269 is set the
 * entry is mirrored (two angles negated, +180 degrees on one). Results are mirrored into the object at +0x28..+0x54,
 * +0x278 and through set_value. Exact game meaning of the fields is purpose unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_00344798(void *, f32);                    /* extern */
extern "C" f32 func_003447F8(void *, f32);                    /* extern */
extern "C" f32 func_00344828(void *, f32);                    /* extern */
extern "C" f32 func_00344858(void *, f32);                    /* extern */
extern "C" f32 func_00344888(void *, f32);                    /* extern */
extern "C" f32 func_003448B8(void *, f32);                    /* extern */
extern "C" f32 func_00384B28(void *);                          /* extern */
extern "C" f32 func_00384BC8(void *);                          /* extern */
extern "C" void func_004A7844(f32, f32, f32);               /* extern */
extern "C" void func_004A7988(f32);                         /* extern */
extern "C" void func_004A79B0(f32);                         /* extern */
extern "C" void func_004A79D8(f32);                         /* extern */
extern "C" f32 func_0057D008(f32);                             /* extern */

struct VEntry { short delta; short index; int (*fn)(void *); };
struct PEntry { short delta; short index; void *(*fn)(void *); };
struct Obj { char pad[0xC]; float value; char pad2[0x260-0x10]; s64 flags; };
static inline int kind(char *o) {
    VEntry *e = (VEntry *)(*(char **)o + 0xB8);
    return e->fn(o + e->delta);
}
static inline void set_value(char *p, float v) {
    Obj *o = (Obj *)p;
    float *dst = &o->value;
    *dst = v;
    s64 bits = 0x8000LL << 33;
    s64 mask = ~(0xFFLL << 48);
    o->flags = (o->flags & mask) | bits;
}
extern "C" void func_0037B580(char *self) {
    f32 posZ;
    f32 negPoseY;
    f32 negPoseX;
    f32 targetDegC;
    f32 targetDegB;
    f32 targetDegA;
    f32 angle10;
    f32 angle0C;
    f32 angle14;
    f32 posX;
    f32 posY;
    f32 extraYawDeg;
    void *poseSource;
    s32 mirrorRequested;
    char *owner;
    void *tableHolder;
    char *entry;
    void *sourceObj;

    extraYawDeg = 0x0.0p+0f;
    sourceObj = M2C_FIELD(self, void **, 0x18C);
    owner = M2C_FIELD(sourceObj, char **, 0x2880);
    poseSource = M2C_FIELD(sourceObj, void **, 0x18);
    PEntry *holderEntry = (PEntry *)(M2C_FIELD(owner, char **, 8) + 0x50);
    tableHolder = holderEntry->fn(owner + holderEntry->delta);
    entry = M2C_FIELD(tableHolder, char **, 0x44) + (kind(self) << 5);
    posX = M2C_FIELD(entry, f32 *, 0);
    posY = M2C_FIELD(entry, f32 *, 4);
    posZ = M2C_FIELD(entry, f32 *, 8);
    angle0C = M2C_FIELD(entry, f32 *, 0xC);
    angle10 = M2C_FIELD(entry, f32 *, 0x10);
    angle14 = M2C_FIELD(entry, f32 *, 0x14);
    targetDegA = func_00344888(poseSource, 0) * 0x1.ca5dc00000000p+5f;
    targetDegB = -func_00344858(poseSource, 0) * 0x1.ca5dc00000000p+5f;
    targetDegC = -func_003448B8(poseSource, 0) * 0x1.ca5dc00000000p+5f;
    if (!(M2C_FIELD(entry, s32 *, 0x1C) & 4) || (M2C_FIELD(self, u8 *, 0x265) != 0)) {
        func_004A7988(func_00384B28(self + 0x1B8) * 0x1.6666660000000p-1f);
        func_004A79B0(func_00384B28(self + 0x1C4) * 0x1.6666660000000p-1f);
        posX += 0x1.0000000000000p+1f * func_00384BC8(self + 0x1D0);
        posY += 0x1.0000000000000p+1f * func_00384BC8(self + 0x1DC);
    }
    mirrorRequested = 0;
    if ((M2C_FIELD(self, u8 *, 0x26B) != 0) || (M2C_FIELD(self, u8 *, 0x269) != 0)) {
        mirrorRequested = 1;
    }
    if (mirrorRequested != 0) {
        if (kind(self) == 6) {
            angle0C = -angle0C;
            angle14 = -angle14;
            angle10 += 0x1.6800000000000p+7f;
            extraYawDeg = 0x1.6800000000000p+7f;
        }
    }
    func_004A79D8(angle14);
    func_004A7988(angle0C);
    func_004A79B0(angle10);
    func_004A7844(posX, posY, posZ);
    func_004A79D8(targetDegA);
    func_004A7988(targetDegB);
    func_004A79B0(targetDegC);
    negPoseX = -func_00344798(poseSource, 0);
    negPoseY = -func_003447F8(poseSource, 0);
    func_004A7844(negPoseX, negPoseY, -func_00344828(poseSource, 0));
    M2C_FIELD(self, f32 *, 0x4C) = angle10;
    M2C_FIELD(self, f32 *, 0x50) = angle0C;
    M2C_FIELD(self, f32 *, 0x54) = angle14;
    M2C_FIELD(self, f32 *, 0x40) = posX;
    M2C_FIELD(self, f32 *, 0x44) = posY;
    M2C_FIELD(self, f32 *, 0x48) = posZ;
    M2C_FIELD(self, f32 *, 0x34) = targetDegC;
    M2C_FIELD(self, f32 *, 0x38) = targetDegB;
    M2C_FIELD(self, f32 *, 0x3C) = targetDegA;
    M2C_FIELD(self, f32 *, 0x28) = (f32) -func_00344798(poseSource, 0);
    M2C_FIELD(self, f32 *, 0x2C) = (f32) -func_003447F8(poseSource, 0);
    M2C_FIELD(self, f32 *, 0x30) = (f32) -func_00344828(poseSource, 0);
    float angle = M2C_FIELD(entry, f32 *, 0x10) + extraYawDeg;
    M2C_FIELD(self, f32 *, 8) = 0x1.9000000000000p+6f;
    M2C_FIELD(self, f32 *, 0x278) = angle;
    set_value(self, (2.0f * func_0057D008(1.0f / M2C_FIELD(entry, f32 *, 0x18))) / 0x1.1df468p-6f);
    if (M2C_FIELD(self, u8 *, 0x267) != 0) {
        set_value(self, M2C_FIELD(self, f32 *, 0x188));
    }
}
