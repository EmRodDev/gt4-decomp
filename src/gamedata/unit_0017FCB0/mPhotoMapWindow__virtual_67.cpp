/* compiler: ee-gcc2.96-stl */
/* mPhotoMapWindow::initialize (virtual 67): after the base initialisation, looks up the map's
 * child widgets by name ("car" with its "body" and "shadow", "camera" with its "body" and
 * "shadow", "zoom", "cursor", "hotspot") and the "onPhotoViewDisable" handler; on the first call
 * it also sizes the photo mode's map camera to the window and copies the zoom state. */
typedef float f32;

struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
struct VEntry { short delta, index; void *fn; };

struct Zoom { char pad[0x1C]; f32 value; };
struct Holder { char *vtbl; char pad[0xE28 - 4]; Zoom zoom; };
struct PhotoMode { char pad0[0x64]; char *vtbl; char pad68[4]; int f6C; };

struct Win {
    char pad0[0xC0];
    void *car;
    void *carBody;
    void *carShadow;
    void *camera;
    void *cameraBody;
    void *cameraShadow;
    void *zoom;
    void *cursor;
    void *hotspot;
    int onDisable[1];
    int initialized;
};

extern Rep D_00659FA8;
extern char D_00692180[], D_00692188[], D_006921C8[], D_006921D0[], D_006921D8[], D_006921E0[],
    D_006921E8[], D_006921F0[];

extern "C" PhotoMode *func_00192E20(void *) throw();
extern "C" void func_00194148(Win *, f32, f32);
extern "C" void func_00194190(Win *, f32);
extern "C" void func_00194198(Win *, f32);
extern "C" void func_00204D30(void *, int);
extern "C" void *func_00204D88(void *, void *);
extern "C" void func_00236680(void *, int);
extern "C" int func_002366D8(void *, void *);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);
extern "C" void mTextFace__virtual_67(Win *, void *);
extern "C" void func_003069F8(void *, void *, int *);
extern "C" void func_00309378(void *, int);
extern "C" void *func_0030BB18(void *);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" f32 func_0036FD98(Zoom *);
extern "C" f32 func_00370230(Zoom *);
extern "C" void func_00377BE0(Holder *, f32, f32, f32, f32);
extern "C" int func_0057F260(const char *) throw();
extern "C" Info *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, int, int, const char *, int);

/* out = the child of obj named text; the name goes through a temporary string. */
#define FIND(obj, out, pn, str, text) { \
    const char *src = text; \
    Rep *r = &D_00659FA8; \
    Str *ps = str; \
    char *p; \
    if (r->sel) p = func_005C2560(r); \
    else { p = (char *)(r + 1); r->ref++; } \
    ps->p = p; \
    func_005C2630(ps, 0, -1, src, func_0057F260(src)); \
    (pn)[0] = HSymID__GetID(ps); \
    func_003069F8(obj, out, pn); \
    Rep *q = (Rep *)(ps->p - 16); \
    if (--q->ref == 0) { int size = q->cap + 16; func_00326798(q, size, 4, func_005C11A8()->name); } \
}

extern "C" void mPhotoMapWindow__virtual_67(Win *self, void *ctx) {
    int h[4];
    int name[4];
    Str s20;
    int name30[4];
    Str s40, s50, s60;
    int name70[4];
    Str s80, s90;
    f32 width, height;

    mTextFace__virtual_67(self, ctx);
    func_0030BB18(h);
    int *pn = name;
    Str *ps20 = &s20;
    FIND(self, h, pn, ps20, D_00692180);
    if (__builtin_expect(h[0], 0)) {
        func_00204D88(pn, h);
        self->car = (void *)pn[0];
        int *pb = name30;
        FIND(self->car, h, pb, &s40, D_006921C8);
        if (__builtin_expect(h[0], 0)) {
            func_00204D88(pb, h);
            self->carBody = (void *)pb[0];
            func_00204D30(pb, 2);
        }
        FIND(self->car, h, pb, &s50, D_006921D0);
        if (__builtin_expect(h[0], 0)) {
            func_00204D88(pb, h);
            self->carShadow = (void *)pb[0];
            func_00204D30(pb, 2);
        }
        func_00204D30(pn, 2);
    }
    FIND(self, h, pn, &s60, D_00692188);
    if (__builtin_expect(h[0], 0)) {
        func_00204D88(pn, h);
        self->camera = (void *)pn[0];
        int *pb = name70;
        FIND(self->camera, h, pb, &s80, D_006921C8);
        if (__builtin_expect(h[0], 0)) {
            func_00204D88(pb, h);
            self->cameraBody = (void *)pb[0];
            func_00204D30(pb, 2);
        }
        FIND(self->camera, h, pb, &s90, D_006921D0);
        if (__builtin_expect(h[0], 0)) {
            func_00204D88(pb, h);
            self->cameraShadow = (void *)pb[0];
            func_00204D30(pb, 2);
        }
        func_00204D30(pn, 2);
    }
    FIND(self, h, pn, ps20, D_006921D8);
    if (__builtin_expect(h[0], 0)) {
        func_002366D8(pn, h);
        self->zoom = (void *)pn[0];
        func_00236680(pn, 2);
    }
    FIND(self, h, pn, ps20, D_006921E0);
    if (__builtin_expect(h[0], 0)) {
        func_00204D88(pn, h);
        self->cursor = (void *)pn[0];
        func_00204D30(pn, 2);
    }
    FIND(self, h, pn, ps20, D_006921E8);
    if (__builtin_expect(h[0], 0)) {
        func_00204D88(pn, h);
        self->hotspot = (void *)pn[0];
        func_00204D30(pn, 2);
    }
    FIND(self, self->onDisable, pn, ps20, D_006921F0);
    if (self->initialized == 0) {
        f32 one = 1.0f;
        mWidget__getWindowSize(self, &width, &height);
        PhotoMode *pm = func_00192E20(ctx);
        VEntry *e = (VEntry *)(pm->vtbl + 0x4B0);
        Holder *cam = ((Holder *(*)(void *))e->fn)((char *)pm + e->delta);
        Zoom *zoom = &cam->zoom;
        VEntry * e2 = (VEntry *)(pm->vtbl + 0x4A8);
        void *target = ((void *(*)(void *))e2->fn)((char *)pm + e2->delta);
        VEntry * e3 = (VEntry *)(cam->vtbl + 0xA8);
        ((void (*)(void *, int))e3->fn)((char *)cam + e3->delta, pm->f6C);
        func_00377BE0(cam, width, height, one, one);
        VEntry * e4 = (VEntry *)(cam->vtbl + 0x1D8);
        ((void (*)(void *, f32, f32, f32))e4->fn)((char *)cam + e4->delta, width, height, one);
        VEntry * e5 = (VEntry *)(cam->vtbl + 0x1D0);
        ((void (*)(void *, void *))e5->fn)((char *)cam + e5->delta, target);
        f32 a = func_00370230(zoom);
        f32 b = func_0036FD98(zoom);
        func_00194148(self, a, b);
        func_00194198(self, zoom->value);
        func_00194190(self, zoom->value);
        self->initialized = 1;
    }
    func_00309378(h, 2);
}
