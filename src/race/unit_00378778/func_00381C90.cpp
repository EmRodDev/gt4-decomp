/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Setup routine of an object whose base initializer is func_00378CB8 (inferred from the call made first). It
 * stores the enable flag at +0x184 and the value 10 at +0x148, and only when enabled runs one of three setup
 * helpers chosen by kind: 0 calls func_00381D88, 1 calls func_003821F0, anything else calls func_00382708 (the
 * param and float go only to the first two). The helper input is a pointer found at owner+0x10 then +0x18 (purpose
 * unknown); kind goes to +0x188 and the helper result to +0x18C. It always clears +0xE8 and +0xEC and sets byte 2
 * of the 64-bit word at +0x168 to 1. The explicit case 2 before default is what makes the compiler emit the
 * original compare order (see knowledge/ee-gcc-2.96.md). */
typedef int s32;
typedef float f32;
typedef long long s64;

struct Inner { char pad[0x18]; void *unk18; };
struct Arg1 { char pad[0x10]; Inner *unk10; };
struct Obj {
    char pad0[0xE8];
    s32 mE8;
    s32 mEC;
    char pad1[0x148 - 0xF0];
    s32 state;
    char pad2[0x168 - 0x14C];
    s64 flags64;
    char pad3[0x184 - 0x170];
    s32 enabled;
    s32 kind;
    s32 setupResult;
};

extern "C" void func_00378CB8(void *) throw();
extern "C" s32 func_00381D88(Obj *, void *, s32, f32);
extern "C" s32 func_003821F0(Obj *, void *, s32, f32);
extern "C" s32 func_00382708(Obj *, void *);

extern "C" void func_00381C90(Obj *self, Arg1 *owner, s32 enable, s32 param, s32 kind, f32 scale) {
    func_00378CB8(self);
    self->enabled = enable;
    self->state = 10;
    if (enable != 0) {
        void *p = owner->unk10->unk18;
        s32 r;
        switch (kind) {
        case 0:
            r = func_00381D88(self, p, param, scale);
            break;
        case 1:
            r = func_003821F0(self, p, param, scale);
            break;
        case 2:
        default:
            r = func_00382708(self, p);
            break;
        }
        self->kind = kind;
        self->setupResult = r;
    }
    self->mE8 = 0;
    self->mEC = 0;
    self->flags64 = (self->flags64 & ~(0xFFLL << 16)) | (1LL << 16);
}
