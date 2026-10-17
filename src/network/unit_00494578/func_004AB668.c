/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "ee_kernel.h"
#include "spr.h"
struct State { char pad[0x15]; volatile signed char busy; };
struct Spr { char pad[0x50]; struct State state; };
void func_004AB930(struct State *);
int func_004AB668(void) {
    struct Spr *spr;
    struct State *s;
    *(volatile long *)0x12001000 = 2;
    spr = (struct Spr *)spr_base();
    s = &spr->state;
    ++s->busy;
    if (s->busy == 2) func_004AB930(s);
    ExitHandler();
    return 1;
}
