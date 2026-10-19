typedef int s32;

struct ShiftDisplay {
    char pad[0x54];
    s32 unk54;
};

struct RaceOnboardPanelLayout {
    char pad0[0xA20];
    ShiftDisplay shift_display;
};

extern "C" void RaceOnboardPanel__setClutch(RaceOnboardPanelLayout *arg0, s32 arg1) {
    ShiftDisplay *obj = &arg0->shift_display;
    obj->unk54 = (obj->unk54 & 0xFFFFFF) | (arg1 << 24);
}
