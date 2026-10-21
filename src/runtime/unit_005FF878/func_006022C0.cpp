/* Overwrites the 12-byte record at +0x16A4 with the one passed in, but keeps the first word of the old record
 * (it is saved and written back), so only the last two words are really replaced (purpose of the record unknown).
 * The unused spare[4] local only reproduces the original stack frame size (inferred: nothing reads it). */
typedef int s32;

struct S12 {
    s32 word0;
    s32 word1;
    s32 word2;
};

struct Obj {
    char pad[0x16A4];
    s32 unk16A4;
};

extern "C" void func_006022C0(Obj *self, S12 *newRecord) {
    s32 spare[4];
    s32 savedFirstWord = self->unk16A4;
    S12 *record = (S12 *)((char *)self + 0x16A4);
    *record = *newRecord;
    self->unk16A4 = savedFirstWord;
}
