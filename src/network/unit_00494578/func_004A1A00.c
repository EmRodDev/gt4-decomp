/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Scratch { char pad[0x1f0]; int start, length, current, end, sync, mask; };
void func_005ADF20(int);
void func_004A1A00(int start, int length) {
    struct Scratch *s = (struct Scratch *)spr_base();
    int current, limit;
    int end;
    s->start = start;
    current = 0;
    s->length = length;
    end = start + length;
    if (start) current = (start & 0x0fffffff) | s->mask;
    s->current = current;
    limit = 0;
    if (end) limit = (end & 0x0fffffff) | s->mask;
    s->end = limit;
    if (s->sync) {
        __asm__ volatile("sync");
        func_005ADF20(0);
    }
}
