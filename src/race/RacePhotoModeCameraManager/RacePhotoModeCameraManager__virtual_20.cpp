/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets the photo-mode camera manager (virtual slot 20): runs DevelopCamera::virtual_20, initialises the three embedded blocks
 * (+0x9C0, +0xC80, CameraControl at +0xDD0 with 0 and 1), calls virtual +0x58 on both camera objects (+0xC40, +0xC44), makes the first one
 * the active camera (field +0x13C; the name is inferred from the assignment), runs 0036FAE8 on the block at +0xE28 and clears +0xF30 / +0xF34.
 * When a source object is given, its int at +0x80 goes to the virtuals +0x140 (first camera) and +0x138 (second camera), to 0036FAE8, and
 * the source feeds 003FBAB0 on the block at +0xD00. What the source object is is purpose unknown. */
typedef int s32;
typedef short s16;

struct Obj;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct Obj { VEntry *vt; };
struct VT { char data[1]; };

struct Info8 { char pad[8]; s32 *p8; };
struct Info { char pad60[0x60]; Info8 *p60; };
struct Other { char pad[0x80]; s32 i80; };

struct Cam {
    char *vt;
    char pad4[0x138];
    Obj *activeCamera;
    char pad140[0x9C0 - 0x140];
    char b9C0[0xC40 - 0x9C0];
    Obj *firstCamera;
    Obj *secondCamera;
    char padC48[0xC80 - 0xC48];
    char bC80[0xD00 - 0xC80];
    char bD00[0xDD0 - 0xD00];
    char bDD0[0xE28 - 0xDD0];
    char bE28[0xF30 - 0xE28];
    s32 iF30;
    s32 iF34;
};

extern "C" void DevelopCamera__virtual_20(Cam *) throw();
extern "C" void func_003FB430(void *);
extern "C" void CameraSys__CameraControl__init(void *, s32, s32);
extern "C" void func_0036FAE8(void *, s32, s32) throw();
extern "C" void func_003FBAB0(void *, void *, s32, s32);

extern "C" void RacePhotoModeCameraManager__virtual_20(Cam *self, Other *source) {
    char *blockE28 = self->bE28;
    DevelopCamera__virtual_20(self);
    func_003FB430(self->b9C0);
    Obj *firstCamera = self->firstCamera;
    VEntry *firstEntry = (VEntry *)((char *)firstCamera->vt + 0x58);
    ((void (*)(void *))firstEntry->fn)((char *)firstCamera + firstEntry->delta);
    Obj *secondCamera = self->secondCamera;
    VEntry *secondEntry = (VEntry *)((char *)secondCamera->vt + 0x58);
    ((void (*)(void *))secondEntry->fn)((char *)secondCamera + secondEntry->delta);
    self->activeCamera = self->firstCamera;
    func_003FB430(self->bC80);
    CameraSys__CameraControl__init(self->bDD0, 0, 1);
    func_0036FAE8(blockE28, 0, 0);
    self->iF30 = 0;
    self->iF34 = 0;
    if (source != 0) {
        Obj *cameraA = self->firstCamera;
        s32 sourceValue80 = source->i80;
        VEntry *e3 = (VEntry *)((char *)cameraA->vt + 0x140);
        e3->fn((char *)cameraA + e3->delta, sourceValue80);
        Obj *cameraB = self->secondCamera;
        VEntry *e4 = (VEntry *)((char *)cameraB->vt + 0x138);
        e4->fn((char *)cameraB + e4->delta, sourceValue80);
        func_0036FAE8(blockE28, sourceValue80, *((Info *)source)->p60->p8);
        func_003FBAB0(self->bD00, source, 0, 0);
    }
}
