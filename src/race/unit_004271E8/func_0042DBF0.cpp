/* Points the field at +4 to the address +8 inside the same object, i.e. a pointer to the object's own trailing storage (inferred from the
 * arithmetic only; what lives at +8 is purpose unknown). The field was renamed from unk4 on that basis only as a description of its value. */
struct Obj {
    char pad0[0x4];
    void *selfLink;
};

extern "C" void func_0042DBF0(Obj *self) {
    self->selfLink = (char *)self + 8;
}
