/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Uploads up to eight slots of vector parameters to the renderer (inferred from the slot ids 0x65..0x6C and the
 * loop bound 8). Every vector is first passed through func_0040A1A0 together with 1/ctx->f38, i.e. scaled by the
 * inverse of a value at ctx+0x38 (inferred from the 1.0f / f38 division). The 0x50-byte records at self hold a
 * count at +8 and four 4-float vectors; each record is sent with func_004A5BF8 under sub-ids 0xD, 0, 1 and 4
 * (meaning of those ids unknown) after func_004A1638 is called for the slot id. Unused trailing ids up to eight
 * get func_004AB040 instead. With a count of zero or less only func_00398210 is called, with the two floats at
 * self+0 and self+4. A first call func_004A5CC0 uses the matrix at ctx+0xEF0 scaled the same way. */
struct Entry { float f0, f4; int count; float v0[4], v1[4], v2[4], v3[4]; float pad; };
struct Ctx { char p[0x38]; float f38; char p3C[0xEF0 - 0x3C]; float mat[1]; };
extern "C" void func_00398210(void *, float, float);
extern "C" void func_0040A1A0(float *, float *, float) throw();
extern "C" void func_004A1638(int);
extern "C" void func_004A5BF8(int, int, void *);
extern "C" void func_004A5CC0(int, void *);
extern "C" void func_004AB040(int);

extern "C" void func_0040A1D0(char *self, Ctx *ctx) {
    float scaled[4];
    float invScale = 1.0f / ctx->f38;
    func_0040A1A0(scaled, ctx->mat, invScale);
    func_004A5CC0(0, scaled);
    Entry *entries = (Entry *)self;
    int count = entries->count;
    if (count > 0) {
        int slotId = 0x65;
        int i;
        for (i = 0; i < entries->count; i++, slotId++) {
            func_004A1638(slotId);
            func_004A5BF8(slotId, 0xD, entries[i].v0);
            func_0040A1A0(scaled, entries[i].v1, invScale);
            func_004A5BF8(slotId, 0, scaled);
            func_0040A1A0(scaled, entries[i].v2, invScale);
            func_004A5BF8(slotId, 1, scaled);
            func_0040A1A0(scaled, entries[i].v3, invScale);
            func_004A5BF8(slotId, 4, scaled);
        }
        for (; i < 8; i++) func_004AB040(slotId++);
    } else {
        func_00398210(ctx, *(float *)self, *(float *)(self + 4));
    }
}
