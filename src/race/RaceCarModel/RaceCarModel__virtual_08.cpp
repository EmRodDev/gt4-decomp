struct RaceCarModelLayout {
    char pad0[0x18];
    char car_model[0x5C8];
};

extern "C" void func_004519A0(void *arg0);

extern "C" void RaceCarModel__virtual_08(RaceCarModelLayout *arg0) {
    func_004519A0(arg0->car_model);
}
