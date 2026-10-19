#include "types.h"
struct R { unsigned int a, b, c, d; };
struct Out { int zero; u8 d, c, b, a; };
extern char D_006CC058[];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005A5AD8(const char *, const char *, ...) throw();
extern "C" int func_00570CC8(Out *out, const char *name) {
    R r;
    if (!out || !name || (func_005A48D8(out, 0, 0x10), func_005A5AD8(name, D_006CC058, &r.a, &r.b, &r.c, &r.d) != 4))
        return -0x200;
    out->zero = 0;
    out->d = *(u8 *)&r.d;
    out->c = *(u8 *)&r.c;
    out->b = *(u8 *)&r.b;
    out->a = *(u8 *)&r.a;
    return 0;
}
