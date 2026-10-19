typedef int s32;

struct RaceBaseLayout {
    char pad0[0xCE4];
    char unkCE4[0x34];
};

extern "C" s32 RaceBase__getSignal(void *arg0);
extern "C" void func_00574F58(void *arg0);

extern "C" s32 RaceBase__signalHandler(RaceBaseLayout *arg0) {
    func_00574F58(arg0->unkCE4);
    return RaceBase__getSignal(arg0);
}
