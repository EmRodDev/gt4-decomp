typedef int s32;

struct RaceLicenseLayout {
    char pad0[0x24E5C];
    s32 license_concourse;
};

extern "C" s32 LicenseConcourse__isCameraPeriod(s32 *arg0);

extern "C" s32 RaceLicense__isInterruptMotionCameraPeriod(RaceLicenseLayout *arg0, s32 arg1) {
    s32 result = 0;

    if (arg1 == 0) {
        result = LicenseConcourse__isCameraPeriod(&arg0->license_concourse) != 0;
    }
    return result;
}
