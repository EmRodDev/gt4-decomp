/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Updates camera position and perspective projection for photo mode.
 * Resolves camera view matrix via vtable dispatch (slot 0x1F0 and 0x78)
 * and emits transformed camera viewpoint parameters.
 */
typedef int s32;
typedef short s16;
typedef float float32;

struct VTableSlot { s16 thisDelta; s16 vtableIndex; void *functionPtr; };

extern "C" int func_003FD3D8(s32 viewId, void *matrixBuffer, void *cameraTarget, float32 fovValue, float32 aspectVal, float32 nearDist, float32 farDist);

extern "C" void func_003784B8(void *cameraManager, float32 fovValue, float32 aspectVal, float32 nearDist, float32 farDist) {
    char matrixBuffer[0x40];
    void *cameraObject;
    s32 viewId;
    struct VTableSlot *cameraSlot = (struct VTableSlot *)(*(char **)cameraManager + 0x1F0);
    cameraObject = ((void *(*)(void *))cameraSlot->functionPtr)((char *)cameraManager + cameraSlot->thisDelta);
    viewId = *(s32 *)((char *)cameraManager + 0xE2C);
    struct VTableSlot *transformSlot = (struct VTableSlot *)(*(char **)cameraObject + 0x78);
    ((void (*)(void *, void *, void *))transformSlot->functionPtr)((char *)cameraObject + transformSlot->thisDelta, matrixBuffer, (char *)cameraManager + 0x9C0);
    func_003FD3D8(viewId, matrixBuffer, (char *)cameraObject + 0x100, fovValue, aspectVal, nearDist, farDist);
}
