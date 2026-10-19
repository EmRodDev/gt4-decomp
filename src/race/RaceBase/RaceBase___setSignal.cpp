#include "types.h"

struct RaceBaseLayout {
    char pad0[0xCE4];
    char unkCE4[0x34];
    s32 unkD18;
};

extern "C" void func_00574F90(void *arg0);
extern "C" void GranTurismo4__GameObjectPS2__terminate(void *arg0);

extern "C" void RaceBase___setSignal(RaceBaseLayout *arg0, s32 arg1) {
    arg0->unkD18 = arg1;
    func_00574F90(arg0->unkCE4);
    GranTurismo4__GameObjectPS2__terminate(arg0);
}
