/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Processes license test finishing time and rank in ResultLicense.
 * Formats elapsed time string, calculates delta to target gold/silver time,
 * and notifies the license view hierarchy via vtable dispatch.
 */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct VTableEntry { s16 thisDelta; s16 vtableIndex; void *functionPtr; };
struct LicenseInputData { char inputPadding[0x88]; s32 testPassed; u32 elapsedTime; };
struct LicenseResultView {
    char headerPadding[0xC]; char *vtablePtr;
    char bufferPadding[0x544 - 0x10]; char signChar;
    char deltaString[0x570 - 0x545]; s32 resultRank; s32 isInitialized;
};

extern "C" void func_00391DC8(float fadeAlpha);
extern "C" void func_003B76F0(void *soundCtx, s32 soundId, s32 volume, void *userData);
extern "C" s32 RaceOrganization__getLicenseRank(void *raceData, s32 rankType);
extern "C" void func_003E1FB0(LicenseResultView *resultView, void *licenseData);
extern "C" void GranTurismo4__GetTimeString(u32 timeValue, void *outputBuffer, u32 bufferSize);

extern "C" void func_003E1EA0(LicenseResultView *self, LicenseInputData *licenseInput) {
    s32 *timeData = (s32 *)((char *)licenseInput + 0x88);
    if (self->isInitialized == 0) {
        func_00391DC8(1.0f);
        func_003B76F0(((char *)licenseInput + 0xF4), 0x18, 0x18, 0);
        self->resultRank = timeData[0];
        self->isInitialized = 1;
        GranTurismo4__GetTimeString(timeData[1], (char *)self + 0x6C, 0x20);
        if (timeData[1] != 0x157529FF) {
            self->signChar = 0x2B;
            GranTurismo4__GetTimeString(timeData[1] - RaceOrganization__getLicenseRank(licenseInput, 3), (char *)self + 0x545, 0x1F);
        }
        VTableEntry *vtEntry = (VTableEntry *)(self->vtablePtr + 0x38);
        ((void (*)(void *, void *))vtEntry->functionPtr)((char *)self + vtEntry->thisDelta, licenseInput);
        func_003B76F0(((char *)licenseInput + 0xF4), 0x16, 0, 0);
        if (timeData[0] != 0) func_003E1FB0(self, licenseInput);
    }
}
