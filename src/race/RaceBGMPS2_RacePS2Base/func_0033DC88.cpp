/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Binds texture buffer to the race scene post-process rendering stage.
 * Fetches GS texture descriptor from graphics buffer and passes display
 * texture parameters to the low-level rendering context.
 */
#include "types.h"

extern "C" s32 func_003D2998(void *renderTarget);
extern "C" void GSBuffer__getTexture(void *graphicsBuffer, void *outputTexDesc);
extern "C" void func_003D2710(void *renderTarget, void *texDescriptor);
extern "C" void func_003D25B0(void *renderTarget, s32 renderMode, s32 textureSlot, s32 contextParam);

struct RaceSceneContext {
    char headerPadding[0x6C];
    s32 pipelineConfig;
    s32 textureSlot;
};

extern "C" void func_0033DC88(s32 *sceneObject, void *graphicsBuffer, s32 renderMode) {
    s32 texDescBuffer0[4];
    s32 texDescBuffer1[4];
    s32 texDescBuffer2[4];
    char *renderTarget = (char *)sceneObject + 0x3628;
    if (func_003D2998(renderTarget) != 0) {
        GSBuffer__getTexture(graphicsBuffer, texDescBuffer0);
        func_003D2710(renderTarget, texDescBuffer0);
        RaceSceneContext *sceneCtx = (RaceSceneContext *)sceneObject;
        func_003D25B0(renderTarget, renderMode, sceneCtx->textureSlot, *(s32 *)((char *)(*(s32 *)((char *)(*(s32 *)((char *)(sceneCtx->pipelineConfig) + 0x80)) + 0x4)) + 0x80));
    }
}
