/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long u64;
struct S { char pad[0x24]; u32 data; char *tags; int a,b,c; char pad38[8]; int active; };
extern int D_0086F7C4, D_0086F7CC, D_0086F7D0;
extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
#define REG(x) (*(volatile u32 *)(x))
#define SYNC() __asm__ volatile("sync" ::: "memory")
extern "C" int func_0054FEC8(S *s) {
 s->c = 0; s->b = 0; s->a = 0;
 int i = 0;
 int count = D_0086F7D0 >> 4;
 u32 tag = count & 0xffff;
 tag |= 0x30000000;
 for (; i < D_0086F7C4; i++) {
  *(u64 *)(s->tags + i * 16) = tag | ((u64)((s->data + (i << D_0086F7CC)) & 0xfffffff) << 32);
 }
 *(u64 *)(s->tags + i * 16) = ((u64)((u32)s->tags & 0xfffffff) << 32) | 0x20000000;
 REG(0x1000b420) = 0; SYNC();
 REG(0x1000b410) = s->data & 0xfffffff; SYNC();
 REG(0x1000b430) = (u32)s->tags & 0xfffffff; SYNC();
 func_005B72A8();
 u32 saved = REG(0x1000f520);
 REG(0x1000f590) = saved | 0x10000; SYNC();
 REG(0x1000b400) = 4; SYNC();
 REG(0x1000f590) = saved; SYNC();
 func_005B72F8();
 s->active = 1;
 return 0;
}
