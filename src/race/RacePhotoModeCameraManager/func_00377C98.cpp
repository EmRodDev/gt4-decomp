/* Constructor of the photo-mode camera manager (class from the source directory): runs the base constructor, installs vtable
 * D_0067A250, constructs the embedded member at +0xE28, allocates two helper objects (0x200 and 0x1C0 bytes, stored at
 * +0xC40 and +0xC44) and finishes with virtual slot 20 called with 0. */
#include "types.h"

extern char D_0067A250[];

extern "C" s32 func_0036FA88(void *);
extern "C" void *func_003721D8(void *);
extern "C" s32 RacePhotoModeCameraManager__virtual_20(void *, s32);
extern "C" void func_00384358(void *);
extern "C" void func_00384510(void *);
extern "C" s32 exception__structor_0(s32);

static inline s32 make_camera() {
    s32 p = exception__structor_0(0x200);
    func_00384358((void *)p);
    return p;
}
static inline s32 make_other() {
    s32 p = exception__structor_0(0x1C0);
    func_00384510((void *)p);
    return p;
}
extern "C" s32 func_00377C98(void *self) {
    char *cameraSlot = (char *)self + 0xC40;
    s32 created;
    func_003721D8(self);
    *(char **)self = D_0067A250;
    func_0036FA88((char *)self + 0xE28);
    created = make_camera();
    *(s32 *)cameraSlot = created;
    created = make_other();
    *(s32 *)((char *)self + 0xC44) = created;
    return RacePhotoModeCameraManager__virtual_20(self, 0);
}
