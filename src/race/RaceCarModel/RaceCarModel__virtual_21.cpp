typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[0x14];
    char car_model[0x5C8];
};

extern "C" void func_00451AB0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void RaceCarModel__virtual_21(Obj *arg0, s32 arg1, s32 arg2) {
    func_00451AB0(arg0->car_model, arg0->unk0, 1, arg1, arg2);
}
