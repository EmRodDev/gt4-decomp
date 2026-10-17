/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct AudioTransferState {
    int argumentForContextWait;
    u8 unknown04[0x3C];
    u8 payload[0x3B8];
    int dirty;
};

extern AudioTransferState D_008735C0;
extern u8 D_00873DC0[];

extern "C" void func_00578500(int argument);
extern "C" int func_005B72A8(void);
extern "C" int func_00578168(AudioTransferState *, int, int, const void *, int);

extern "C" void func_0055E6D0(const void *source) {
    // The global's first word is passed through to this helper; its role is unknown.
    func_00578500(D_008735C0.argumentForContextWait);
    int interruptsWereEnabled = func_005B72A8();
    __builtin_memcpy(D_008735C0.payload, source, 0x3B8);
    if (interruptsWereEnabled != 0) {
        __asm__ volatile("ei" ::: "memory");
    }
    D_008735C0.dirty = 1;
    func_00578168(&D_008735C0, 4, 1, D_00873DC0, 0x80);
}
