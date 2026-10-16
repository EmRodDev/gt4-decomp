/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short pad; void (*fn)(void *); };
struct VT { char pad[0x20]; VE e; };
struct SlotA { char pad0[0xC]; float fC; char pad1[4]; VT *vt14; char pad2[0x70 - 0x18]; };
struct SlotB { char pad0[0xC]; float fC; char pad1[4]; VT *vt14; char pad2[0x94 - 0x18]; };
struct Elem { int w0; char pad0[8]; float fC; char pad1[0x1C - 0x10]; };
struct Lic {
    char pad0[4]; void *p4; char pad1[8]; int i10;
    char pad2[0x38 - 0x14];
    int w38;
    char pad3[0xBC - 0x3C]; float fBC;
    char pad4[0x3F30 - 0xC0];
    SlotA a[3];
    SlotB b[3];
    Elem e[5];
    Elem e5;
    char pad5[0x4360 - 0x42E4];
    Elem e6;
};
extern "C" int DynamicsConductor__GetNumberOfPylonsToBeTouched(int);
extern "C" int DynamicsConductor__GetNumberOfPylonsTouched(int);
extern "C" void RaceDisplay__update(void *, float);
extern "C" void RaceValueDisplayBase__update(void *);
extern "C" void AutomaticFader__update(void *, float);
extern "C" void RaceRichCountDisplay__setCount(void *, int);
extern "C" void RaceLicenseDisplay__update_pass_check(void *, void *);

static inline void enable(Elem *e, unsigned char value) {
    e->w0 = (e->w0 & ~0xFF) | value;
}

extern "C" void RaceLicenseDisplay__update(Lic *o, float f)
{
    int i, j;
    RaceDisplay__update(o, f);
    for (i = 0; i < 5; i++) AutomaticFader__update(&o->e[i], f);
    void *s5 = o->p4;
    for (j = 0; j < 3; j++) {
        float x = *(float *)&o->e[j+1];
        SlotA *pa = &o->a[j];
        SlotB *pb = &o->b[j];
        pa->fC = x;
        pb->fC = x;
        VE *v = &pa->vt14->e;
        v->fn((char *)pa + v->delta);
        VE *w = &pb->vt14->e;
        w->fn((char *)pb + w->delta);
    }
    if (DynamicsConductor__GetNumberOfPylonsToBeTouched(o->i10) > 0) {
        Elem *s0 = &o->e5;
        RaceRichCountDisplay__setCount(s0, DynamicsConductor__GetNumberOfPylonsTouched(o->i10));
        float *t = &o->fBC;
        Elem *s6 = &o->e6;
        s0->fC = *t;
        enable(s0, 1);
        s6->fC = *t;
        enable(s6, 1);
        o->w38 = (o->w38 & 0xFF00FFFF) | 0x10000;
    }
    RaceValueDisplayBase__update(&o->e5);
    RaceLicenseDisplay__update_pass_check(o, s5);
}
