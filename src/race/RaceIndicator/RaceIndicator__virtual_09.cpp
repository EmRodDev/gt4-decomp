/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RaceIndicatorLayout {
    char pad0[0x18];
    char oscillator[0x20];
};

extern "C" void Oscillator__update(void *arg0);

extern "C" void RaceIndicator__virtual_09(RaceIndicatorLayout *arg0) {
    Oscillator__update(arg0->oscillator);
}
