/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Updates dynamic motion blur / camera post-processing in race background music/scene context.
 * Checks viewport activity and camera distance, prepares frame buffer surfaces,
 * and sets decay blending factor with maximum clamp.
 */
typedef int s32;
typedef short s16;

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct VTableEntry {
    s16 thisDelta;
    s16 vtableIndex;
    void *functionPtr;
};

struct BufferEntry { char padding[4]; s32 bufferStatus; char entryPadding[0x3C - 8]; };
struct DoubleBufferContext { BufferEntry buffers[2]; s32 bufferPadding; };
struct GlobalGraphicsContext { char contextPadding[0x134]; s32 baseVramAddress; };
extern char D_0061850C[];

extern "C" void func_00105728(void *bufferPtr);
extern "C" s32 func_004A7C60(void);
extern "C" void func_004A9378(s32 buffer0, s32 buffer1, s32 buffer2, s32 width, s32 height);

typedef s32 (*CameraCheckFn)(char *cameraObject);

extern "C" void func_003429E0(char *raceBaseContext) {
    if (*(unsigned char *)(raceBaseContext + 0xCF58) != 0) {
        VTableEntry *cameraSlot = (VTableEntry *)(*(char **)(raceBaseContext + 0x64) + 0x428);
        if (((CameraCheckFn)cameraSlot->functionPtr)(raceBaseContext + cameraSlot->thisDelta) != 0 && *(float *)(raceBaseContext + 0xCF40) != 0.0f) {
            char *globalBase = D_0061850C;
            char *activeBuffer = globalBase + (1 - *(s32 *)(globalBase + 0x78)) * 0x3C;
            if (*(s32 *)(activeBuffer + 4) == 1) {
                s32 vramBase = *(s32 *)(globalBase + 0x134);
                s32 vramOffset1 = vramBase + 0x23000;
                s32 vramOffset2 = vramBase + 0x46000;
                func_00105728(activeBuffer);
                func_004A9378(vramBase, vramOffset1, vramOffset2, 0x280, 0xE0);
                *(unsigned char *)(raceBaseContext + 0xCF59) = func_004A7C60();
                *(float *)(raceBaseContext + 0xCF3C) = maxf(1.0f - 0x1.111110p-6f / *(float *)(raceBaseContext + 0xCF40), 0.0f);
            }
        }
    }
}
