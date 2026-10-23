/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Font { int f0; int mode; };
struct Self {
    unsigned char p0, fx, fy, p3;
    short x, y;
    char pad8[4];
    float alpha;
    char pad10[8];
    char *title;
    char *artist;
    char pad20[8];
    float fade;
};

extern Font D_00623838;
extern char D_006A1870[];
extern char D_006A1878[];
extern char D_006A1880[];
extern char D_006A1888[];

extern "C" {
float RaceDisplayUtil__wideOffset(int);
unsigned int func_003AFEC8(unsigned int, float);
void func_0044D920(Font *, const char *);
void func_0044D988(Font *);
void func_0044DBC0(Font *, float, float);
void func_0044DDF8(Font *, float, float, float);
void func_0044DE80(Font *, unsigned int);
void GT3OLDFONT__GT3OldFontManagerClass__setShadowValue(Font *, float);
void GT3OLDFONT__GT3OldFontManagerClass__putstring(Font *, const char *);
}

extern "C" void RaceMusicDisplay__render_main(Self *self) {
    float a = self->fade * self->alpha;
    if (a <= 0.0f)
        return;
    func_0044DE80(&D_00623838, func_003AFEC8(0x80C8C8C8, a));
    D_00623838.mode = 0;
    GT3OLDFONT__GT3OldFontManagerClass__setShadowValue(&D_00623838, 2.0f);
    float x = (float)self->x + RaceDisplayUtil__wideOffset(4);
    if (self->title) {
        func_0044D920(&D_00623838, D_006A1870);
        func_0044DBC0(&D_00623838, 1.0f, 1.0f);
        func_0044DDF8(&D_00623838, x - 16.0f, (float)self->y, 0.0f);
        GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00623838, D_006A1878);
        func_0044D920(&D_00623838, D_006A1880);
        func_0044DBC0(&D_00623838, 0x1.ccccccp-1f, 0x1.ccccccp-1f);
        func_0044DDF8(&D_00623838, x, (float)self->y, 0.0f);
        GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00623838, self->title);
        if (self->artist) {
            func_0044D920(&D_00623838, D_006A1888);
            func_0044DBC0(&D_00623838, 0x1.666666p-1f, 0x1.666666p-1f);
            func_0044DDF8(&D_00623838, x, (float)(self->y + 18), 0.0f);
            GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00623838, self->artist);
        }
    }
    func_0044DBC0(&D_00623838, 1.0f, 1.0f);
    GT3OLDFONT__GT3OldFontManagerClass__setShadowValue(&D_00623838, 0.0f);
    func_0044D988(&D_00623838);
}
