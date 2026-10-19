typedef int s32;

struct RaceMessageDisplayLayout {
    char pad0[0x24];
    s32 unk24;
    char pad28[0x70 - 0x28];
    char font_obj[0x20];
};

extern "C" void func_005A609C(void *arg0);

extern "C" void RaceMessageDisplay__setFont(RaceMessageDisplayLayout *arg0, s32 arg1, s32 arg2) {
    arg0->unk24 = arg2;
    func_005A609C(arg0->font_obj);
}
