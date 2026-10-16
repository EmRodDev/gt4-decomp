/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
extern "C" int func_005ADCC0(int);
struct Sema { int id; char pad[8]; };
struct Spr { char pad[0x74]; Sema sema[3]; };
extern "C" int func_004A0F38(int n) {
    Spr *p = (Spr *)spr_base();
    return func_005ADCC0(p->sema[n].id);
}
