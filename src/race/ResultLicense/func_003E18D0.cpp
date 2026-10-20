/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Configures the 3D camera and award presentation transforms for ResultLicense.
 * Sets position, orientation, and angle offsets depending on license test result mode
 * (pass, silver, gold, failure) and updates the award trophy icon index.
 */
typedef int s32;
typedef short s16;
typedef unsigned short u16;

struct Vector3 { float x, y, z; };
struct AwardBadge { char badgePadding[0x18]; s16 iconIndex; };
struct LicenseRecord { char recordPadding[0x1A]; u16 timeRank; char middlePadding[0x60]; AwardBadge *badgePtr; };
struct LicenseResultObject {
    char objectPadding[0x570]; s32 testType; char typePadding[4]; LicenseRecord *recordPtr;
};

extern char D_006A38F0[];
extern "C" void func_003E2088(void *targetNode);
extern "C" void func_00454B90(void *recordPtr, s32 state);

#define GET_FIELD_FLOAT(offset) (*(float *)((char *)self + (offset)))

extern "C" void func_003E18D0(LicenseResultObject *self, s32 mode) {
    *(s32 *)((char *)self + 0x57C) = 1;
    char *nodePtr = (char *)self;
    for (s32 i = 0; i < 3; i++) {
        func_003E2088(nodePtr + 0x584);
        func_003E2088(nodePtr + 0x5B4);
        func_003E2088(nodePtr + 0x5E4);
        nodePtr += 0x10;
    }
    Vector3 *cameraPos = (Vector3 *)((char *)self + 0x5A4);
    Vector3 *targetPos = (Vector3 *)((char *)self + 0x5F4);
    Vector3 *scaleVec = (Vector3 *)((char *)self + 0x614);
    cameraPos->x = -0.5f;
    cameraPos->y = -2.5f;
    cameraPos->z = 0.5f;
    targetPos->z = 0.5f;
    float zeroVal = 0.0f;
    targetPos->x = zeroVal;
    targetPos->y = 60.0f;
    scaleVec->y = 1.0f;
    scaleVec->x = zeroVal;
    scaleVec->z = 1.0f;
    switch (mode) {
    case 1:
    case 2:
        GET_FIELD_FLOAT(0x5C4) = -22.5f;
        cameraPos->z = 0.35f;
        break;
    case 3:
        GET_FIELD_FLOAT(0x5C4) = 180.0f;
        targetPos->x = 1000.0f;
        targetPos->y = 60.0f;
        targetPos->z = 0x1.333332p+0f;
        break;
    default: {
        Vector3 *orientVec = (Vector3 *)((char *)self + 0x5B4);
        GET_FIELD_FLOAT(0x5C4) = 270.0f;
        orientVec->x = -180.0f;
        orientVec->y = 0;
        orientVec->z = 1.5f;
        targetPos->z = 3.0f;
        break;
    }
    }
    if (self->recordPtr) {
        func_00454B90(self->recordPtr, -1);
        LicenseRecord *activeRecord = self->recordPtr;
        s32 currentRank = activeRecord->timeRank;
        s32 thresholdVal = D_006A38F0[self->testType];
        if (currentRank < thresholdVal) thresholdVal = currentRank;
        activeRecord->badgePtr->iconIndex = thresholdVal;
    }
}
