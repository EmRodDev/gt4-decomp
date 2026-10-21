/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Ground probe: asks the scene for the surface under (x, y, z) (func_00395910, which returns a plane and its id), then queries the hit
 * record (func_00395760). Returns 0 when the hit is flagged as invalid; otherwise stores the plane, its id, the hit's value at
 * +0x10 and the height at which the plane passes through (x, z), solved from nx*x + ny*y + nz*z + d = 0, and returns 1. */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Hit {
    f32 x, y, z;
    s32 id;
    f32 f10;
    char pad14[0x30 - 0x14];
    u8 flag;
};

struct Plane {
    f32 nx, ny, nz, d;
};

struct Out {
    f32 t;
    f32 u;
    Plane pl;
    s32 id;
};

extern "C" void func_00395760(s32, Hit *);
extern "C" void func_00395910(s32, f32 *, s32 *, Plane *);

extern "C" s32 func_00409A48(s32 scene, Hit *hit, Out *out, f32 x, f32 y, f32 z) {
    s32 planeId;
    f32 probePos[3];
    Plane *pl = (Plane *)((char *)out + 8);
    f32 t;
    probePos[0] = x;
    probePos[1] = y;
    probePos[2] = z;
    planeId = 0;
    func_00395910(scene, probePos, &planeId, pl);
    hit->id = planeId;
    hit->x = probePos[0];
    hit->y = probePos[1];
    t = 0.0f;
    hit->z = probePos[2];
    func_00395760(scene, hit);
    if (hit->flag != 0) {
        return 0;
    }
    if (pl->ny != 0.0f) {
        t = -(pl->nx * probePos[0] + pl->nz * probePos[2] + pl->d) / pl->ny;
    }
    out->t = t;
    out->id = planeId;
    out->u = hit->f10;
    return 1;
}
