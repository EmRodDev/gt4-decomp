/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
struct Img { s32 w; s32 h; char pad8[8]; s32 dst; s32 src; char pad18[4]; };
struct Rec { char pad0[0x34]; u32 a0; u32 b0; u32 a1; u32 b1; char pad44[8]; };
struct Obj {
    char pad0[0x80];
    Img img[4];
    char padF0[0x1C];
    Rec rec[4];
    s32 value;
    f32 f240;
    f32 x0;
    f32 dx;
    f32 y0;
    f32 dy;
    char pad254[0x2E0 - 0x254];
    char lock[4];
};
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_001C18B0(s32, s32, s32, s32, s32) throw();
extern "C" void func_001C21E0(Rec *, Img *, f32, f32) throw();
extern "C" int func_001C1D00(s32, s32, s32, u32, u32, s32, s32, u32 *, u32 *) throw();
extern "C" int func_001C1DF8(s32, s32, s32, u32, u32, s32, s32, u32 *, u32 *) throw();
extern "C" void func_001C3958(Obj *self) {
    int i;
    f32 x, y;
    func_00576788(self->lock);
    x = self->x0;
    y = self->y0;
    for (i = 0; i < 4; i++) {
        func_001C18B0(self->img[i].src, self->img[i].dst, self->img[i].w, self->img[i].h, self->value);
        func_001C21E0(&self->rec[i], &self->img[i], x, y);
        s32 w = self->img[i].w;
        s32 h = self->img[i].h;
        func_001C1D00(self->img[i].src, w, h, 0, 0, w, h, &self->rec[i].a0, &self->rec[i].b0);
        func_001C1DF8(self->img[i].src, w, h, 0, 0, w, h, &self->rec[i].a1, &self->rec[i].b1);
        x += self->dx;
        y += self->dy;
    }
    func_005767C0(self->lock);
}
