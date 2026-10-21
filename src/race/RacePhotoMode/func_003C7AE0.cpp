/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Updates camera perspective projection parameters for photo mode.
 * Evaluates depth buffer samples, queries transformation matrix from car geometry,
 * and sets the target view distance reciprocal.
 */
#include "types.h"

extern "C" void func_004A5178(s32 bufferId, s32 format, s32 sampleX, s32 sampleY, s32 sampleZ, s32 flags, s32 mode, s32 *outputSample);
extern "C" void RaceEntryCar__update(s32 enableState);
extern "C" void func_004A7550(f32 *matrixBuffer);

extern "C" void func_003C7AE0(void *photoModeContext, s32 *sampleCoordList, s32 sampleY, s32 sampleZ) {
    f32 transformMatrix[16];
    f32 normalizedDepth;
    s32 *depthBufferPtr;

    depthBufferPtr = *(s32 **)((char *)photoModeContext + 0x1E658);
    normalizedDepth = 1.0f;
    func_004A5178(sampleCoordList[0], 0x30, sampleCoordList[2], sampleY, sampleZ, 8, 4, depthBufferPtr);
    normalizedDepth = normalizedDepth - ((f32)(*depthBufferPtr & 0xFFFFFF) * 0x1p-23f);
    RaceEntryCar__update(1);
    func_004A7550(transformMatrix);
    RaceEntryCar__update(0);
    *(f32 *)((char *)photoModeContext + 0x1E65C) = transformMatrix[14] / (normalizedDepth + transformMatrix[10]);
}
