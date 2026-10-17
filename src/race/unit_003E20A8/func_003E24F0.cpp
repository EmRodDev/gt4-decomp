/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mat44 { float m[4][4]; };
extern "C" void func_0057D8A0(float, float *, float *);

extern "C" void func_003E24F0(Mat44 *r, float x, float y, float z)
{
    float sx, cx, sy, cy, sz, cz;
    float a, b;

    func_0057D8A0(x, &sx, &cx);
    func_0057D8A0(y, &sy, &cy);
    func_0057D8A0(z, &sz, &cz);
    const float cosineZ = cz;
    a = sx * sz;
    b = sx * cosineZ;
    const float cosineY = cy;
    float sysz = sy * sz;
    float aCy = a * cosineY;
    float bCy = b * cy;
    float cycz = cy * cosineZ;
    float cysz = cy * sz;
    a *= sy;
    float sycz = sy * cosineZ;
    b *= sy;
    r->m[1][2] = sysz - bCy;
    r->m[0][0] = cycz - a;
    r->m[0][2] = sycz + aCy;
    r->m[1][0] = cysz + b;
    r->m[1][1] = cx * cosineZ;
    r->m[0][1] = -cx * sz;
    r->m[2][0] = -cx * sy;
    r->m[2][1] = sx;
    r->m[2][2] = cx * cy;
    r->m[0][3] = 0.0f;
    r->m[1][3] = 0.0f;
    r->m[2][3] = 0.0f;
    r->m[3][0] = 0.0f;
    r->m[3][1] = 0.0f;
    r->m[3][2] = 0.0f;
    r->m[3][3] = 1.0f;
}
