#include "types.h"

struct Q {
    char pad0[8];
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    char *w1C;
    s32 w20;
    char pad24[0x10];
    s32 w34;
    s32 w38;
    s32 w3C;
    char buffer[0x2000];
};

struct O {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    char pad10[0x10];
    Q *q20;
    Q *q24;
};

extern "C" s32 func_00571630(s32 h, Q *q);
extern "C" s32 func_005716D8(s32 h, Q *q, s32 n) throw();
extern "C" s32 func_0056EFE8(s32 h, s32 *buf, s32 a, s32 b);
extern "C" s32 func_00570EC0(s32 a, s32 b, s32 c);

extern "C" s32 func_00570250(s32 h, s32 *buf, O *o, s32 flag) {
    s32 r = -0x200;
    s32 fl = 0;
    if (o == 0) return r;
    if (flag == 0) fl = o->w0 == 1;
    s32 mode = (fl == 1) ? 2 : 1;
    Q *q = o->q20;
    q->wC = mode;
    q->w1C = q->buffer;
    q->w34 = o->w0;
    q->w38 = o->w4;
    q->w10 = o->w8;
    q->w8 = o->wC;
    q->w14 = 0;
    q->w18 = 0x2000;
    if (func_00571630(h, q) != 0) return -0x1F5;
    Q *p = o->q24;
    p->wC = mode;
    p->w1C = p->buffer;
    p->w34 = o->w0;
    p->w38 = o->w4;
    p->w10 = o->w8;
    s32 n = o->wC;
    p->w18 = 0x2000;
    p->w8 = n;
    p->w14 = 0;
    if (func_005716D8(h, p, n) != 0) return -0x1F5;
    s32 res;
    if (fl == 0) {
        res = func_0056EFE8(h, buf, o->w8, flag);
        if (res == 0 || (res == -500 && o->w0 == 2)) {
            o->q24->wC = 0;
            o->q20->wC = 0;
        } else {
            o->q24->wC = 3;
            o->q20->wC = 3;
        }
        if (func_00570EC0((s32)o->q24, o->q24->w20, 0x10) != 0) return -0x1F5;
        if (func_00570EC0((s32)o->q20, o->q20->w20, 0x10) != 0) return -0x1F5;
    } else {
        res = 0;
    }
    return res;
}
