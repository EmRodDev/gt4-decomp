/* Passes the field at +0x14 and the object itself to func_004FAC78. Sibling of func_004FAC58 (func_004FAC30); purpose unknown. */
typedef int s32;

struct S004FAC58 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_004FAC78(s32 self, struct S004FAC58 *arg1);

extern "C" void func_004FACC8(struct S004FAC58 *self) {
    func_004FAC78(self->unk14, self);
}
