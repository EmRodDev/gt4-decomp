/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame update of a license test race. The license display at +0x10368 is hidden (virtual_16 with 0) when the organization's field +0xDC
 * is set. While the flag at +0x24EE0 is set, the display is switched to replay type 2 and, until the handled flag at +0x24EE4 is 1, the
 * code asks the object returned by the virtual at vtable +0xD0 whether it is busy (+0x158): if not, it applies the organization to it
 * (+0xB0) and returns for this frame; if so it runs the two virtual methods at +0x178 and +0x180 and marks the flag handled. Otherwise the base
 * RacePS2Base::updateRace runs, followed by 003BC6E0 with one 1/60 s step. Which replay or result phase the flags stand for is purpose unknown. */
typedef int s32;
typedef short s16;
typedef float f32;

struct Org { char pad[0xDC]; s32 unkDC; };

struct Obj;
struct VEntV { s16 off; s16 pad; void (*fn)(void *); };
struct VEntO { s16 off; s16 pad; Obj *(*fn)(void *, s32); };
struct VEntI { s16 off; s16 pad; s32 (*fn)(void *); };
struct VEntB { s16 off; s16 pad; void (*fn)(void *, void *, s32, s32); };
struct Obj { char *vt; };

struct Self {
    char pad0[0x64];
    char *vtable;
    char pad68[4];
    Org *organization;
    s32 unk70;
    char pad74[0xD44 - 0x74];
    s32 unkD44;
    char padD48[0x24EE0 - 0xD48];
    s32 pendingFlag;
    s32 handledFlag;
};

extern "C" void RacePS2Base__updateRace(void *);
extern "C" void RaceDisplay__virtual_16(void *, s32);
extern "C" void func_003BC6E0(void *, f32);
extern "C" void RaceLicenseDisplay__setDisplayTypeInReplay(void *, s32);

extern "C" void RaceLicense__updateRace(Self *self) {
    char *display = (char *)self + 0x10368;
    if (self->organization->unkDC != 0) {
        RaceDisplay__virtual_16(display, 0);
    }
    if (self->pendingFlag != 0) {
        RaceDisplay__virtual_16(display, self->handledFlag != 0);
        RaceLicenseDisplay__setDisplayTypeInReplay(display, 2);
        if (self->handledFlag == 0) {
            VEntO *getEntry = (VEntO *)(self->vtable + 0xD0);
            Obj *target = getEntry->fn((char *)self + getEntry->off, 0);
            VEntI *queryEntry = (VEntI *)(target->vt + 0x158);
            if (queryEntry->fn((char *)target + queryEntry->off) == 0) {
                VEntB *applyEntry = (VEntB *)(target->vt + 0xB0);
                applyEntry->fn((char *)target + applyEntry->off, self->organization, self->unk70, self->unkD44 == 0);
                return;
            }
            VEntV *firstCall = (VEntV *)(self->vtable + 0x178);
            firstCall->fn((char *)self + firstCall->off);
            VEntV *secondCall = (VEntV *)(self->vtable + 0x180);
            secondCall->fn((char *)self + secondCall->off);
            self->handledFlag = 1;
        }
    }
    RacePS2Base__updateRace(self);
    func_003BC6E0(self, 0x1.111110p-6f);
}
