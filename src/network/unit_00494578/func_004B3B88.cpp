/* Clears five consecutive integer fields at +0x0..+0x10 of the record (an init/reset helper, inferred from the shape; the fields are unnamed in the library). Same body as func_004AF6B8. */
struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

extern "C" void func_004B3B88(Obj *self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
}
