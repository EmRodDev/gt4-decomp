#include "types.h"

struct RaceMachineTestLayout {
    char pad[0x6C];
    s32 unk6C;
    char pad70[0xF140 - 0x70];
    char car_icon_maker[0x100];
};

extern "C" void RaceBase__postInitialize(void *arg0);
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceMachineTest__postInitialize(RaceMachineTestLayout *arg0) {
    RaceBase__postInitialize(arg0);
    CarIconMaker__structor_1(arg0->car_icon_maker, arg0->unk6C);
}
