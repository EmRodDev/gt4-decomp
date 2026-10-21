/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Renders vignetting / aperture ring gradient in race photo mode.
 * Calculates lens radius and outer falloff intensity and dispatches
 * the vignette disc primitive to the render pipeline.
 */
#include "types.h"

extern "C" void func_003BBBC0(void *renderContext, u32 innerColor, u32 outerColor, f32 innerRadius, f32 outerRadius);
extern "C" s32 func_004AA0D0(void *photoCtx, void *renderContext, f32 posX, f32 posY, f32 posZ, f32 radiusFactor, f32 maxAlpha);

extern "C" void func_003C7CD8(void *photoContext, void *renderContext) {
    f32 radiusFactor;

    radiusFactor = *(f32 *)((char *)photoContext + 0x1E66C) * 0x1.666666p-1f * 0x1.47AE14p-7f;
    func_003BBBC0(renderContext, (u32)func_004AA0D0(photoContext, renderContext, 0.0f, 0.0f, 0.0f, radiusFactor, 255.0f), 0, 420.0f, 200.0f);
}
