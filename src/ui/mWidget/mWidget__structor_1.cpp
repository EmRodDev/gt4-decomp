#include "gt4/mWidget.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mWidget__vtable;
extern "C" void func_00255058(void *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_0024B248(void *, s32);
extern "C" void func_005DD9C0(void *);
extern "C" void *func_005DEA88(void);
extern "C" void func_0026A118(void *, s32);
extern "C" void func_003286B8(void *);
extern "C" void hModule__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)s->p - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

struct Member60 {
    char pad0[4];
    void *p0;
    char pad8[0x24];
};

static inline void member_0(Member60 *m) {
    func_0024B248(&m->pad8[0], 0x2);
    func_005DD9C0(m);
    void *p0 = m->p0;
    void *r3 = func_005DEA88();
    func_00326798(p0, 0xc, 0x4, *(void **)(r3));
}

struct mWidgetInternal {
    void *vptr0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x1C];
    void *unk2C;
    char pad30[0x30];
    Member60 member60;
    Str str8C;
    void *unk90;
    Str str94;
};

extern "C" void mWidget__structor_1(mWidgetInternal *arg0, s32 arg1) {
    arg0->unk4 = &mWidget__vtable;
    func_00255058(arg0->unk90);
    str_release(&arg0->str94);
    str_release(&arg0->str8C);
    member_0(&arg0->member60);
    func_0026A118(arg0->pad30, 0x2);
    if (arg0->unk2C != 0) {
        func_003286B8(arg0->unk2C);
    }
    hModule__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xa0, 0x4, "RefCounter");
    }
}
