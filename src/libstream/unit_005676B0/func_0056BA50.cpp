typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned long u64;
extern "C" void func_0056BA50(u128 *a, u128 *b, u64 *out, int n) {
    u128 hi, lo, round;
    __asm__ volatile("pceqw %0, $0, $0" : "=r"(hi));
    __asm__ volatile("psrlw %0, %1, 17" : "=r"(hi) : "r"(hi));
    __asm__ volatile("psubsw %0, $0, %1" : "=r"(lo) : "r"(hi));
    __asm__ volatile("pceqw %0, $0, $0" : "=r"(round));
    __asm__ volatile("psrlw %0, %1, 20" : "=r"(round) : "r"(round));
    if(n<0) n+=3;
    n>>=2;
    do {
        n--;
        u128 x, y;
        __asm__ volatile("lq %0, 0(%1)" : "=r"(x) : "r"(a));
        a++;
        __asm__ volatile("lq %0, 0(%1)" : "=r"(y) : "r"(b));
        b++;
        __asm__ volatile("psubsw %0, %1, %2" : "=r"(x) : "r"(x), "r"(y));
        __asm__ volatile("paddsw %0, %1, %2" : "=r"(x) : "r"(x), "r"(round));
        __asm__ volatile("psraw %0, %1, 13" : "=r"(x) : "r"(x));
        __asm__ volatile("pmaxw %0, %1, %2" : "=r"(x) : "r"(x), "r"(lo));
        __asm__ volatile("pminw %0, %1, %2" : "=r"(x) : "r"(x), "r"(hi));
        u64 r;
        __asm__ volatile("ppach %0, %1, %1" : "=r"(r) : "r"(x));
        *out++=r;
    } while(n!=0);
}
