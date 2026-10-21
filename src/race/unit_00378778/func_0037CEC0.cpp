/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialiser (inferred from the call-first shape): runs func_00379CE0(self, baseArg, 0), sets the field at +0x148 to 5, and when
 * resetFlag is non-zero clears the word at +0x2C0 byte by byte (the byte-wise store then mask is the form that matched) and sets the
 * word at +0x2C4 to -1. When initialValue is given, its word is copied to +0x2C0. Ends with func_0037CFC8(self). Meaning of the words unknown. */
typedef int s32;
typedef unsigned char u8;

struct Obj { char pad0[0x148]; s32 u148; char pad1[0x2c0 - 0x14c]; s32 word2C0; s32 word2C4; };
extern "C" void func_00379CE0(Obj *, s32, s32) throw();
extern "C" void func_0037CFC8(Obj *);

extern "C" void func_0037CEC0(Obj *self, s32 baseArg, s32 resetFlag, s32 *initialValue) {
    char *wordPtr;

    func_00379CE0(self, baseArg, 0);
    self->u148 = 5;
    if (resetFlag != 0) {
        wordPtr = (char *)self + 0x2C0;
        *(u8 *)wordPtr = 0;
        *(u8 *)(wordPtr + 1) = 0;
        *(s32 *)wordPtr = *(s32 *)wordPtr & 0xFF00FFFF;
        *(u8 *)(wordPtr + 3) = 0;
        self->word2C4 = -1;
    }
    if (initialValue != 0) {
        self->word2C0 = *initialValue;
    }
    func_0037CFC8(self);
}
