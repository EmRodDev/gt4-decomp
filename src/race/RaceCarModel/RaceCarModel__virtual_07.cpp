struct RaceCarModelLayout {
    char pad0[0x18];
    char car_model[0x5C8];
};

extern "C" void func_00451998(void *arg0);

extern "C" void RaceCarModel__virtual_07(RaceCarModelLayout *arg0) {
    func_00451998(arg0->car_model);
}
