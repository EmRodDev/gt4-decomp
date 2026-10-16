/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short pad; void (*fn)(void *, int, int); };

struct VT { char pad[0x38]; VE e38; VE e40; VE e48; };
struct SlotA { unsigned w0; char pad0[0x10]; VT *vt14; char pad2[0x70 - 0x18]; };
struct SlotB { unsigned w0; char pad0[0x10]; VT *vt14; char pad2[0x94 - 0x18]; };
struct Lic {
    char pad0[0x1588];
    unsigned w1588;
    char pad1[0x16BC - 0x158C];
    unsigned w16BC;
    char pad2[0x2D78 - 0x16C0];
    unsigned w2D78;
    char pad3[0x3F30 - 0x2D7C];
    SlotA a[3];
    SlotB b[3];
    char pad4[0x42C8 - 0x423C];
    char s42C8[0x98];
    char s4360[0x1C];
};
static inline void setLow(unsigned *p, unsigned v, unsigned m) { *p = (*p & m) | v; }
extern "C" void RaceDisplay__virtual_33();
extern "C" void RaceDisplayObjectBase__setLocation(void *, int, int);
extern "C" void RaceMiniMap__virtual_07(void *, int, int);
extern "C" void RaceDisplayObjectBase__setAlignment(void *, int, int);

extern "C" void RaceLicenseDisplay__virtual_33(Lic *o)
{
    SlotB *pb = o->b;
    SlotA *pa = o->a;
    int k = 0x6E;
    int i = 2;
    RaceDisplay__virtual_33();
    unsigned *q1 = &o->w1588, *q2 = &o->w16BC, *q3 = &o->w2D78;
    *q1 &= ~0xFF;
    *q2 &= ~0xFF;
    *q3 &= ~0xFF;
    do {
        i--;
        { VE *v = &pa->vt14->e48;
        v->fn((char *)pa + v->delta, 0xD, 0);
        }
        { VE *v = &pa->vt14->e40;
        v->fn((char *)pa + v->delta, 0, 0);
        }
        { VE *v = &pa->vt14->e38;
        v->fn((char *)pa + v->delta, 0x260, k);
        }
        setLow(&pa->w0, 1, ~0xFFu);
        pa++;
        { VE *v = &pb->vt14->e48;
        v->fn((char *)pb + v->delta, 0xE, 0);
        }
        { VE *v = &pb->vt14->e40;
        v->fn((char *)pb + v->delta, 0, 0);
        }
        { VE *v = &pb->vt14->e38;
        int t = k;
        k += 0x1C;
        v->fn((char *)pb + v->delta, 0x248, t);
        }
        setLow(&pb->w0, 1, ~0xFFu);
        pb++;
    } while (i >= 0);
    char *s0 = o->s42C8;
    RaceDisplayObjectBase__setAlignment(s0, 6, 1);
    RaceMiniMap__virtual_07(s0, 0x64, 0);
    char *s1 = o->s4360;
    RaceDisplayObjectBase__setLocation(s0, 0x87, 0x4A);
    RaceDisplayObjectBase__setAlignment(s1, 6, 0);
    RaceMiniMap__virtual_07(s1, 0x1E, 0x23);
    RaceDisplayObjectBase__setLocation(s1, 0x87, 0x14);
}
