/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
#include "vu_macros.h"
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Three floats read as one 64-bit and one 32-bit word. */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

/* $vfN.xyz stored to (p) as one 64-bit and one 32-bit word (no 16-byte alignment). */

struct Vec3 {
    f32 x, y, z;
};

struct Camera {
    char pad[0x21B0];
    f32 m21B0;
    char pad21B4[0x21C4 - 0x21B4];
    f32 m21C4;
    char pad21C8[0x21D0 - 0x21C8];
    f32 m21D0;
    f32 m21D4;
};

static inline u128 load_point(Point *p)
{
    u128 v;
    u32 z = p->z;
    u64 xy = p->xy;
    __asm__("pcpyld %0, %1, %2" : "=r"(v) : "0"(z), "r"(xy));
    return v;
}

extern "C" int func_003B7C98(Camera *cam, Vec3 *view, Vec3 *screen, Vec3 *in, f32 radius, f32 near)
{
    u128 v;
    f32 depth, inv, sx, sy;
    f32 ext[2];

    __asm__ volatile("vnop");
    v = load_point((Point *)in);
    __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(v));
    __asm__ volatile("vmulax.xyzw ACC, $vf28, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf29, $vf1y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf30, $vf1z");
    __asm__ volatile("vmaddw.xyzw $vf1, $vf31, $vf0w");
    VU_GET_VEC3(1, view);
    depth = view->z;
    inv = -1.0f / depth;
    if (depth >= 0.0f)
        return 0;
    if (depth < -near)
        return 0;
    sx = (view->x * cam->m21B0 + depth * cam->m21D0) * inv;
    screen->x = sx;
    sy = (view->y * cam->m21C4 + view->z * cam->m21D4) * inv;
    screen->y = sy;
    screen->z = -view->z;
    inv *= radius;
    ext[0] = cam->m21B0 * inv;
    ext[1] = cam->m21C4 * inv;
    if (sx - ext[0] > 1.0f || sx + ext[0] < -1.0f || sy - ext[1] > 1.0f || sy + ext[1] < -1.0f)
        return 0;
    return 1;
}
