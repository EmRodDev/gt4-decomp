typedef int s32;

struct RaceCarModelLayout {
    char pad0[0x18];
    char car_model[0x5C8];
};

struct Result {
    char pad[0x38];
    s32 unk38;
};

extern "C" Result *func_00450FB0(void *arg0);

extern "C" s32 RaceCarModel__virtual_40(RaceCarModelLayout *arg0) {
    s32 res;
    Result *resObj;

    resObj = func_00450FB0(arg0->car_model);
    res = 0;
    if (resObj != 0) {
        res = resObj->unk38;
    }
    return res;
}
