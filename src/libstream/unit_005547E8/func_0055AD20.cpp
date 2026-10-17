/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

// Partial constructor view: only accessed fields and established offsets are named.
struct AudioStreamInitializer {
    char unknown00[0x28];
    unsigned long long selectionMask;
    s32 streamContext;
    s32 state34;
    char unknown38[8];
    float timingResolution;
    s32 state44;
    s32 state48;
    s32 state4C;
    s32 state50;
    void *streamCursor54;
    void *streamCursor58;
    s32 streamId;
};

struct VoiceSystem;
extern "C" void func_0055A858(AudioStreamInitializer *self, float beatsPerMinute);
extern "C" int func_0055C588(VoiceSystem *system);
extern char SDDRV__VoiceSystem__master_[];

extern "C" void func_0055AD20(AudioStreamInitializer *self, void *streamCursor,
                                s32 streamContext, float timingResolution) {
    self->streamContext = streamContext;
    self->streamCursor58 = streamCursor;
    self->streamCursor54 = streamCursor;
    self->timingResolution = timingResolution;
    self->state34 = 0;
    self->state4C = 0;
    self->state44 = 0;
    self->state48 = 0;
    self->state50 = 0;
    self->selectionMask = 0;
    func_0055A858(self, 120.0f);
    self->streamId = func_0055C588((VoiceSystem *)SDDRV__VoiceSystem__master_);
}
