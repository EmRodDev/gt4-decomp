/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0xC0];
    s32 cols;
};

struct Res {
    char pad0[8];
    f32 w;
    f32 h;
};

extern "C" f32 func_00200EA8(Obj *a);
extern "C" f32 func_00200EB8(Obj *a);
extern "C" f32 func_00200EC8(Obj *a);
extern "C" f32 func_00200ED8(Obj *a);
extern "C" s32 func_00206868(Obj *a);
extern "C" void func_00207208(Obj *a, s32 b, s32 c);
extern "C" s32 func_002073D8(Obj *a, s32 b);
extern "C" Res *func_0025BF60(Obj *a);
extern "C" s32 func_0025C300(s32 a);
extern "C" void func_00263B80(s32 a, f32 *b, f32 *c);
extern "C" f32 func_002B8590(Obj *a) throw();
extern "C" f32 func_002B85A0(Obj *a) throw();

extern "C" void mMBox__virtual_95(Obj *self, s32 arg1) {
    f32 sz[2];
    f32 rowH = 0.0f;
    f32 rowW = 0.0f;
    f32 width = 0.0f;
    f32 height = 0.0f;
    s32 n = 0;
    s32 rows = 0;
    s32 it;
    for (it = func_00206868(self); it != 0; it = func_0025C300(it)) {
        func_00207208(self, arg1, it);
        if (func_002073D8(self, it) != 0) {
            func_00263B80(it, &sz[0], &sz[1]);
            if (n > 0) rowW += func_002B8590(self);
            rowW += sz[0];
            if (rowH < sz[1]) rowH = sz[1];
            n++;
            if (n == self->cols) {
                if (width < rowW) width = rowW;
                if (rows > 0) height += func_002B85A0(self);
                height += rowH;
                n = 0;
                rowH = 0.0f;
                rows++;
                rowW = 0.0f;
            }
        }
    }
    if (n > 0) {
        if (width < rowW) width = rowW;
        if (rows > 0) height += func_002B85A0(self);
        height += rowH;
    }
    {
        f32 a = func_00200EA8(self);
        f32 b = func_00200EB8(self);
        f32 c = func_00200EC8(self);
        f32 d = c + func_00200ED8(self);
        Res *r = func_0025BF60(self);
        height += d;
        width += a + b;
        r->w = width;
        r->h = height;
    }
}
