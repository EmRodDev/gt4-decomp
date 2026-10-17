/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect16 {
    short x, y, w, h;
};

struct Widget {
    char pad0[4];
    int enabled;
    int dirty;
    int h;
    char pad1[0x1C - 0x10];
    int x;
    int y;
    int w;
    char pad2[0x5C - 0x28];
    int source;
};

extern "C" char D_006550F8[];
extern "C" Rect16 func_00565EF8(char *table, int source);

extern "C" void func_00556630(Widget *self)
{
    Rect16 r = func_00565EF8(D_006550F8, self->source);
    self->x = r.x;
    self->y = r.y;
    self->w = r.w;
    self->h = r.h;
    self->enabled = 1;
    self->dirty = 0;
}
