/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "ee_kernel.h"
typedef unsigned int u32;
struct State { u32 flags; int pad[2]; int sema; };
extern "C" int func_005AEB68(int);
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
extern "C" int func_0054D9A0(int cause, State *s) {
    s->flags &= ~1;
    func_005AEB68(s->sema);
    volatile u32 *stat = (volatile u32 *)0x1000E010;
    u32 old = *stat;
    *stat = 8;
    (void)*stat; SYNC();
    if (old & 0x80000) {
        REG(0x1000E010) = 0x80000;
        (void)REG(0x1000E010); SYNC();
    }
    ExitHandler();
    return 0;
}
