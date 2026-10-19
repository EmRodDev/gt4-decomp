/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct RacePS2BaseLayout {
    char pad[0x64];
    VEntry *vtbl;
};

extern "C" void RacePS2Base__idle(RacePS2BaseLayout *arg0) {
    VEntry *e = &arg0->vtbl[121];
    e->fn((char *)arg0 + e->delta);
}
