#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void RaceDisplayObjectBase__structor_1(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RacePriusPanel__vtable[];
extern char RacePanel__vtable[];
extern char RacePriusHybridDisplay__vtable[];
extern char RaceValueDisplayBase__vtable[];
extern char RaceDigitalSpeedmeter__vtable[];
struct func_005FA350_temp_a0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_005FA350_temp_v0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_005FA350_temp_a0_2 {
    char pad0[0x14];
    s32 unk14;
};
struct func_005FA350_temp_v1 {
    char pad0[0x14];
    s32 unk14;
};

struct func_005FA350_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void RaceDigitalSpeedmeter__structor_5(void *arg0, s32 arg1) {
    struct func_005FA350_temp_a0 *temp_a0;
    struct func_005FA350_temp_a0_2 *temp_a0_2;
    struct func_005FA350_temp_v0 *temp_v0;
    struct func_005FA350_temp_v1 *temp_v1;

    temp_a0 = arg0 + 0x150;
    ((struct func_005FA350_arg0 *)arg0)->unk14 = (s32)RacePriusPanel__vtable;
    temp_a0->unk14 = (s32)RacePriusHybridDisplay__vtable;
    RaceDisplayObjectBase__structor_1(temp_a0, 0);
    temp_v0 = arg0 + 0xE0;
    temp_v0->unk14 = (s32)RaceValueDisplayBase__vtable;
    RaceDisplayObjectBase__structor_1(temp_v0, 0);
    temp_a0_2 = arg0 + 0x74;
    temp_a0_2->unk14 = (s32)RaceValueDisplayBase__vtable;
    RaceDisplayObjectBase__structor_1(temp_a0_2, 0);
    temp_v1 = arg0 + 0x3C;
    temp_v1->unk14 = (s32)RaceDigitalSpeedmeter__vtable;
    RaceDisplayObjectBase__structor_1(temp_v1, 0);
    ((struct func_005FA350_arg0 *)arg0)->unk14 = (s32)RacePanel__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
