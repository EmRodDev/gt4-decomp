#include "ee_kernel.h"
struct Obj;
typedef unsigned long u_long;
extern "C" void func_00503630(Obj *) throw();
extern "C" void func_005036D8(Obj *);
/* SetTimerAlarm-style: (u_long clock, handler, common), built on iAllocTimerCounter/iSetTimerHandler */
extern "C" int func_005B9068(u_long clock, void (*handler)(Obj *), Obj *common) throw();
extern "C" int func_00503688(int unused, Obj *p) {
    func_00503630(p);
    func_005B9068(0x21099C, func_005036D8, p);
    ExitHandler();
    return 0;
}
