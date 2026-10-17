/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VoiceSlot {
    void *voice;
    char unknown04[0x14];
};
struct PlaybackPoolEntry {
    VoiceSlot voices[2];
    char unknown30[0x24];
    s32 state;
};
extern char D_00655340[];
extern "C" void func_00576100(void *section);
extern "C" void func_00576140(void *section);
extern "C" void func_0055D688(void *voice, s32 flags);
extern "C" PlaybackPoolEntry *func_00559548(PlaybackPoolEntry *self) {
    func_00576100(D_00655340);
    for (s32 i = 0; i < 2; ++i) {
        if (self->voices[i].voice != 0) {
            func_0055D688(self->voices[i].voice, 0);
            self->voices[i].voice = 0;
        }
    }
    func_00576140(D_00655340);
    return self;
}
