/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TexData {
    char pad0[0x20];
    unsigned long bits;
};

struct Texture {
    char pad0[0x18];
    TexData *data;
};

struct AutomaticFader {
    float value;
    float get() const { return value; }
};

struct Self {
    char pad0[0x18];
    int mode;
    Texture *tex;
    AutomaticFader fader;
    char pad24[0x3C - 0x24];
    float value;
    float other;
    int width;
};

struct Target {
    int id;
    int flags;
};

struct Font {
    int unk0;
    int flags;
    float x;
    float y;
    char pad10[8];
    float sx;
    float sy;
};

extern Font D_00623838;
extern char D_006A1430[];
extern char D_006A1438[];
extern char D_006A1460[];

extern "C" {
void func_001055C0(Target *t);
void func_00105460(Target *t, int w, int h);
int func_00105528(Target *t);
void func_001056A0(Target *t);
void func_003AF4F8(Texture *t, float x0, float y0, float x1, float y1, int filter, int blend);
unsigned int func_003AFEC8(unsigned int color, float alpha);
void func_0044D950(Font *f);
void func_0044D988(Font *f);
void func_0044D9B8(Font *f, const char *name);
void func_0044DE80(Font *f, unsigned int color);
float func_0044DFC8(Font *f, const char *s);
void func_0044E088(Font *f, const char *fmt, ...);
void func_0044E390(Font *f, float sx, float sy);
int func_0044E3B0(Font *f, int w, int h);
void func_004A1638(int mode);
void func_004A2750(int mode, float ref);
void func_004A27C8(int mode);
void func_004A2808(int mode, float ref);
void func_004A2980(int mask);
void func_004A29A8(int on);
void func_004A3078(int on);
void func_004A3230(int on);
void RaceEntryCar__update(int mode);
void func_004A53F8(void);
void func_004A5400(void);
void pglPushAttrib(int mask);
void func_004A5688(void);
void func_004A5A90(float l, float r, float b, float t, float n, float f);
void func_004A7454(void);
void func_004AA168(unsigned int color);
void func_004AA1D8(float r, float g, float b, float a);
void func_004AB040(int mode);
}

extern "C" void RaceMTRMultiFunctionDisplay__render_buffer(Self *self, Target *target)
{
    int w = 8;
    int h = 1;

    pglPushAttrib(1);
    if (self->tex) {
        unsigned long bits = self->tex->data->bits;
        w = ((bits >> 14) & 0x3FF) + 1;
        h = ((bits >> 34) & 0x3FF) + 1;
    }
    if (target->id == -1) {
        func_001055C0(target);
        func_00105460(target, w, h);
        target->flags = 0;
        func_00105528(target);
    }
    func_001056A0(target);
    func_004A2980(-1);
    func_004A3078(0);
    func_004A3230(1);
    if (!self->tex)
        return func_004A5688();

    float fw = (float)w;
    float fh = (float)h;
    func_004AA168(0x80FFFFFF);
    func_004A1638(6);
    func_004AB040(15);
    func_004AB040(5);
    func_004A29A8(0);
    func_004A2808(0x44, 0.0f);
    RaceEntryCar__update(1);
    func_004A53F8();
    func_004A7454();
    func_004A5A90(0.0f, fw, fh, 0.0f, -1.0f, 1.0f);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7454();
    func_004AA1D8(1.0f, 1.0f, 1.0f, self->fader.get());
    func_003AF4F8(self->tex, 0.0f, 0.0f, fw, fh, 0, 0);
    func_004A1638(4);
    func_004A2750(6, self->fader.get() * 0.5f);
    func_004A27C8(0);

    Font *font = &D_00623838;
    float sx = font->sx;
    float sy = font->sy;
    func_0044E390(font, 1.0f, 1.0f);
    func_0044D9B8(font, D_006A1460);
    func_0044E3B0(font, w, h);
    func_0044D950(font);
    if ((float)self->width == 0.0f)
        self->width = (int)func_0044DFC8(font, D_006A1430);

    unsigned int color = 0;
    int value = 0;
    switch (self->mode) {
    case 0:
        break;
    case 1:
        value = (int)self->other;
        color = 0x800255D8;
        break;
    case 2:
        value = (int)self->value;
        color = 0x80B58E43;
        break;
    case 3:
        value = (int)self->value;
        color = 0x800000C6;
        break;
    }
    if (value < 0)
        value = 0;
    else
        value = value >= 1000 ? 999 : value;

    func_0044DE80(&D_00623838, func_003AFEC8(color, self->fader.get()));
    float x = (float)((w >> 1) + self->width);
    float y = (float)((h >> 1) - 1);
    D_00623838.flags = 6;
    D_00623838.y = y;
    D_00623838.x = x;
    func_0044E088(&D_00623838, D_006A1438, value);
    D_00623838.flags = 0;
    func_0044D988(&D_00623838);
    func_004AB040(4);
    RaceEntryCar__update(0);
    func_004A5400();
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
    func_0044E390(&D_00623838, sx, sy);
    func_004A5688();
}
