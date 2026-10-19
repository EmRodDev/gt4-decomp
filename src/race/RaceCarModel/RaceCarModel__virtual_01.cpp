#include "types.h"

extern "C" s32 func_00450AD0(void *);
extern "C" void func_003EDA10(s32);
extern "C" void func_003EDA90(s32);
extern "C" void func_0044F4B0(void);
extern "C" void free(s32);
extern "C" void HumanModel__virtual_03(void *);

struct RaceCarModelLayout {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    char car_model[0x5C8];
    char driver_model[0x840];
    char crew_model[0x840];
    char pad1660[0x10];
    s32 unk1670;
    s32 unk1674;
};

extern "C" void RaceCarModel__virtual_01(RaceCarModelLayout *arg0) {
    func_003EDA10(func_00450AD0(arg0->car_model));
    if (arg0->unk10 != 0) {
        func_003EDA90(arg0->unk10);
        arg0->unk10 = 0;
    }
    if (arg0->unkC != 0) {
        func_0044F4B0();
        func_003EDA90(arg0->unkC);
        arg0->unkC = 0;
    }
    if (arg0->unk14 != 0) {
        free(arg0->unk14);
        arg0->unk14 = 0;
    }
    arg0->unk1670 = 0;
    arg0->unk1674 = 0;
    HumanModel__virtual_03(arg0->driver_model);
    HumanModel__virtual_03(arg0->crew_model);
}
