/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of mScaleBar: runs the mFBox constructor, installs the mScaleBar vtable at +4 and sets the members at +0xC0..+0x104 to their defaults.
 * +0xC0 is 1, +0xC4 is 0; the floats at +0xC8 and +0xD0 are 0.0 and the ones at +0xCC and +0xD4 are 100.0 (two 0..100 ranges; inferred from the constants), +0xD8 is 1.0,
 * the 3-float vector at +0xDC and the floats +0xE8/+0xEC are 0.0, the words +0xF0/+0xF4/+0x100/+0x104 are 0 and the objects at +0xF8 and +0xFC are built by func_002FA120.
 * func_0025B4C8(this, 256.0, 24.0) looks like a default size (inferred from the values), func_00265F10(this, 1) and func_00206858(this, 0) finish it. */
typedef int s32;
typedef float f32;
struct V { f32 x, y, zero; };
struct O {
    char pad[4]; void *vt; char pad1[0xC0 - 8];
    s32 c0, c4; f32 c8, cc, d0, d4, d8;
    V vec;
    f32 e8, ec;
    s32 f0, f4;
    char pad2[8];
    s32 f100, f104;
};
extern char mScaleBar__vtable[];
extern "C" void *mFBox__structor_0(void *);
extern "C" int func_002FA120(void *);
extern "C" void func_0025B4C8(void *, f32, f32);
extern "C" void func_00265F10(void *, s32);
extern "C" void func_00206858(void *, s32);

extern "C" void mScaleBar__structor_0(O *self) {
    mFBox__structor_0(self);
    self->vt = mScaleBar__vtable;
    self->c0 = 1;
    self->c4 = 0;
    f32 zero = *(float *)&self->c4;
    self->c8 = zero;
    self->cc = 100.0f;
    self->d0 = zero;
    self->d4 = 100.0f;
    self->d8 = 1.0f;
    V *vec = &self->vec;
    vec->x = zero;
    vec->y = zero;
    vec->zero = zero;
    self->e8 = zero;
    self->ec = zero;
    self->f0 = 0;
    self->f4 = 0;
    func_002FA120((char *)self + 0xF8);
    func_002FA120((char *)self + 0xFC);
    self->f100 = 0;
    self->f104 = 0;
    func_0025B4C8(self, 256.0f, 24.0f);
    func_00265F10(self, 1);
    return func_00206858(self, 0);
}
