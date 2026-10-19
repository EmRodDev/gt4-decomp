/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct RaceSpecHolder {
    char pad[0x70];
    s32 race_label;
};

struct RaceLicenseLayout {
    char pad0[0x6C];
    RaceSpecHolder *spec_holder;
    char pad70[0xD68 - 0x70];
    s32 unkD68;
};

extern "C" s32 RaceBase__getLicenseSubNumber(s32);
extern "C" s32 RaceBase__getLicenseSubMode(s32);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(s32);

extern "C" s32 RaceLicense__getRaceMode(RaceLicenseLayout *arg0, s32 *arg1) {
    s32 *mode = &arg0->unkD68;
    s32 label;
    s32 subMode;
    s32 modeVal;
    *arg1 = -1;
    modeVal = *mode;
    if ((modeVal ^ 3) == 0) {
        label = SPEC_DATABASE__RaceSpec__getRaceLabel(arg0->spec_holder->race_label);
        subMode = RaceBase__getLicenseSubMode(label);
        if (subMode == 0) {
            return *mode;
        }
        *arg1 = RaceBase__getLicenseSubNumber(label);
        modeVal = subMode;
        return modeVal;
    }
    return modeVal;
}
