struct RichCount {
    char pad0[0x20];
    int texture;
    char pad24[0x44 - 0x24];
    signed char x;
    signed char y;
    char pad46[0x6C - 0x46];
    int total;
};
struct ValueText {
    char pad0[0x20];
    int texture;
    char pad24[0x44 - 0x24];
    signed char x;
    signed char y;
    char pad46[0x88 - 0x46];
    int text;
    float size;
    int f90;
};
struct Fader {
    char pad[0x1C];
};
struct Counter {
    char pad0[0x18];
    unsigned int color;
};
struct Lic {
    char pad0[4];
    void *org;
    char pad8[8];
    int layout;
    char pad14[0x3F30 - 0x14];
    struct RichCount rank[3];
    struct ValueText label[3];
    struct Fader fader[5];
    struct Counter pylons;
    char pad42E4[0x4360 - 0x42E4];
    char icon[0x1C];
    int i437C;
    int i4380;
    int i4384;
};
struct LicTex {
    int texture;
    int text;
};
extern const struct LicTex D_006A2810[];
extern char D_006A2828[];
extern char D_006A2830[];
extern "C" int DynamicsConductor__GetNumberOfPylonsToBeTouched(int);
extern "C" void RaceDisplay__initialize(struct Lic *);
extern "C" int func_003A1E10(int);
extern "C" void AutomaticFader__oneshot(struct Fader *, float, float, float, float);
extern "C" void AutomaticFader__reset(struct Fader *);
extern "C" void RaceRichCountDisplay__setTotal(struct Counter *, int);
extern "C" void RaceValueDisplay__setFont(struct ValueText *, char *);
extern "C" int DisplayRText__getRTextStr(int);
extern "C" void RaceDisplayObjectBase__selectTexture(void *, char *);
extern "C" int RaceLicenseDisplay__get_real_entry_car_count(struct Lic *, void *);
extern "C" int RaceOrganization__getLicenseRank(void *, int);

extern "C" void RaceLicenseDisplay__initialize(struct Lic *o)
{
    RaceDisplay__initialize(o);
    void *org = o->org;
    for (int i = 0; i < 3; i++) {
        struct RichCount *r = &o->rank[i];
        int rank = RaceOrganization__getLicenseRank(org, i + 1);
        struct ValueText *t = &o->label[i];
        r->total = rank;
        int tex = D_006A2810[i].texture;
        r->x = -15;
        r->y = 8;
        t->y = 11;
        t->x = -15;
        int v = func_003A1E10(tex);
        r->texture = v;
        t->texture = v;
        int text = DisplayRText__getRTextStr(D_006A2810[i].text);
        t->size = 40.0f;
        t->text = text;
        t->f90 = 0;
        RaceValueDisplay__setFont(t, D_006A2828);
    }
    struct Counter *pylons = &o->pylons;
    pylons->color = 0x80C8C8C8;
    RaceRichCountDisplay__setTotal(pylons, DynamicsConductor__GetNumberOfPylonsToBeTouched(o->layout));
    RaceDisplayObjectBase__selectTexture(o->icon, D_006A2830);
    o->i437C = RaceLicenseDisplay__get_real_entry_car_count(o, org) >= 2;
    o->i4380 = RaceLicenseDisplay__get_real_entry_car_count(o, org) < 4;
    o->i4384 = 0;
    for (int k = 0; k < 5; k++) {
        AutomaticFader__reset(&o->fader[k]);
        AutomaticFader__oneshot(&o->fader[k], 0.5f, -1.0f, 0.5f, 0.0f);
    }
}
