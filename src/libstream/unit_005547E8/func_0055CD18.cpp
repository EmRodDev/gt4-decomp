/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VoiceSystem;
extern char D_00655340[];
extern "C" void func_00576100(void *section);
extern "C" void func_00576140(void *section);
extern "C" void func_0055DDD8(VoiceSystem *, s32 bankIndex, s32 value0, s32 value1);
extern "C" void func_0055CD18(VoiceSystem *voiceSystem, s32 bankIndex, s32 value0, s32 value1) {
    func_00576100(D_00655340);
    if (bankIndex != 2) {
        func_0055DDD8(voiceSystem, bankIndex, value0, value1);
    } else {
        s32 bankIndex = 0;
        do {
            func_0055DDD8(voiceSystem, bankIndex, value0, value1);
            bankIndex++;
        } while (bankIndex < 2);
    }
    func_00576140(D_00655340);
}
