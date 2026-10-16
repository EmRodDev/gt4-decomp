/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct R {
    char pad0[7];
    char c7;
    char pad8[0x260 - 8];
    unsigned short h260;
    char c262;
    char c263;
    int w264;
    int w268;
    short h26C;
    short h26E;
    short h270;
    short h272;
    char pad274[0x2A8 - 0x274];
    float f2A8;
    float f2AC;
    int w2B0;
    int w2B4;
    float f2B8;
    float f2BC;
};
extern "C" void func_004A2558(R *);
extern "C" void func_004A2BC8(R *);
extern "C" long func_004A2D20(int, int, int, int);

extern "C" long func_004A2478(unsigned int a0, char a1, int a2, int a3) {
    R *r = (R *)spr_base();
    int v0 = (0x1000 - a2) * 8;
    int t0 = (0x1000 - a3) * 8;
    r->c263 = a1;
    int blocks = a2 + 0x3F;
    int a6 = v0 + a2 * 16;
    int a7 = t0 + a3 * 16;
    r->h260 = a0 >> 6;
    r->c262 = blocks >> 6;
    r->h270 = a6;
    r->h272 = a7;
    r->f2A8 = 0.5f;
    r->f2B8 = 1.0f;
    r->f2AC = 0.5f;
    r->f2BC = 1.0f;
    r->h26C = v0;
    r->h26E = t0;
    r->w264 = a2;
    r->w268 = a3;
    r->w2B0 = 0;
    r->w2B4 = 0;
    r->c7 = 0;
    func_004A2558(r);
    func_004A2BC8(r);
    return func_004A2D20(0, 0, a2, a3);
}
