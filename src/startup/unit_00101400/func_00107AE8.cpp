/* Resets a 5-word record to its 'empty' state: the first word becomes -1 (read as 'none', inferred from the sentinel) and the
 * words at +4, +8 and +0x10 become 0; the word at +0xC is left alone. Purpose of the record unknown. */
struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};
extern "C" void func_00107AE8(Obj *self) {
    self->unk0 = -1;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unk10 = 0;
}
