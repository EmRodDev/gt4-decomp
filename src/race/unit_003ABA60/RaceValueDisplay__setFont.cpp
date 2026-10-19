struct RaceValueDisplayLayout {
    char pad0[0x68];
    char font_obj[0x20];
};

extern "C" void func_005A609C(void *arg0);

extern "C" void RaceValueDisplay__setFont(RaceValueDisplayLayout *arg0) {
    func_005A609C(arg0->font_obj);
}
