/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds an orientation basis from three angles (pitch, roll, yaw; order inferred from func_0035D350 passing body pitch, roll and
 * heading): a0 receives the forward axis (z = sin pitch), a1 the right axis and a2 the up axis (z = cos pitch * cos roll), in a
 * z-up frame. Plain sine/cosine products; the temporaries are named after the factors they hold. */
typedef float f32;
struct Vec3 { f32 x, y, z; };

extern "C" f32 func_0057D1F0(f32);
extern "C" f32 func_0057D2B8(f32) throw();

extern "C" void func_0036C9F8(Vec3 *forwardAxis, Vec3 *rightAxis, Vec3 *upAxis, f32 pitch, f32 roll, f32 yaw) {
    f32 sinPitch = func_0057D2B8(pitch);
    f32 cosPitch = func_0057D1F0(pitch);
    f32 sinRoll = func_0057D2B8(roll);
    f32 cosRoll = func_0057D1F0(roll);
    f32 sinYaw = func_0057D2B8(yaw);
    f32 cosYaw = func_0057D1F0(yaw);
    f32 sinYawSinPitch, cosYawSinPitch, rightX, rightY, upX, cosYawSinPitchCosRoll, cosYawCosPitch;
    cosYawSinPitch = cosYaw * sinPitch;
    sinYawSinPitch = sinYaw * sinPitch;
    cosYawCosPitch = cosYaw * cosPitch;
    rightX = (cosYaw * cosRoll) - (sinYawSinPitch * sinRoll);
    rightY = (sinYaw * cosRoll) + (cosYawSinPitch * sinRoll);
    cosYawSinPitchCosRoll = cosYawSinPitch * cosRoll;
    upX = (cosYaw * sinRoll) + (sinYawSinPitch * cosRoll);
    rightAxis->z = -cosPitch * sinRoll;
    rightAxis->x = rightX;
    rightAxis->y = rightY;
    forwardAxis->z = sinPitch;
    forwardAxis->x = -sinYaw * cosPitch;
    forwardAxis->y = cosYawCosPitch;
    upAxis->z = cosPitch * cosRoll;
    upAxis->y = (sinYaw * sinRoll) - cosYawSinPitchCosRoll;
    upAxis->x = upX;
}
