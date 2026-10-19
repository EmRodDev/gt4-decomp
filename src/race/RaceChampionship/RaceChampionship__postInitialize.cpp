typedef int s32;

struct RaceChampionshipLayout {
    char pad[0x6C];
    s32 unk6C;
    char pad70[0x22708 - 0x70];
    char car_icon_maker[0x100];
};

extern "C" void RaceBase__postInitialize();
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceChampionship__postInitialize(RaceChampionshipLayout *arg0) {
    RaceChampionshipLayout *s0 = arg0;
    RaceBase__postInitialize();
    CarIconMaker__structor_1(s0->car_icon_maker, s0->unk6C);
}
