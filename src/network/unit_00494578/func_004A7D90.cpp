/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
#define MAXS(d, a, b) __asm__("max.s %0, %1, %2" : "=f"(d) : "f"(a), "f"(b))
#define MINS(d, a, b) __asm__("min.s %0, %1, %2" : "=f"(d) : "f"(a), "f"(b))
static inline float minf(float a, float b) { float r; MINS(r, a, b); return r; }
static inline float maxf(float a, float b) { float r; MAXS(r, a, b); return r; }
extern "C" int func_004AA558(int);
extern "C" void func_004A8CB8(int, float, float, float, float, float, float);
extern "C" void func_004A8F78(int);
extern "C" void func_004A81A8(int, int, int, int, int, int, long, int, int, int);
extern "C" int func_004AA6B8(int);
struct Buf { unsigned short fbp; unsigned char psm; unsigned char pad; int w; int h; };
struct Spr { char p0[0x170]; unsigned short a; unsigned char b; char p173[0x1C0 - 0x173]; long c; char p1c8[0x260 - 0x1C8]; Buf buf; };
extern "C" int func_004A7D90(float a, float b, float c, float d, float e, float x, float f)
{
    int buf = func_004AA558(0x1000);
    int p = buf + 0x800;
    int q = buf + 0x900;
    func_004A8CB8(p, a, b, c, d, e, f);
    func_004A8F78(q);
    MAXS(x, x, -1.0f);
    MINS(x, x, 1.0f);
    x *= 128.0f;
    float y = maxf(128.0f - x, 0.0f);
    float r = y * 0x1.2e147ap-1f;
    float g = y * 0x1.333332p-2f;
    float bl = y * 0x1.c28f5cp-4f;
    int ig = (int)minf(g, 255.0f);
    int ib = (int)minf(bl, 255.0f);
    int ir = (int)minf(r, 255.0f);
    int xr = (int)minf(maxf(x + r, 0.0f), 255.0f);
    int xg = (int)minf(maxf(x + g, 0.0f), 255.0f);
    int xb = (int)minf(maxf(x + bl, 0.0f), 255.0f);
    Spr *s = (Spr *)spr_base();
    Buf *fb = &s->buf;
    func_004A81A8((int)(s->c & 0x3fff) << 6, s->a << 11, s->b, buf, p, q,
                  ((long)fb->h - 1) << 48 | ((long)fb->w - 1) << 16,
                  xg | (ig << 8) | (ig << 16), ir | (xr << 8) | (ir << 16), ib | (ib << 8) | (xb << 16));
    return func_004AA6B8(buf);
}
