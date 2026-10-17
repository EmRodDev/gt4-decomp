#include "ee_kernel.h"
struct State { unsigned int flags; int pad[2]; int sema; };
extern "C" int func_005AEB68(int);
extern "C" void func_005AE940(void *);
extern "C" int func_0054D960(int cause, State *s) {
    s->flags &= ~4;
    func_005AEB68(s->sema);
    func_005AE940((void *)8);
    ExitHandler();
    return 0;
}
