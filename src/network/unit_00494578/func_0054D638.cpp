typedef unsigned int u32;
struct State { int a, b, arg, c, dma, intc; };
extern State D_0086F610;
extern "C" int func_005AE780(void *);
extern "C" int func_0054D960(int, void *, void *);
extern "C" int func_0054D9A0(int, void *, void *);
typedef int (*Handler)(int, void *, void *);
extern "C" int func_005AD990(int, Handler, int, State *);
extern "C" int func_005AD9C0(int, Handler, int, State *);
extern "C" int func_005627D0(u32, u32);
#define DSTAT (*(volatile u32 *)0x1000E010)
extern "C" void func_0054D638(int arg) {
    char frame_[32];
    State *p = &D_0086F610;
    p->arg = arg;
    func_005AE780((void *)8);
    volatile u32 *stat = (volatile u32 *)0x1000E010;
    struct Status { u32 word; } old = { *stat };
    *stat = 8;
    (void)DSTAT;
    __asm__ volatile("sync");
    if (old.word & 0x80000) {
        DSTAT = 0x80000;
        (void)DSTAT;
    __asm__ volatile("sync");
    }
    Status old2 = { DSTAT };
    DSTAT = 16;
    (void)DSTAT;
    __asm__ volatile("sync");
    if (old2.word & 0x100000) {
        DSTAT = 0x100000;
        (void)DSTAT;
    __asm__ volatile("sync");
    }
    p->dma = func_005AD990(8, func_0054D960, 0, p);
    p->intc = func_005AD9C0(3, func_0054D9A0, 0, p);
    func_005627D0(8, 8);
}
