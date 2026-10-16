/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Work { char pad[0x110]; int sema, owner, depth; };
extern "C" int func_005ADB90(void);
extern "C" int func_005ADCE0(int);
static inline void lock(Work *w) {
    int id = func_005ADB90();
    if (w->owner != id) {
        func_005ADCE0(w->sema);
        w->owner = id;
    }
    w->depth = w->depth + 1;
}
extern "C" void func_004A0690(void) { lock((Work *)spr_base()); }
