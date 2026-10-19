#include "gt4/RaceSinglePlayerInformation.h"
#include "gt4/RaceEntryCar.h"
typedef int s32;

struct EntryCarObj {
    char pad[0x14];
    s32 unk14;
};

extern "C" void RaceEntryCar__setPlayerSpec(struct RaceEntryCar *arg0, const void *arg1);

extern "C" void RaceSinglePlayerInformation__updateEntryCar(struct RaceSinglePlayerInformation *arg0, struct EntryCarObj *arg1) {
    if (arg1->unk14 == 0) {
        RaceEntryCar__setPlayerSpec((struct RaceEntryCar *)arg1, arg0->unk130);
    }
}
