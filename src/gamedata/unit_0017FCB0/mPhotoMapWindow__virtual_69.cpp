/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mPhotoMapWindow::update (virtual 69): runs the base update, then, when active, feeds the photo
 * mode's zoom camera (input keys in mode 8, zoom limits, rotation), places the two map markers
 * (clamped to the window, rotated toward the edge when clamped), and copies the window's light
 * and focus settings into the photo mode. */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct VEntry { short delta; short index; void *fn; };

struct Ctx { s32 mode; s32 changed; s32 reset; s32 pad; };

struct Sub48 { char pad[8]; f32 value; };

struct Zoom {
    char pad0[8];
    f32 width;
    f32 height;
    char pad10[0x1C - 0x10];
    f32 value;
    char pad20[0x48 - 0x20];
    Sub48 sub48;
    char pad54[0x6C - 0x54];
    f32 rotation;
    char pad70[0xD8 - 0x70];
    f32 fD8;
    char padDC[4];
    f32 fE0;
    f32 fE4;
};

struct Holder { char *vtbl; char pad[0xE28 - 4]; Zoom zoom; };

struct PhotoMode {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    s32 f6C;
    s32 f70;
    char pad74[0x1E668 - 0x74];
    s32 f1E668;
    f32 f1E66C;
    f32 f1E670;
    f32 f1E674;
    f32 f1E678;
    f32 f1E67C;
};

struct Input { char pad[4]; char *vtbl; };
struct Context { char pad[0x10]; Input *input; };

struct Track { s32 a; s32 b; f32 v; };
struct Hist { s32 cur; s32 next; };

struct Win {
    char pad0[0xC0];
    void *wC0;
    void *wC4;
    void *wC8;
    void *wCC;
    void *wD0;
    void *wD4;
    s32 fD8;
    char padDC[0xEC - 0xDC];
    s32 mode;
    s32 prevMode;
    f32 fF4;
    char padF8[4];
    Hist clampA;
    Hist clampB;
    char pad10C[4];
    f32 fade;
    f32 f114;
    f32 f118;
    f32 f11C;
    s32 f120;
    f32 f124;
    s32 f128;
    s32 f12C;
    s32 f130;
    Track t0;
    Track t1;
    Track t2;
    Track t3;
};

struct Game { char pad[0x39DC0]; s32 f39DC0; };
extern Game *D_00622F4C;

extern "C" PhotoMode *func_00192E20(Context *) throw();
extern "C" void func_001939E0(Win *, Input *, Context *) throw();
extern "C" void func_00193B10(Win *, Input *, Context *, s32) throw();
extern "C" void func_00193C88(Win *, Input *, Context *, s32) throw();
extern "C" void func_00194198(Win *, f32) throw();
extern "C" s32 func_001941D8(f32 *px, f32 *py, f32 *angle, f32 width, f32 height) throw();
extern "C" void func_00194308(Win *, PhotoMode *) throw();
extern "C" void func_001943E0(Win *, Context *, s32) throw();
extern "C" f32 func_00238FB8(s32);
extern "C" void func_00250FC0(Input *, s32);
extern "C" void mColorChipFace__virtual_69(Win *, Context *, s32);
extern "C" void func_00266200(void *, s32);
extern "C" void mWidget__setRotate(void *, f32);
extern "C" f32 func_003700F8(Zoom *);
extern "C" f32 func_00370110(Zoom *);
extern "C" f32 func_00370158(Zoom *);
extern "C" f32 func_00370170(Zoom *);
extern "C" f32 func_00370188(Zoom *);
extern "C" f32 func_003701A0(Zoom *);
extern "C" void func_00370240(Zoom *, s32);
extern "C" u32 func_00370950(Zoom *);
extern "C" s32 func_00370CC0(Zoom *);
extern "C" void func_00370D08(Zoom *, f32);
extern "C" void func_00370D98(Zoom *, f32);
extern "C" void func_00377BD0(Ctx *);
extern "C" void func_003C75F0(PhotoMode *, f32, f32, f32);
extern "C" void func_003C7668(PhotoMode *, f32);
extern "C" void func_004272A0(void *, s32);

static inline void *vcall4A8(PhotoMode *pm) {
    VEntry *e = (VEntry *)(pm->vtbl + 0x4A8);
    return ((void *(*)(void *))e->fn)((char *)pm + e->delta);
}

static inline Holder *vcall4B0(PhotoMode *pm) {
    VEntry *e = (VEntry *)(pm->vtbl + 0x4B0);
    return ((Holder *(*)(void *))e->fn)((char *)pm + e->delta);
}

static inline int limit(float width, float height, float *x, float *y, float *angle) {
    return func_001941D8(x, y, angle, width, height);
}

extern "C" void mPhotoMapWindow__virtual_69(Win *self, Context *arg1, s32 active) {
    Ctx ctx;
    f32 x, y, angle;

    mColorChipFace__virtual_69(self, arg1, 0);
    if (active != 0) {
        s32 *mode = &self->mode;
        Input *input = arg1->input;
        PhotoMode *pm = func_00192E20(arg1);
        func_00194308(self, pm);
        s32 changed = self->prevMode != *mode;
        void *s7 = vcall4A8(pm);
        Holder *h = vcall4B0(pm);
        Zoom *z = &h->zoom;
        func_00377BD0(&ctx);
        f32 before = z->value;
        s32 wasOff = func_00370950(z) ^ 1;
        if (*mode != 0) {
            VEntry *e = (VEntry *)(input->vtbl + 0x1D8);
            s32 keys = ((s32 (*)(void *, s32))e->fn)((char *)input + e->delta, 0);
            func_00250FC0(input, 0);
            if (*mode == 8) {
                if (keys & 0x100)
                    func_00370240(z, 1);
                if (keys & 0x800)
                    func_00370240(z, 0);
            }
        }
        func_004272A0(s7, changed);
        ctx.mode = self->mode;
        ctx.changed = changed;
        func_00370D08(z, self->fF4);
        func_00370D98(z, self->f114);
        Sub48 *limit48 = &z->sub48;
        if (D_00622F4C->f39DC0 == 0)
            limit48->value = -1.0f;
        {
            VEntry *e = (VEntry *)(h->vtbl + 0x1E0);
            ((void (*)(void *, s32, s32, Ctx *))e->fn)((char *)h + e->delta, pm->f6C, pm->f70, &ctx);
        }
        f32 now = z->value;
        f32 d = before - now;
        if (d < -0x1.a36e2ep-14f || d > 0x1.a36e2ep-14f) {
            func_00194198(self, now);
            self->f124 = now;
        } else {
            d = now - self->f124;
            if (d < -0x1.a36e2ep-14f || d > 0x1.a36e2ep-14f)
                z->value = func_00238FB8(self->fD8);
        }
        s32 isOff = func_00370950(z) ^ 1;
        if (wasOff != isOff)
            func_001943E0(self, arg1, isOff);

        Track *t0 = &self->t0;
        t0->v = func_00370188(z);
        Track *t1 = &self->t1;
        Track *t2 = &self->t2;
        Track *t3 = &self->t3;
        t1->v = func_003701A0(z);
        t2->v = func_00370158(z);
        t3->v = func_00370170(z);
        switch (self->mode) {
        case 1:
            t0->v = func_003700F8(z);
            t1->v = func_00370110(z);
            func_00266200(self->wC0, func_00370CC0(z) ^ 1);
            break;
        case 2:
            t2->v = func_003700F8(z);
            t3->v = func_00370110(z);
            func_00266200(self->wCC, func_00370950(z) ^ 1);
            break;
        }

        s32 clamped;
        {
            x = t2->v;
            y = t3->v;
            f32 *rot = &z->rotation;
            s32 r = limit(z->width, z->height, &x, &y, &angle);
            clamped = 0;
            if (self->mode != 2)
                clamped = r;
            t2->v = x;
            t3->v = y;
            mWidget__setRotate(self->wD0, *rot);
            mWidget__setRotate(self->wD4, *rot);
            if (clamped != self->clampA.cur)
                func_00193C88(self, input, arg1, clamped);
            if (clamped != 0) {
                mWidget__setRotate(self->wD0, angle + 90.0f);
                mWidget__setRotate(self->wD4, angle + 90.0f);
            }
            Hist *hist = &self->clampA;
            hist->cur = hist->next;
            self->clampA.next = clamped;
        }
        {
            x = t0->v;
            y = t1->v;
            s32 r = limit(z->width, z->height, &x, &y, &angle);
            clamped = 0;
            if (self->mode != 1)
                clamped = r;
            t0->v = x;
            t1->v = y;
            mWidget__setRotate(self->wC4, -z->fE4);
            mWidget__setRotate(self->wC8, -z->fE4);
            if (clamped != self->clampB.cur)
                func_00193B10(self, input, arg1, clamped);
            if (clamped != 0) {
                mWidget__setRotate(self->wC4, angle + 90.0f);
                mWidget__setRotate(self->wC8, angle + 90.0f);
            }
            Hist *hist = &self->clampB;
            hist->cur = hist->next;
            self->clampB.next = clamped;
        }

        func_003C75F0(pm, z->fD8, z->fE0, z->fE4 * 0x1.921fb4p+1f / 180.0f);
        if (ctx.reset != 0) {
            func_00266200(self->wC0, 0);
            func_00266200(self->wCC, 0);
            func_001939E0(self, input, arg1);
        }
        self->fade -= 0x1.eb851cp-6f;
        if (self->fade < 0.0f)
            self->fade = 1.0f;
        if (self->fade > 1.0f)
            self->fade = 1.0f;
        func_003C7668(pm, -self->f118);
        pm->f1E668 = self->f120;
        pm->f1E66C = self->f11C;
        pm->f1E674 = (f32)self->f128 * 0.125f;
        pm->f1E678 = (f32)self->f130 * 2000.0f / 5.0f + 5500.0f;
        pm->f1E67C = (f32)self->f12C;
        pm->f1E670 = 1.0f;
    }
    self->prevMode = self->mode;
}
