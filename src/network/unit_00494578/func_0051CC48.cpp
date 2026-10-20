#include "types.h"
struct Vt { char p[0x58]; s32 (*f58)(s32, s32); };
struct W { char p[0x1C]; s32 f1C; };
struct V { char p[0x80]; W *f80; };
extern Vt *D_0064B4B0;
extern "C" s32 func_0051BE28(void) throw();
extern "C" s32 func_0051BE60(void) throw();
extern "C" V *func_0051DD88(s32);
extern "C" s32 func_0051CC48(s32 a, s32 b) {
    s32 r = func_0051BE28();
    if (r != 0) return r;
    V *v = func_0051DD88(a);
    if (v == 0 || b == 0 || v->f80 == 0) r = 2;
    else r = D_0064B4B0->f58(v->f80->f1C, b);
    func_0051BE60();
    return r;
}
