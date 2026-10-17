/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "ee_kernel.h"
typedef unsigned int u32;
extern u32 D_0086F600;
int func_005AEB68(int);
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
int func_0054CFA8(int unused, int arg) {
    u32 *remaining = &D_0086F600;
    u32 n = *remaining;
    if (n != 0) {
        u32 count = n <= 0xfff0u ? n : 0xfff0u;
        volatile u32 *size;
        volatile u32 *channel;
        *remaining = n - count;
        size = (volatile u32 *)0x1000b020;
        *size = count;
        SYNC();
        channel = (volatile u32 *)0x1000b000;
        *channel |= 0x100;
        SYNC();
    } else {
        volatile u32 *status = (volatile u32 *)0x1000e010;
        u32 old = *status;
        *status = 8;
        (void)*status;
        SYNC();
        if (old & 0x80000) {
            REG(0x1000e010) = 0x80000;
            (void)REG(0x1000e010);
            SYNC();
        }
        func_005AEB68(arg);
    }
    ExitHandler();
    return 0;
}
