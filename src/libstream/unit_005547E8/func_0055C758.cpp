/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned long u64;

// Partial VoiceSystem view: the next-ID counter and list head are recovered;
// the intervening class layout remains unknown.
struct VoiceSystemListView;
struct VoiceListEntry {
    u64 selectionMask;
    VoiceSystemListView *system;
    VoiceListEntry *next;
    char unknown10[0x20];
    s32 field30;
    char unknown34[0x14];
    s32 voiceId;
};
struct VoiceSystemListView {
    char unknown00[0xA0];
    s32 nextVoiceId;
    char unknownA4[0x2A04];
    VoiceListEntry *voiceListHead;
};
struct InterruptSection { s32 depth; s32 previouslyEnabled; };
extern InterruptSection D_00655340;
extern "C" void func_00576100(InterruptSection *section);
extern "C" void func_00576140(InterruptSection *section);
extern "C" s32 func_0055C520(VoiceSystemListView *system);
extern "C" VoiceListEntry *func_0055C758(VoiceSystemListView *system, u64 mask) {
    func_00576100(&D_00655340);
    VoiceListEntry *previous = 0;
    VoiceListEntry *entry = system->voiceListHead;
    while (entry != 0 && !(entry->selectionMask & mask)) {
        previous = entry;
        entry = entry->next;
    }
    if (entry != 0) {
        VoiceListEntry *next = entry->next;
        if (previous == 0)
            system->voiceListHead = next;
        else
            previous->next = next;
        entry->next = 0;
        entry->field30 = 6;
        entry->voiceId = func_0055C520(entry->system);
    }
    func_00576140(&D_00655340);
    return entry;
}
