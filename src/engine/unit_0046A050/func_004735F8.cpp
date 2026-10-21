/* Clears the two 32-bit fields at +8 and +0x14 (a reset; purpose unknown). Sibling of func_004735E8, which sets +8 to 1 instead. */
struct Obj4735F8 {
    char pad[0x8];
    int unk8;
    char pad2[0x14 - 0x8 - 4];
    int unk14;
};
extern "C" void func_004735F8(Obj4735F8 *self) {
    self->unk8 = 0;
    self->unk14 = 0;
}
