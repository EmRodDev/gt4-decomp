struct RaceCarModelLayout {
    char pad0[0x18];
    char car_model[0x5C8];
};

extern "C" void func_00451238(void *arg0);

extern "C" void RaceCarModel__virtual_38(RaceCarModelLayout *arg0) {
    func_00451238(arg0->car_model);
}
