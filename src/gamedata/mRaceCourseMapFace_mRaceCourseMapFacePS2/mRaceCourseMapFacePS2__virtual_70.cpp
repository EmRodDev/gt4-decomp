typedef unsigned int u32;
typedef unsigned long u64;
typedef int s32;
typedef float f32;

struct Tex {
    char pad0[0x20];
    u64 bits;
};

struct Surface {
    char pad0[0x18];
    Tex *tex;
};

struct V2 {
    f32 x, y;
};

struct View {
    char pad0[0x28];
    Surface *surface;
    u32 count;
    V2 *points;
};

struct Color {
    f32 r, g, b, a;
};

struct Obj {
    char pad0[0xA0];
    Color color;
    Color line;
    s32 enabled;
    char padC4[4];
    View *view;
    char padCC[8];
    f32 length;
    f32 start;
    f32 end;
};

struct Entry {
    short delta, index;
    void (*fn)(void *, int, V2 *, V2 *, int);
};

struct Render {
    int z;
    char *vt;
};

extern "C" {
void mWidget__virtual_70(Obj *, Render *, int);
void func_004AB040(u32);
void func_004A1638(u32);
void func_004A2808(signed char, f32);
void func_00129010(Obj *, Render *, f32, f32);
f32 func_00231420(Render *);
f32 func_00231440(Render *);
int func_00499728(Surface *);
void func_0049CC48(Tex *);
void func_004A4810(int, unsigned int, unsigned int);
void func_004A4550(unsigned, int);
void func_004AA1D8(f32, f32, f32, f32);
void RaceEntryCar__update(int);
void func_004A53F8(void);
void func_004A5400(void);
void func_004A7844(f32, f32, f32);
void func_001292E0(Obj *, Render *, f32, f32);
void func_004A2750(int, f32);
void func_004A27C8(unsigned);
}

#define TEX_W(t) ((((t)->bits >> 14) & 0x3FF) + 1)
#define TEX_H(t) ((((t)->bits >> 34) & 0x3FF) + 1)

static inline u32 pow2(u32 x) {
    u32 n;
    __asm__("plzcw %0, %1" : "=r"(n) : "r"(x));
    return 1u << ((n & 31) ^ 31);
}

static inline void setColor(Color *c) {
    func_004AA1D8(c->r, c->g, c->b, c->a);
}

static inline void draw(Render *r, V2 *xy, V2 *uv) {
    Entry *e = (Entry *)(r->vt + 0x1B0);
    e->fn((char *)r + e->delta, 4, xy, uv, 0);
}

extern "C" void mRaceCourseMapFacePS2__virtual_70(Obj *self, Render *r) {
    mWidget__virtual_70(self, r, 0);
    if (self->view == 0) return;
    Surface *s = self->view->surface;
    if (s == 0) return;
    Tex *t = s->tex;
    f32 zero = 0.0f;
    u32 w = TEX_W(t);
    u32 h = TEX_H(t);
    f32 cx = (s32)w / 2;
    f32 cy = (s32)h / 2;
    func_004AB040(0xF);
    func_004AB040(0x11);
    func_004AB040(5);
    func_004AB040(4);
    func_004AB040(8);
    func_004A1638(6);
    func_004A2808(0x44, zero);
    func_00129010(self, r, cx, cy);
    f32 right = zero + func_00231420(r);
    f32 bottom = zero + func_00231440(r);
    V2 xy[4];
    xy[0].x = zero;
    xy[0].y = zero;
    xy[1].x = right;
    xy[1].y = zero;
    xy[2].x = zero;
    xy[2].y = bottom;
    xy[3].x = right;
    xy[3].y = bottom;
    func_00499728(s);
    func_0049CC48(t);
    f32 fw = w;
    u32 wm1 = w - 1;
    f32 u = fw / pow2(wm1);
    f32 fh = h;
    u32 hm1 = h - 1;
    f32 v = fh / pow2(hm1);
    V2 uv[4];
    V2 *puv = uv;
    puv[0].x = 0.0f;
    puv[0].y = 0.0f;
    puv[1].x = u;
    puv[1].y = 0.0f;
    puv[2].x = 0.0f;
    puv[2].y = v;
    puv[3].x = u;
    puv[3].y = v;
    func_004A1638(2);
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    func_004A4810(0, 0, wm1);
    func_004A4810(1, 0, hm1);
    func_004A4550(4, 2);
    func_004A4550(5, 2);
    setColor(&self->color);
    draw(r, xy, puv);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7844(cx, cy, 0.0f);
    View *view = self->view;
    if (view != 0) {
        V2 *points = view->count ? view->points : 0;
        if (self->enabled && points) {
            func_004AB040(2);
            func_004AB040(6);
            setColor(&self->line);
            f32 start = self->start;
            f32 end = self->end;
            f32 span = self->length;
            if (span <= end - start) {
                start = 0.0f;
                end = span;
            } else {
                while (start < 0.0f) {
                    start += span;
                    end += span;
                }
                while (self->length <= start) {
                    start -= self->length;
                    end -= self->length;
                }
            }
            if (end <= span) {
                func_001292E0(self, r, start, end);
            } else {
                func_001292E0(self, r, start, span);
                func_001292E0(self, r, 0.0f, end - self->length);
            }
        }
    }
    RaceEntryCar__update(0);
    func_004A5400();
    func_004A1638(4);
    func_004A2750(6, 0.5f);
    func_004A27C8(0);
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    func_00129010(self, r, cx, cy);
    func_004AB040(4);
}
