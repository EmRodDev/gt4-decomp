/* Setter: stores two 32-bit values at +0x38 and +0x3C (purpose unknown). Sibling of func_00475D78 (+0x30/+0x34). */
struct Obj {
    char pad0[0x38];
    int unk38;
    int unk3C;
};
extern "C" void func_00475D88(Obj *self, int first, int second) {
    self->unk38 = first;
    self->unk3C = second;
}
