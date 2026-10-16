/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct State { char pad[0xa4]; int handles[3]; };
extern "C" void func_004A0D00(int,int) throw();
extern "C" int func_005AD9B0(int, void *,int);
extern "C" int func_005AE8B8(void *);
extern char D_004AB6D8[];
extern "C" int func_004A0D98() {
    State *s = (State *)((char *)spr_base() + 0x50);
    func_004A0D00(0,0x40);
    func_004A0D00(1,0xc0);
    func_004A0D00(2,0x80);
    *(unsigned int *)0x1000e010 &= 0x70007;
    *(unsigned int *)0x1000e020 &= 0x7ff8fff8;
    *(unsigned int *)0x1000e000 = 1;
    __asm__ volatile("sync");
    s->handles[0] = func_005AD9B0(0,D_004AB6D8,0);
    s->handles[1] = func_005AD9B0(1,D_004AB6D8,0);
    s->handles[2] = func_005AD9B0(2,D_004AB6D8,0);
    func_005AE8B8((void *)0);
    func_005AE8B8((void *)1);
    return func_005AE8B8((void *)2);
}
