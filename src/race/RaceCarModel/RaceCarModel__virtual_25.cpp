#include "types.h"

struct Obj {
    s32 unk0;
    char pad4[0x14];
    char car_model[0x5C8];
};

extern "C" void func_00451EE0(void *arg0, s32 arg1, s32 arg2);

extern "C" void RaceCarModel__virtual_25(Obj *arg0, s32 arg1) {
    func_00451EE0(arg0->car_model, arg0->unk0, arg1);
}
