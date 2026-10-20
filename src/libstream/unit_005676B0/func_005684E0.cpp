#include "types.h"
extern "C" void func_0054D5C8(void);
extern "C" int func_005684E0(int mode) {
    func_0054D5C8();
    u32 temp = *(volatile u32 *)0x10002010;
    temp = (temp & 0xF8FFFFFF) | ((mode << 24) & 0x07000000);
    *(volatile u32 *)0x10002010 = temp;
    __asm__ volatile("sync");
    func_0054D5C8();
    temp = 0x34000000;
    *(volatile u32 *)0x10002000 = temp;
    __asm__ volatile("sync");
    func_0054D5C8();
    return (int)(*(volatile u64 *)0x10002000 & 0xFFFF);
}
