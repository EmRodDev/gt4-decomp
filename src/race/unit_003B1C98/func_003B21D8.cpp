/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds a rotation matrix from two angles stored in the object (yaw at +0x10, pitch at +0xC, inferred from the
 * sin/cos pairs and how they are used) and rotates the position of camera cameraIndex (record from func_0038DC00,
 * position floats at +0x58..+0x60, scale at +0x64) into three outputs, each multiplied by the scale. Sin/cos pairs
 * come from func_0057D8A0 (which of a pair is sin is inferred from the matrix layout). The 4x4 float matrix is
 * written at +0x14 with the last row 0,0,0,1 and the flag at +8 is set to 1 (inferred: matrix valid). Entry m[2]
 * is the square of the negated yaw sin, exactly as matched; the real formula there may differ (unconfirmed). */
typedef int s32;

struct Cam {
    char pad0[0x58];
    float posX, posY, posZ, scale;
};

struct Self {
    char pad0[8];
    s32 matrixValid;
    float pitch;
    float yaw;
    float m[16];
};

extern "C" Cam *func_0038DC00(s32);
extern "C" void func_0057D8A0(float *, float *, float);

extern "C" void func_003B21D8(Self *self, s32 cameraIndex, float *outX, float *outY, float *outZ) {
    float pitchSin, pitchCos, yawSin, yawCos;
    Cam *cam = func_0038DC00(cameraIndex);
    float pitchAngle = self->pitch;
    func_0057D8A0(&yawSin, &yawCos, self->yaw);
    float nx = cam->posX;
    nx = -nx;
    float ny = cam->posY;
    float nz = -cam->posZ;
    float t1 = nx * yawCos - ny * yawSin;
    nx *= yawSin;
    nx += ny * yawCos;
    func_0057D8A0(&pitchSin, &pitchCos, pitchAngle);
    float *m = self->m;
    *outX = (t1 + cam->posX) * cam->scale;
    float ns8 = -yawSin;
    float ns0 = -pitchSin;
    float yc = nx * pitchCos;
    nx *= pitchSin;
    float zs = nz * pitchCos;
    ny = yc - nz * pitchSin;
    nz = nx + zs;
    *outY = (ny - cam->posY) * cam->scale;
    *outZ = (nz + cam->posZ) * cam->scale;
    m[0] = yawCos;
    m[4] = yawSin;
    m[8] = 0;
    m[12] = 0;
    m[1] = pitchCos * ns8;
    m[5] = pitchCos * yawCos;
    m[9] = pitchSin;
    m[13] = 0;
    m[2] = ns8 * ns8;
    m[6] = yawCos * ns0;
    m[10] = pitchCos;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    m[15] = 1.0f;
    self->matrixValid = 1;
}
