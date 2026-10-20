#include "types.h"

struct RaceEntryCarLayout {
    char pad[0x28FC];
    s32 unk28FC;
    char car_sound[0x40];
};

extern "C" void RaceCarSound__playStop(void *arg0, s32 arg1);

extern "C" void RaceEntryCar__flushSound(RaceEntryCarLayout *arg0) {
    RaceCarSound__playStop(arg0->car_sound, 0);
    arg0->unk28FC = 0;
}
