/* Constructor of RaceBGMPS2: runs the RaceBGMBase constructor, installs the RaceBGMPS2 vtable, resets the two BGMPlayList blocks at +0x1C8 and
 * +0x9D8 to their default (0), stores three callback pointers at +0x08, +0x10 and +0x0C (0033D920, 0033D928, 004601A8), clears +0x14, +0x30
 * and +0x34, initialises the block at +0x18, and finally calls 0033D110 and RaceBGMPS2::setVolumeRate with 1.0 (full volume, inferred from the
 * setter's name). What the three callbacks do is purpose unknown. */
#include "types.h"

struct Obj {
    char pad0[4];
    void *vt;
    void *f8;
    void *fC;
    void *f10;
    s32 f14;
    char pad18[0x18];
    s32 f30;
    s32 f34;
};

extern char RaceBGMPS2__vtable[];
extern "C" void func_0033D920(void);
extern "C" void func_0033D928(void);
extern "C" void func_004601A8(void);
extern "C" void func_0033D110(void *, float);
extern "C" void RaceBGMPS2__setVolumeRate(void *, float);
extern "C" s32 RaceBGMBase__structor_0(void *);
extern "C" void GranTurismo4__BGMPlayList__setDefault(void *, s32);
extern "C" void func_00460368(void *);

extern "C" void RaceBGMPS2__structor_0(Obj *self) {
    RaceBGMBase__structor_0(self);
    self->vt = RaceBGMPS2__vtable;
    GranTurismo4__BGMPlayList__setDefault((char *)self + 0x1C8, 0);
    GranTurismo4__BGMPlayList__setDefault((char *)self + 0x9D8, 0);
    self->f8 = (void *)func_0033D920;
    self->f10 = (void *)func_0033D928;
    self->fC = (void *)func_004601A8;
    self->f14 = 0;
    func_00460368((char *)self + 0x18);
    self->f30 = 0;
    self->f34 = 0;
    float fullVolume = 1.0f;
    func_0033D110(self, fullVolume);
    return RaceBGMPS2__setVolumeRate(self, fullVolume);
}
