/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct RaceSolitaireLayout {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" void RaceSolitaire__loadReplayTheathre(RaceSolitaireLayout *arg0, void *arg1) {
    VEntry *e = &arg0->vtbl[57];
    e->fn((char *)arg0 + e->delta, arg1);
}
