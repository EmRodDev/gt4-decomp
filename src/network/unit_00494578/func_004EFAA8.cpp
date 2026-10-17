/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Device {
    char pad[0x38];
    char event[0x30];
    char lock[0x30];
    void *waiters;
    char pad9C[0x214 - 0x9C];
    int running;
};

extern int D_006454DC;
extern "C" int func_004EFA68(void) throw();
extern "C" void func_00574EE8(void *);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00576A48(void *);

extern "C" void func_004EFAA8(Device *dev) {
    unsigned int status;

    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1)) {
        if (dev->running && D_006454DC == 0)
            return func_00576A48(dev->event);
    } else if (func_004EFA68()) {
        func_00576788(dev->lock);
        if (dev->running)
            func_00574EE8(dev->event);
        func_005767C0(dev->lock);
        D_006454DC = 0;
    }
}
