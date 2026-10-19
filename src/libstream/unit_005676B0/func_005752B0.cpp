#include "types.h"

struct Obj {
    char pad0[0x3C];
    u32 w3C;
    char pad40[0xC];
    s32 *tbl;
};

extern "C" void func_00576788(Obj *);
extern "C" void func_005767C0(Obj *);
extern "C" void func_005755C0(Obj *);
extern "C" s32 func_00575610(Obj *);
extern "C" s32 func_00575620(Obj *, s32);
extern "C" s32 *func_00575688(Obj *);
extern "C" void func_00575720(Obj *, s32 *);
extern "C" s32 func_00575770(Obj *, s32);

extern "C" s32 func_005752B0(Obj *o, s32 sz) {
    func_00576788(o);
    sz = (sz + 3) & ~3;
    u32 need = sz + 0xC;
    if (o->w3C < need) {
        func_005767C0(o);
        return 0;
    }
    o->w3C = o->w3C - need;
    if (func_00575610(o) < 8) {
        func_005767C0(o);
        func_005755C0(o);
        func_00576788(o);
        if (func_00575610(o) < 8) {
            o->w3C = o->w3C + need;
            func_005767C0(o);
            return 0;
        }
    }
    s32 *e = func_00575688(o);
    s32 key = *e;
    s32 r = func_00575770(o, sz);
    if (r == 0) {
        func_005767C0(o);
        func_005755C0(o);
        func_00576788(o);
        e = o->tbl + func_00575620(o, key) * 2;
        r = func_00575770(o, sz);
        if (r == 0) {
            func_00575720(o, e);
            o->w3C = o->w3C + need;
            func_005767C0(o);
            return 0;
        }
    }
    e[1] = r;
    func_005767C0(o);
    return key;
}
