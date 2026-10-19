typedef int s32;

struct ClutchDisplay {
    char pad[0x54];
    s32 unk54;
};

struct RaceSimplePanelLayout {
    char pad0[0x124];
    ClutchDisplay clutch_display;
};

extern "C" void RaceSimplePanel__setClutch(RaceSimplePanelLayout *arg0, s32 arg1) {
    ClutchDisplay *obj = &arg0->clutch_display;
    obj->unk54 = (obj->unk54 & 0xFFFFFF) | (arg1 << 24);
}
