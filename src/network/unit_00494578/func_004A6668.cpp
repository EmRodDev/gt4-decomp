/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct S {
    char pad0[7]; unsigned char mode;
    char pad1[0x26c-8]; unsigned short x, y;
    char pad2[0x288-0x270]; int ox, oy;
};
extern "C" void func_004A6538(S *, int, int, int, int, int, int, int, int) throw();
static inline void draw(S *s, float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1) {
    int dy = s->mode ? 8 : 16;
    float scale = (float)dy;
    float ox = (float)(s->ox * 16);
    float oy = (float)(s->oy * 16);
    x0 *= 16.0f;
    float bx = (float)s->x;
    float by = (float)s->y;
    bx += ox;
    by += oy;
    x1 *= 16.0f;
    y0 *= scale;
    y1 *= scale;
    u0 *= 16.0f;
    v0 *= 16.0f;
    u1 *= 16.0f;
    v1 *= 16.0f;
    float ax = bx + x0;
    float ay = by + y1;
    bx = bx + x1;
    by = by + y0;
    ax += 0.5f; bx += 0.5f; by += 0.5f; ay += 0.5f;
    u0 += 0.5f; v0 += 0.5f; u1 += 0.5f; v1 += 0.5f;
    int iy0 = (int)by;
    int ix0 = (int)ax;
    int ix1 = (int)bx;
    int iy1 = (int)ay;
    int iu0 = (int)u0;
    int iv0 = (int)v0;
    int iu1 = (int)u1;
    int iv1 = (int)v1;
    func_004A6538(s, ix0, iy0, ix1, iy1, iu0, iv0, iu1, iv1);
}
extern "C" void func_004A6668(float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1) {
    draw((S *)spr_base(), x0, y0, x1, y1, u0, v0, u1, v1);
}
