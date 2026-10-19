#include "types.h"
extern u8 D_006CB170[], D_006CB3F0[], D_006CB670[];
extern "C" unsigned func_00567B38(void *, int);
extern "C" void func_0056D920(u16 *out, int n, void *rng) {
    u16 *p = out;
    for (int i=0; i<n; i++) { *p = (i+1)<<11; p++; }
    int value = (int)func_00567B38(rng,6)*5;
    value *= 2;
    u8 *q = D_006CB170 + value;
    p = out;
    for (int i=0; i<10; i++) { value = (int)(*q << 24) >> 19; *p += value; q++; p++; }
    value = (int)func_00567B38(rng,6)*5;
    q = D_006CB3F0 + value;
    p = out;
    for (int i=0; i<5; i++) { value = (int)(*q << 24) >> 20; *p += value; q++; p++; }
    value = (int)func_00567B38(rng,6)*5;
    q = D_006CB670 + value;
    p = out+5;
    for (int i=0; i<5; i++) { value = (int)(*q << 24) >> 20; *p += value; q++; p++; }
}
