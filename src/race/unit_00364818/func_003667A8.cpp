/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Packs the state of slot idx (slots are 0xEC bytes apart from +0x164; the 0x34-byte entries at +0x7B8/+0x7C4 are indexed in parallel) into a
 * stack record of one index, one flag byte, a position copied from pos and 13 floats, then hands the record to the sub-object at +8 through
 * 00395C70 and, when bit 0x20 of the entry's byte 0x33 is set, also through 00395C98 with extraVec. The final line subtracts 0.05 * float 5 from
 * float 7 of the record (a one-step prediction, inferred from the shape only). The meaning of the record is purpose unknown. */
typedef unsigned char u8;
typedef float f32;

struct Slot {
    f32 f0;
    char pad4[0x1C];
    f32 f20;
    char pad24[4];
    f32 f28;
    char pad2C[0xC];
    f32 f38;
    char pad3C[0x4D];
    u8 b89;
    char pad8A[0x32];
    f32 fBC;
    char padC0[0x2C];
};
struct R {
    char pad0[0x14];
    f32 f14;
    char pad18[0x1B];
    u8 b33;
};
struct T { f32 f[13]; };
struct Win {
    char pad0[0x440];
    u8 b440;
    char pad441[0x12F];
    f32 f570;
};
struct Car {
    char pad0[8];
    void *obj;
};
struct Vec3 { f32 x, y, z; };
struct Frame {
    int idx;
    int b;
    f32 x;
    T t;
};

extern "C" void func_00395C70(void *, void *, int);
extern "C" void func_00395C98(void *, void *, Vec3 *);

extern "C" void func_003667A8(Car *self, int idx, Vec3 *pos, Vec3 *extraVec) {
    Frame record;
    Slot *slot = (Slot *)((char *)self + 0x164) + idx;
    Win *block104 = (Win *)((char *)self + 0x104);
    R *entry = (R *)((char *)self + 0x7B8 + idx * 0x34);
    T *srcFloats = (T *)((char *)self + 0x7C4 + idx * 0x34);
    record.idx = idx;
    record.b = slot->b89;
    record.t.f[3] = entry->f14;
    record.t.f[8] = slot->fBC;
    record.t.f[2] = block104->f570 + slot->f0;
    record.x = pos->x;
    record.t.f[0] = pos->y;
    record.t.f[1] = pos->z;
    T *dstFloats = &record.t;
    for (int i = 0; i < 4; i++)
        dstFloats->f[i + 4] = srcFloats->f[i + 4];
    record.t.f[9] = slot->f38;
    record.t.f[10] = slot->f28;
    record.t.f[11] = slot->f20;
    record.t.f[7] = record.t.f[7] - record.t.f[5] * 0.05f;
    func_00395C70(self->obj, &record, block104->b440);
    if (entry->b33 & 0x20)
        func_00395C98(self->obj, &record, extraVec);
}
