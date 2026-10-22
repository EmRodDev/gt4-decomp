/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Measures whether carB is ahead of carA on the course and by how much (inferred from the signs and the lap wrap).
 * Distances along the course are the floats at +0x104+0x4A4 of each car; if carA is in the last quarter of the
 * course length (DynamicsConductor__GetCourseLength of carA's owner) and carB in the first quarter, carB's
 * distance gets the course length added (a lap wrap). The gap is that difference minus carB's float at +4 and
 * carA's float at +0 of their data blocks (probably the car extents; names unknown). A gap that is zero or less
 * returns 0. When the gap is under 20.0, the last argument p must lie within half the sum of both cars' float at
 * +8 (a width), otherwise 0. On success outGap gets the gap, outSide the negated difference of the floats at
 * +0x650, and 1 is returned. The unused float parameter is part of the signature. */
struct Dat { float f0, f4, f8; };
struct Inner { char p[0x4A4]; float f4a4; char q[0x650 - 0x4A8]; float f650; };
struct Obj { char p[4]; Obj *f4; char q[8]; Dat *d; char r[0x104 - 0x14]; Inner s; };
extern "C" float DynamicsConductor__GetCourseLength(Obj *);

extern "C" int func_003F42D0(Obj *carA, Obj *carB, float *outGap, float *outSide, float unused, float p)
{
    Inner *s1 = &carA->s;
    Inner *s0 = &carB->s;
    Dat *da = carA->d;
    float f21 = da->f0;
    Dat *db = carB->d;
    float f20 = db->f4;
    float f24 = db->f8;
    float f23 = da->f8;
    *(int *)outGap = 0;
    *(int *)outSide = 0;
    float courseLength = DynamicsConductor__GetCourseLength(carA->f4);
    int r = 0;
    float distA = s1->f4a4;
    float distB = s0->f4a4;
    float ahead;
    if (courseLength * 0.75f < distA && distB < courseLength * 0.25f)
        ahead = (distB + courseLength) - distA;
    else
        ahead = distB - distA;
    float d = (ahead - f20) - f21;
    if (d <= 0.0f) return r;
    float sideDelta = s0->f650 - s1->f650;
    if (d < 20.0f) {
        float halfWidth = (f23 + f24) * 0.5f;
        if (halfWidth < p)
            return 0;
        if (p < -halfWidth)
            return 0;
    }
    *outGap = d;
    r = 1;
    *outSide = -sideDelta;
    return r;
}
