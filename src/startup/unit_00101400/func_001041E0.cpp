/* Copies one of two 16-byte blocks of the object into *out and returns out: the block at +0x1C when the word at +8 is
 * non-zero, otherwise the block at +0xC. */
typedef struct S16 { char data[16]; } S16;
typedef int s32;

struct Obj1_001041E0 {
    char pad0[8];
    s32 unk8;
    S16 unkC;
    S16 unk1C;
};

extern "C" void *func_001041E0(void *out, struct Obj1_001041E0 *self) {
    S16 *chosen = self->unk8 ? &self->unk1C : &self->unkC;
    *(S16 *)out = *chosen;
    return out;
}
