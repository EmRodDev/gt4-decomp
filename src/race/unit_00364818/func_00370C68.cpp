/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Restores the camera's backup (see func_00370BE0): copies the saved vector and the value pair back and re-derives the view with
 * func_00370548. */
typedef int s32;
typedef float f32;

struct Pair_00370C68 {
    f32 f;
    s32 i;
};

struct Obj_00370C68 {
    char pad0[0x80];
    s32 m80;
    char pad84[0xD8 - 0x84];
    char mD8[0xC];
    Pair_00370C68 mE4;
    char mEC[0xC];
    Pair_00370C68 mF8;
};

extern "C" void func_005F5040(void *dst, void *src);
extern "C" void func_00370548(Obj_00370C68 *obj, void *v, s32 n);

extern "C" void func_00370C68(Obj_00370C68 *self) {
    func_005F5040(self->mEC, self->mD8);
    self->mE4.f = self->mF8.f;
    self->mE4.i = self->mF8.i;
    func_00370548(self, self->mD8, self->m80);
}
