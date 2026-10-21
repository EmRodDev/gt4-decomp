/* Returns the sum of the two 16-bit fields at +0x12 and +0x14; the same function as func_004798B0, kept as its own copy with local typedefs. */
typedef int s32;
typedef short s16;
struct Obj004798B0 {
    char pad[0x12];
    s16 unk12;
    s16 unk14;
};
extern "C" s32 func_004798C0(struct Obj004798B0 *self) {
    return self->unk12 + self->unk14;
}
