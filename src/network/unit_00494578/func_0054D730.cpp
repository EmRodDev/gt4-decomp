/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct State { int pad[4]; int a,b,c; };
extern State D_0086F610;
extern "C" int func_005AE780(void *);
extern "C" int func_005AD9A0(int,int);
extern "C" int func_005AD9D0(int,int);
extern "C" void *func_005A48D8(void *,int,unsigned int);
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
extern "C" void *func_0054D730(void) {
    State *s = &D_0086F610;
    func_005AE780((void *)8);
    volatile u32 *stat = (volatile u32 *)0x1000E010;
    u32 old = *stat;
    *stat = 8;
    (void)*stat; SYNC();
    if (old & 0x80000) {
        REG(0x1000E010) = 0x80000;
        (void)REG(0x1000E010); SYNC();
    }
    u32 old2 = REG(0x1000E010);
    REG(0x1000E010) = 16;
    (void)REG(0x1000E010); SYNC();
    if (old2 & 0x100000) {
        REG(0x1000E010) = 0x100000;
        (void)REG(0x1000E010); SYNC();
    }
    func_005AD9A0(8,s->a);
    func_005AD9D0(3,s->b);
    REG(0x1000E020) &= ~8;
    SYNC();
    return func_005A48D8(s,0,28);
}
