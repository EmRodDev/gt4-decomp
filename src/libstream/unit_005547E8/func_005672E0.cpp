struct Slot { int state; int flags; };
struct Obj {
    char pad0[0x14];
    int enabled;
    char pad18[0x48];
    void *queue;
    char pad64[8];
    Slot slots[1];
};
extern "C" int func_005657E0(void *queue, int channel, int *out);
// The queue lookup supplies a slot index; disabled or failed lookups report false.
extern "C" int func_005672E0(Obj *self, int channel)
{
    int index[4];
    if (!self->enabled || func_005657E0(self->queue, channel, index)) return 0;
    return (self->slots[index[0]].flags >> 5) & 1;
}
