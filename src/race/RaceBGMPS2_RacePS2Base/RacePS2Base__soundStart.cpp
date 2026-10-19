#include "types.h"

struct RacePS2BaseLayout {
    char pad0[0x3628];
    char pitmen[0x3C];
    char pad3664[0xE170 - 0x3628 - 0x3C];
    s32 course_sound;
};

extern "C" void RaceBase__soundStart(void *arg0);
extern "C" void RaceCourseSound__playStart(s32 *arg0);
extern "C" void Pitmen__playSound(void *arg0);

extern "C" void RacePS2Base__soundStart(RacePS2BaseLayout *arg0) {
    RaceBase__soundStart(arg0);
    RaceCourseSound__playStart(&arg0->course_sound);
    Pitmen__playSound(arg0->pitmen);
}
