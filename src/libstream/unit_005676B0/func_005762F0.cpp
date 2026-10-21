/* Builds a temporary object on the stack with func_00576168 (flag 1), hands it plus the two arguments to func_0057DE48,
 * then tears it down with func_00576280 and func_005761B0 (flag 2) (inferred: a constructor / destructor pair around one call). */
#include "types.h"
struct Obj {
    char *vt;
    char p1[0x100];
    s32 f104;
    s32 f108;
    s32 f10C;
};
extern "C" int func_00576168(void *, s32);
extern "C" void func_005761B0(void *, s32);
extern "C" void func_00576280(void *);
extern "C" void func_0057DE48(void *, s32, s32);
extern "C" void func_005762F0(s32 forwardedA, s32 forwardedB) {
    Obj tmp;
    func_00576168(&tmp, 1);
    func_0057DE48(&tmp, forwardedA, forwardedB);
    func_00576280(&tmp);
    func_005761B0(&tmp, 2);
}
