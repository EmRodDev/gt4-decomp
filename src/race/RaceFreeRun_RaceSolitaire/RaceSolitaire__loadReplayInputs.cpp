/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct RaceSolitaireLayout {
    char pad[0x64];
    VEntry *vtbl;
    char pad68[0xe560 - 0x68];
    char record_manager[0x20];
    char padE580[0xe83c - 0xe580];
    s32 flag;
};

extern "C" char *AutomobileControlRecord__Manager__load(void *, char *, int);

extern "C" void RaceSolitaire__loadReplayInputs(RaceSolitaireLayout *self, char *data) {
    AutomobileControlRecord__Manager__load(self->record_manager, data + 0x1aa4, 1);
    VEntry *v = self->vtbl;
    self->flag = 1;
    VEntry *e = &v[67];
    e->fn((char *)self + e->delta);
}
