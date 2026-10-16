/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned int u32;
struct Spr { char p0[0x1F8]; u32 *cur; u32 end; int mode; u32 p204; u32 *link; char p20C[0xB6]; unsigned char busy; };
extern "C" void func_0049FE28() throw();
extern "C" void func_005ADF20(int);
extern "C" void func_004A1C98() {
    Spr *s = (Spr *)spr_base();
    func_0049FE28();
    u32 *p = s->cur;
    p[0] = 0x70000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p += 4;
    *s->link = (u32)p & 0x0FFFFFFF;
    p[0] = 0x70000000;
    p += 4;
    s->cur = p;
    s->busy = 0;
    if (s->mode == 0) {
        __asm__ volatile("sync");
        return func_005ADF20(0);
    }
}
