/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Fader { float value; float get() const { return value; } };
struct Self {
    unsigned char p0, fx, fy, p3;
    short x, y, w, h;
    float alpha;
    char p10[8];
    unsigned color, color2;
    void *tex;
    float width;
    Fader fader;
    char p2c[0x18];
    signed char dx, dy;
    char text[0x22];
    int mode, time;
};
struct Font { char p0[0x18]; float scale; };
extern Font D_00623838;
extern char D_006A1460[];
extern "C" {
void func_003AEF18(void *, float, float, unsigned, unsigned);
float func_003AFD18(int, float, float);
unsigned func_003AFEC8(unsigned, float);
void RaceDisplayUtil__timeToString(char *, int);
void func_003B00A8(char *, int);
void func_0044D920(void *, void *);
void func_0044D988(void *);
void func_0044DDF8(void *, float, float, float);
void func_0044DE80(void *, unsigned);
float func_0044DFC8(void *, void *);
void func_0044E030(void *, void *);
void func_004AA1D8(float, float, float, float);
}

extern "C" void RaceTimeDisplay__render_main(Self *s) {
    char buf[16];
    func_0044D920(&D_00623838, D_006A1460);
    func_0044DE80(&D_00623838, func_003AFEC8(s->color, s->alpha * s->fader.get()));
    if (s->mode)
        func_003B00A8(buf, s->time);
    else
        RaceDisplayUtil__timeToString(buf, s->time);
    float scale = 1.0f / D_00623838.scale;
    float x = func_003AFD18(s->fx, (float)s->x, func_0044DFC8(&D_00623838, buf) * scale);
    float y = (float)s->y;
    func_0044DDF8(&D_00623838, x, y, 0.0f);
    func_0044E030(&D_00623838, buf);
    if (s->tex) {
        func_0044D988(&D_00623838);
        func_004AA1D8(1.0f, 1.0f, 1.0f, s->alpha * s->fader.get());
        func_003AEF18(s->tex, x + (float)(s->w + s->dx), (float)(s->y + s->h + s->dy), 1, 1);
    }
    if (s->text[0]) {
        func_0044D920(&D_00623838, D_006A1460);
        if (s->width == 0.0f)
            s->width = func_0044DFC8(&D_00623838, s->text) * scale;
        unsigned color = s->color2;
        if (!color) color = s->color;
        func_0044DE80(&D_00623838, func_003AFEC8(color, s->alpha * s->fader.get()));
        func_0044DDF8(&D_00623838, x + (float)s->w - s->width, y, 0.0f);
        func_0044E030(&D_00623838, s->text);
    }
    func_0044D988(&D_00623838);
}
