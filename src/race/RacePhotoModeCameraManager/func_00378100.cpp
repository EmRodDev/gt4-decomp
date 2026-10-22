/**
 * Updates camera target transform in race photo mode.
 * Queries active camera object via vtable dispatch; if inactive, clears the
 * viewpoint buffer; otherwise evaluates target orientation via virtual slot 0x68.
 */
#include "types.h"

extern "C" void func_003FB4C0(void *, s32);

static inline s32 vcall378100(void *o) {
    char *ent = *(char **)o + 0x1E8;
    void *fn = *(void **)(ent + 4);
    return ((s32 (*)(void *))fn)((char *)o + *(s16 *)ent);
}

static inline void vcallB378100(void *o, void *x) {
    char *ent = *(char **)o + 0x68;
    void *fn = *(void **)(ent + 4);
    ((void (*)(void *, void *))fn)((char *)o + *(s16 *)ent, x);
}

extern "C" void func_00378100(void *cameraManager) {
    char *entryPtr;
    void *functionPtr;
    void *cameraObject;
    if (vcall378100(cameraManager) == 0) {
        return func_003FB4C0((char *)cameraManager + 0x9C0, 0);
    }
    entryPtr = *(char **)cameraManager + 0x1E8;
    functionPtr = *(void **)(entryPtr + 4);
    cameraObject = ((void *(*)(void *, s32))functionPtr)((char *)cameraManager + *(s16 *)entryPtr, 0);
    vcallB378100(cameraObject, (char *)cameraManager + 0x9C0);
}
